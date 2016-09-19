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
