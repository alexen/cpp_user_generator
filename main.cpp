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
#include <utils/translit.h>


int main( int argc, char **argv )
{
     try
     {
          const std::string kdePanagram =
               "Широкая электрификация южных губерний даст мощный толчок подъёму сельского хозяйства";
          const std::string expectedTranslit =
               "SHirokaya elektrifikaciya yuzhnykh gubernij dast moshhnyj tolchok podyomu selskogo khozyajstva";

          std::cout << transliterate( kdePanagram ) << "\n";

//          RandomMaleGenerator generator;
//          for( int i = 0; i < 10; ++i )
//               std::cout << generator.generate() << "\n";
//          std::cout << "Done.\n";
     }
     catch( const std::exception& e )
     {
          std::cerr << "exception: " << boost::diagnostic_information( e ) << "\n";
          return 1;
     }

     return 0;
}
