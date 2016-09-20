///
/// random_test.cpp
///
/// Created on: Sep 19, 2016
///     Author: alexen
///

#include <gtest/gtest.h>
#include <iostream>
#include <utils/random.h>

TEST( Random, GenerateIntegerInRange )
{
     const int minLimit = -10;
     const int maxLimit = 20;

     bool equalToMinLimit = false;
     bool equalToMaxLimit = false;
     bool inRange = false;

     for( auto i = 0; i < 500000; ++i )
     {
          const auto genInt = generateRandomInteger( minLimit, maxLimit );

          ASSERT_TRUE( minLimit <= genInt && genInt <= maxLimit );

          if( !equalToMinLimit && genInt == minLimit )
          {
               equalToMinLimit = true;
          }
          else if( !equalToMaxLimit && genInt == maxLimit )
          {
               equalToMaxLimit = true;
          }
          else if( !inRange && (minLimit < genInt && genInt < maxLimit) )
          {
               inRange = true;
          }
     }

     ASSERT_TRUE( equalToMinLimit );
     ASSERT_TRUE( equalToMaxLimit );
     ASSERT_TRUE( inRange );
}


TEST( Random, GenerateDatesInRange )
{
     const boost::gregorian::date minDate( 1912, 3, 24 );
     const boost::gregorian::date maxDate( 2037, 11, 8 );

     bool minDateGenerated = false;
     bool maxDateGenerated = false;
     bool dateInRangeGenerated = false;

     for( auto i = 0; i < 500000; ++i )
     {
          const auto genDate = generateRandomDate( minDate, maxDate );

          ASSERT_TRUE( minDate <= genDate && genDate <= maxDate );

          if( !minDateGenerated && genDate == minDate )
          {
               minDateGenerated = true;
          }
          else if( !maxDateGenerated && genDate == maxDate )
          {
               maxDateGenerated = true;
          }
          else if( !dateInRangeGenerated && (minDate < genDate && genDate < maxDate) )
          {
               dateInRangeGenerated = true;
          }
     }

     ASSERT_TRUE( minDateGenerated );
     ASSERT_TRUE( maxDateGenerated );
     ASSERT_TRUE( dateInRangeGenerated );
}
