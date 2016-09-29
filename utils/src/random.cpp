///
/// random.cpp
///
/// Created on: Sep 19, 2016
///     Author: alexen
///

#include <utils/random.h>
#include <ctime>
#include <cstring>
#include <cerrno>
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_int_distribution.hpp>


namespace {
namespace aux {


long nanoseconds()
{
     timespec tv;
     if( clock_gettime( CLOCK_REALTIME, &tv ) < 0 )
     {
          char errstr[ 128 ] = { 0 };
          strerror_r( errno, errstr, sizeof( errstr ) );
          BOOST_THROW_EXCEPTION( std::runtime_error( "clock_gettime failed: "
               + std::string( errstr ) ) );
     }
     return tv.tv_nsec;
}


}  // namespace aux
}


int generateRandomInteger( int min, int max )
{
     static boost::random::mt19937 generator( aux::nanoseconds() );
     boost::random::uniform_int_distribution<> dist( min, max );
     return dist( generator );
}


boost::gregorian::date generateRandomDate( const boost::gregorian::date& minDate, const boost::gregorian::date& maxDate )
{
     return minDate + boost::gregorian::days( generateRandomInteger( 0, (maxDate - minDate).days() ) );
}
