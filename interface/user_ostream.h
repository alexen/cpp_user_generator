///
/// outstream.h
///
/// Created on: Jan 15, 2017
///     Author: alexen
///

#pragma once


class Ostream
{
public:
     virtual ~Ostream() {};

     Ostream& operator<<( const User& user )
     {
          output( *this, user );
          return *this;
     }

     void flush()
     {
          flush( *this );
     }

private:
     virtual void output( Ostream& ostream, const User& user ) = 0;
     virtual void flush( Ostream& ostream ) = 0;
};

