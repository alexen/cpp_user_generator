///
/// random_test.cpp
///
/// Created on: Sep 19, 2016
///     Author: alexen
///

#include <gtest/gtest.h>
#include <utils/random.h>

TEST( Random, GenerateIntegerInRange )
{
     const int minLimit = -10;
     const int maxLimit = 20;

     bool equalToMinLimit = false;
     bool equalToMaxLimit = false;
     bool inRange = false;

     for( auto i = 0; i < 100000; ++i )
     {
          const auto genInt = generateRandomInteger( minLimit, maxLimit );

          ASSERT_TRUE( minLimit <= genInt && genInt <= maxLimit );

          if( !equalToMinLimit )
          {
               equalToMinLimit = (genInt == minLimit);
          }
          if( !equalToMaxLimit )
          {
               equalToMaxLimit = (genInt == maxLimit);
          }
          if( !inRange )
          {
               inRange = (minLimit < genInt && genInt < maxLimit);
          }
     }

     EXPECT_TRUE( equalToMinLimit );
     EXPECT_TRUE( equalToMaxLimit );
     ASSERT_TRUE( inRange );
}


TEST( Random, GenerateDatesInRange )
{
     const boost::gregorian::date minDate( 1937, 3, 24 );
     const boost::gregorian::date maxDate( 1943, 11, 8 );

     bool minDateGenerated = false;
     bool maxDateGenerated = false;
     bool dateInRangeGenerated = false;

     for( auto i = 0; i < 100000; ++i )
     {
          const auto genDate = generateRandomDate( minDate, maxDate );

          ASSERT_TRUE( minDate <= genDate && genDate <= maxDate );

          if( !minDateGenerated )
          {
               minDateGenerated = (genDate == minDate);
          }
          if( !maxDateGenerated )
          {
               maxDateGenerated = (genDate == maxDate);
          }
          if( !dateInRangeGenerated )
          {
               dateInRangeGenerated = (minDate < genDate && genDate < maxDate);
          }
     }

     EXPECT_TRUE( minDateGenerated );
     EXPECT_TRUE( maxDateGenerated );
     ASSERT_TRUE( dateInRangeGenerated );
}
