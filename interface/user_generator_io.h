///
/// user_generator_io.h
///
/// Created on: Sep 19, 2016
///     Author: alexen
///

#pragma once

#include <interface/user_generator.h>
#include <ostream>
#include <boost/assert.hpp>
#include <boost/date_time/gregorian/gregorian_io.hpp>


inline std::ostream& operator<<( std::ostream& os, User::Gender gender )
{
     switch( gender )
     {
          case User::Gender::Male:
               os << "male";
               break;
          case User::Gender::Female:
               os << "female";
               break;
          default:
               BOOST_ASSERT_MSG( false, "unexpected gender type" );
     }
     return os;
}


inline std::ostream& operator<<( std::ostream& os, const User& user )
{
     os << user.lastName << " " << user.firstName << " " << user.middleName
          << " ["
          << user.gender
          << ", " << user.birthDate
          << "]"
          << " (" << user.login << ":" << user.password << ")";
     return os;
}
