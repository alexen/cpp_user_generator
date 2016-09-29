///
/// random_user_generator.cpp
///
/// Created on: Sep 19, 2016
///     Author: alexen
///

#include <impl/random_user_generator.h>
#include <boost/uuid/random_generator.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/algorithm/string/case_conv.hpp>
#include <utils/random.h>
#include <utils/translit.h>


namespace {
namespace aux {


std::string getRandomOf( const std::vector< std::string >& strings )
{
     return strings.at( generateRandomInteger( 0, strings.size() - 1 ) );
}


boost::gregorian::date generateRandomBirthDate()
{
     return generateRandomDate( boost::gregorian::date( 1900, 1, 1 ), boost::gregorian::date( 2000, 1, 1 ) );
}


std::string makeLogin( const std::string& lastName, const std::string& firstName, const std::string& middleName )
{
     std::string login = transliterate( lastName );
     login += "_";
     login += transliterate( firstName )[ 0 ];
     login += transliterate( middleName )[ 0 ];
     login += "_";
     login += std::to_string( generateRandomInteger( 1000, 9999 ) );
     boost::algorithm::to_lower( login );
     return login;
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
     "Иванов", "Васильев", "Петров", "Смирнов", "Михайлов", "Фёдоров", "Соколов",
     "Яковлев", "Попов", "Андреев", "Алексеев", "Александров", "Лебедев", "Григорьев",
     "Степанов", "Семёнов", "Павлов", "Богданов", "Николаев", "Дмитриев"
};

const std::vector< std::string > RandomMaleGenerator::names_ = {
     "Александр", "Алексей", "Андрей", "Вадим", "Владимир", "Владислав", "Глеб",
     "Денис", "Дмитрий", "Евгений", "Егор", "Иван", "Игорь", "Илья", "Кирилл",
     "Константин", "Максим", "Матвей", "Михаил", "Никита", "Олег", "Павел", "Роман",
     "Сергей", "Станислав"
};

const std::vector< std::string > RandomMaleGenerator::patronymics_ = {
     "Александрович", "Алексеевич", "Андреевич", "Владимирович", "Владиславович",
     "Глебович", "Денисович", "Дмитриевич", "Евгеньевич", "Егорович", "Иванович",
     "Игоревич", "Ильич", "Кириллович", "Константинович", "Максимович", "Матвеевич",
     "Михаилович", "Никитич", "Олегович", "Павлович", "Романович", "Сергеевич",
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
          aux::generateRandomBirthDate(),
          User::Gender::Male
     );
}


const std::vector< std::string > RandomFemaleGenerator::surnames_ = {
     "Егорова", "Волкова", "Кузнецова", "Никитина", "Тимофеева", "Орлова", "Афанасьева",
     "Филиппова", "Сергеева", "Захарова", "Матвеева", "Виноградова", "Кузьмина", "Максимова",
     "Козлова", "Ильина", "Герасимова", "Маркова", "Новикова"
};

const std::vector< std::string > RandomFemaleGenerator::names_ = {
     "Алина", "Альбина", "Анастасия", "Ангелина", "Анжелика", "Анна", "Арина", "Валентина",
     "Варвара", "Галина", "Дарья", "Диана", "Екатерина", "Елена", "Ирина", "Кира", "Людмила",
     "Маргарита", "Марина", "Мария", "Нина", "Светлана", "Софья", "Тамара", "Яна"
};

const std::vector< std::string > RandomFemaleGenerator::patronymics_ = {
     "Александровна", "Алексеевна", "Андреевна", "Владимировна", "Владиславовна", "Глебовна",
     "Денисовна", "Дмитриевна", "Евгеньевна", "Егоровна", "Ивановна", "Игоревна", "Ильинична",
     "Кирилловна", "Константиновна", "Максимовна", "Матвеевна", "Михайловна", "Никитична",
     "Олеговна", "Павловна", "Романовна", "Сергеевна", "Станиславовна", "Тимофеевна"
};


User RandomFemaleGenerator::generate() const
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
          aux::generateRandomBirthDate(),
          User::Gender::Female
     );
}


User RandomUserGenerator::generate() const
{
     static const RandomMaleGenerator maleGenerator;
     static const RandomFemaleGenerator femaleGenerator;
     static const std::vector< const IUserGenerator* > generators {
          &maleGenerator,
          &femaleGenerator
     };
     return ( *generators[ generateRandomInteger( 0, generators.size() - 1 ) ] )();
}
