///
/// test_random_user_generator.cpp
///
/// Created on: Sep 19, 2016
///     Author: alexen
///

#include <interface/user_generator_io.h>
#include <boost/date_time/gregorian/formatters.hpp>
#include <impl/random_user_generator.h>
#include <sstream>
#include <gtest/gtest.h>


namespace {
namespace aux {


std::string oneline( const User& user )
{
     std::ostringstream ostr;
     ostr << user.lastName << ":"
          << user.firstName << ":"
          << user.middleName
          << user.login << ":"
          << user.password << ":"
          << user.gender << ":"
          << boost::gregorian::to_iso_string( user.birthDate );
     return ostr.str();
}


bool isMale( const User& user )
{
     return user.gender == User::Gender::Male;
}


bool isFemale( const User& user )
{
     return user.gender == User::Gender::Female;
}


}  // namespace aux
}


TEST( UserGenerator, GenerateRandomMales )
{
     const auto nPersons = 1000u;

     RandomMaleGenerator generator;

     auto nMales = 0u;
     std::set< std::string > uniquePersons;
     for( auto i = 0u; i < nPersons; ++i )
     {
          const auto& person = generator();
          nMales += aux::isMale( person );
          uniquePersons.insert( aux::oneline( person ) );
     }
     ASSERT_EQ( nPersons, uniquePersons.size() );
     ASSERT_EQ( nPersons, nMales );
}


TEST( UserGenerator, GenerateRandomFemales )
{
     const auto nPersons = 1000u;

     RandomFemaleGenerator generator;

     auto nFemales = 0u;
     std::set< std::string > uniquePersons;
     for( auto i = 0u; i < nPersons; ++i )
     {
          const auto& person = generator();
          nFemales += aux::isFemale( person );
          uniquePersons.insert( aux::oneline( person ) );
     }
     ASSERT_EQ( nPersons, uniquePersons.size() );
     ASSERT_EQ( nPersons, nFemales );
}


TEST( UserGenerator, GenerateRandomUsers )
{
     const auto nPersons = 1000u;

     RandomUserGenerator generator;

     auto nMales = 0u;
     auto nFemales = 0u;
     std::set< std::string > uniquePersons;
     for( auto i = 0u; i < nPersons; ++i )
     {
          const auto& person = generator();
          nMales += aux::isMale( person );
          nFemales += aux::isFemale( person );
          uniquePersons.insert( aux::oneline( person ) );
     }
     ASSERT_EQ( nPersons, uniquePersons.size() );
     ASSERT_LT( nMales, nPersons );
     ASSERT_LT( nFemales, nPersons );
     ASSERT_EQ( nPersons, nMales + nFemales );
}
