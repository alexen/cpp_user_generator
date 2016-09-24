///
/// translit_test.cpp
///
/// Created on: Sep 19, 2016
///     Author: alexen
///

#include <gtest/gtest.h>
#include <utils/translit.h>

TEST( DISABLED_Translit, RuToEn )
{
     const std::string kdePanagram =
          "Широкая электрификация южных губерний даст мощный толчок подъёму сельского хозяйства";
     const std::string expectedTranslit =
          "SHirokaya elektrifikaciya yuzhnykh gubernij dast moshhnyj tolchok podyomu selskogo khozyajstva";

     ASSERT_EQ( expectedTranslit, transliterate( kdePanagram ) );
}
