///
/// random.h
///
/// Created on: Sep 19, 2016
///     Author: alexen
///

#pragma once

#include <boost/date_time/gregorian/gregorian_types.hpp>

int generateRandomInteger( int min, int max );

boost::gregorian::date generateRandomDate( const boost::gregorian::date& minDate, const boost::gregorian::date& maxDate );
