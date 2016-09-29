///
/// main.cpp
///
/// Created on: Sep 19, 2016
///     Author: alexen
///

#include <iostream>
#include <atomic>
#include <boost/thread.hpp>
#include <boost/program_options.hpp>
#include <boost/exception/diagnostic_information.hpp>
#include <impl/random_user_generator.h>
#include <interface/user_generator_io.h>


void personGenerator( const IUserGenerator& generator, std::atomic< int >& personsLeft )
{
     while( personsLeft > 0 )
     {
          std::cout << generator() << "\n";
          --personsLeft;
     }
}


int main( int argc, char **argv )
{
     try
     {
          namespace po = boost::program_options;
          po::options_description descr(
               "This program generates user accounts containing full name (last, first and middle names), "
               "birth date, gender, login and plaintext password. Generator supports multithreading "
               "generation, so you can choose number of generating threads."
               );

          int nPersons = 500;
          int nThreads = 1;

          descr.add_options()
               ( "help,h", "Produce this help" )
               ( "persons-number,n", po::value< int >( &nPersons )->default_value( nPersons ),
                    "Number of persons to generate" )
               ( "workers,w", po::value< int >( &nThreads )->default_value( nThreads ),
                    "Number of worker threads" )
               ( "males-only,m", "Generate males only" )
               ( "females-only,f", "Generate females only" );

          po::variables_map vm;
          po::store( po::parse_command_line( argc, argv, descr ), vm );
          po::notify( vm );

          if( vm.count( "help" ) )
          {
               std::cout << descr;
               return 0;
          }

          const bool malesOnly = vm.count( "males-only" );
          const bool femalesOnly = vm.count( "females-only" );

          std::atomic< int > personsLeft( nPersons );

          std::unique_ptr< IUserGenerator > generator;

          if( malesOnly && !femalesOnly )
          {
               generator.reset( new RandomMaleGenerator() );
          }
          else if( !malesOnly && femalesOnly )
          {
               generator.reset( new RandomFemaleGenerator() );
          }
          else
          {
               generator.reset( new RandomUserGenerator() );
          }

          boost::thread_group tg;
          for( auto i = 0; i < nThreads; ++i )
          {
               tg.create_thread( boost::bind( personGenerator, boost::cref( *generator ), boost::ref( personsLeft ) ) );
          }
          tg.join_all();

          std::cout << "Done.\n";
     }
     catch( const std::exception& e )
     {
          std::cerr << "exception: " << boost::diagnostic_information( e ) << "\n";
          return 1;
     }

     return 0;
}
