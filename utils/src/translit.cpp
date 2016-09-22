///
/// translit.cpp
///
/// Created on: Sep 19, 2016
///     Author: alexen
///

#include <utils/translit.h>
#include <unicode/translit.h>
#include <unicode/unistr.h>

#include <iostream>

std::string transliterate( const std::string& ruText )
{
     UErrorCode ec = U_ZERO_ERROR;
     StringEnumeration* enumerator = Transliterator::getAvailableIDs( ec );
     while( const char* id = enumerator->next( nullptr, ec ) )
     {
          std::cout << "Transliterate with ID " << id << ":\n";
          Transliterator* transliterator = Transliterator::createInstance( id, UTRANS_FORWARD, ec );
          UnicodeString ustr = ruText.c_str();
          transliterator->transliterate( ustr );

          std::string result;
          ustr.toUTF8String( result );
          std::cout << result << "\n";
     }
     delete enumerator;
     return "";
}
