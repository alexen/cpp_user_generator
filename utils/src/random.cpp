///
/// random.cpp
///
/// Created on: Sep 19, 2016
///     Author: alexen
///

#include <utils/random.h>
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_int_distribution.hpp>

int generateRandomInteger( int min, int max )
{
     static boost::random::mt19937 generator;
     boost::random::uniform_int_distribution<> dist( min, max );
     return dist( generator );
}


boost::gregorian::date generateRandomDate( const boost::gregorian::date& minDate, const boost::gregorian::date& maxDate )
{
     return minDate + boost::gregorian::days( generateRandomInteger( 0, (maxDate - minDate).days() ) );
}
