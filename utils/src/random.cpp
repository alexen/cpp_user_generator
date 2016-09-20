///
/// random.cpp
///
/// Created on: Sep 19, 2016
///     Author: alexen
///

#include <utils/random.h>
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_int_distribution.hpp>

thread_local boost::random::mt19937 generator;

int generateRandomInteger( int min, int max )
{
     boost::random::uniform_int_distribution<> dist( min, max );
     return dist( generator );
}


boost::gregorian::date generateRandomDate( const boost::gregorian::date& minDate, const boost::gregorian::date& maxDate )
{
     return minDate + boost::gregorian::days( generateRandomInteger( 0, (maxDate - minDate).days() ) );
}
