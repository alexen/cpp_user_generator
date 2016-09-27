///
/// translit_test.cpp
///
/// Created on: Sep 19, 2016
///     Author: alexen
///

#include <gtest/gtest.h>
#include <utils/translit.h>

TEST( Translit, RuToEn )
{
     const std::vector< std::pair< std::string, std::string > > stringPairs {
          {
               "Съешь же ещё этих мягких французских булок да выпей чаю.",
               "Syesh zhe yeshche etikh myagkikh frantsuzskikh bulok da vypey chayu."
          },
          {
               "Широкая электрификация южных губерний даст мощный толчок подъёму сельского хозяйства.",
               "Shirokaya elektrifikatsiya yuzhnykh guberniy dast moshchnyy tolchok podyemu selskogo khozyaystva."
          },
          {
               "Флегматичная эта верблюдица - жуёт у подъезда засыхающий горький шиповник.",
               "Flegmatichnaya eta verblyuditsa - zhuyet u podyezda zasykhayushchiy gorkiy shipovnik."
          },
          {
               "Аэрофотосъёмка ландшафта уже выявила земли богачей и процветающих крестьян.",
               "Aerofotosyemka landshafta uzhe vyyavila zemli bogachey i protsvetayushchikh krestyan."
          },
          {
               "А ещё хорошо бы уметь всем на зависть чётко и наглядно писать буквы и цифры.",
               "A yeshche khorosho by umet vsem na zavist chetko i naglyadno pisat bukvy i tsifry."
          }
     };

     std::string result;
     for( auto&& eachPair: stringPairs )
     {
          ASSERT_NO_THROW( result = transliterate( eachPair.first ) );
          ASSERT_EQ( eachPair.second, result );
     }
}
