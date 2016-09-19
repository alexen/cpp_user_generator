///
/// random_user_generator.cpp
///
/// Created on: Sep 19, 2016
///     Author: alexen
///

#include <impl/random_user_generator.h>
#include <utils/random.h>

namespace {
namespace aux {


std::string getRandomOf( const std::vector< std::string >& strings )
{
     return strings.at( generateRandomInteger( 0, strings.size() - 1 ) );
}


std::string makeLogin( const std::string& lastName, const std::string& firstName, const std::string& middleName )
{
     return "";
}


std::string generatePassword( int minLen = 10, int maxLen = 20 )
{
     static const std::string allowedChars =
          "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM0123456789";

     std::string password( generateRandomInteger( minLen, maxLen ), '\0' );
     std::generate( password.begin(), password.end(),
          []()
          {
               return allowedChars.at( generateRandomInteger( 0, allowedChars.size() - 1 ) );
          } );

     return password;
}


}  // namespace aux
}


const std::vector< std::string > RandomMaleGenerator::surnames_ = {
     "Иванов", "Васильев", "Петров", "Смирнов", "Михайлов", "Фёдоров", "Соколов", "Яковлев", "Попов", "Андреев",
     "Алексеев", "Александров", "Лебедев", "Григорьев", "Степанов", "Семёнов", "Павлов", "Богданов", "Николаев",
     "Дмитриев"
};

const std::vector< std::string > RandomMaleGenerator::names_ = {
     "Александр", "Алексей", "Андрей", "Вадим", "Владимир", "Владислав", "Глеб", "Денис", "Дмитрий", "Евгений",
     "Егор", "Иван", "Игорь", "Илья", "Кирилл", "Константин", "Максим", "Матвей", "Михаил", "Никита", "Олег",
     "Павел", "Роман", "Сергей", "Станислав"
};

const std::vector< std::string > RandomMaleGenerator::patronymics_ = {
     "Александрович", "Алексеевич", "Андреевич", "Владимирович", "Владиславович", "Глебович", "Денисович",
     "Дмитриевич", "Евгеньевич", "Егорович", "Иванович", "Игоревич", "Ильич", "Кириллович", "Константинович",
     "Максимович", "Матвеевич", "Михаилович", "Никитич", "Олегович", "Павлович", "Романович", "Сергеевич",
     "Станиславович", "Тимофеевич"
};


User RandomMaleGenerator::generate() const
{
     const auto lastName = aux::getRandomOf( surnames_ );
     const auto firstName = aux::getRandomOf( names_ );
     const auto middleName = aux::getRandomOf( patronymics_ );
     return User(
          lastName,
          firstName,
          middleName,
          aux::makeLogin( lastName, firstName, middleName ),
          aux::generatePassword(),
          boost::gregorian::date(),
          User::Gender::Male
     );
}
