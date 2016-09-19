///
/// main.cpp
///
/// Created on: Sep 19, 2016
///     Author: alexen
///

#include <iostream>
#include <boost/exception/diagnostic_information.hpp>

#include <impl/random_user_generator.h>
#include <interface/user_generator_io.h>


int main( int argc, char **argv )
{
     try
     {
          RandomMaleGenerator generator;
          for( int i = 0; i < 10; ++i )
               std::cout << generator.generate() << "\n";
          std::cout << "Done.\n";
     }
     catch( const std::exception& e )
     {
          std::cerr << "exception: " << boost::diagnostic_information( e ) << "\n";
          return 1;
     }

     return 0;
}
