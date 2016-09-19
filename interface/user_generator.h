///
/// user_generator.h
///
/// Created on: Sep 19, 2016
///     Author: alexen
///

#pragma once

#include <string>
#include <boost/date_time/gregorian/greg_date.hpp>


struct User {
     enum class Gender {
          Male, Female
     };

     User() {}

     User(
          const std::string& lastName_,
          const std::string& firstName_,
          const std::string& middleName_,
          const std::string& login_,
          const std::string& password_,
          const boost::gregorian::date& birthDate_,
          Gender gender_
     )
          : lastName( lastName_ )
          , firstName( firstName_ )
          , middleName( middleName_ )
          , login( login_ )
          , password( password_ )
          , birthDate( birthDate_ )
          , gender( gender_ )
     {}

     const std::string lastName;
     const std::string firstName;
     const std::string middleName;
     const std::string login;
     const std::string password;
     const boost::gregorian::date birthDate;
     const Gender gender = Gender::Male;
};


class IUserGenerator {
public:
     virtual ~IUserGenerator() {}

     virtual User generate() const = 0;
};
