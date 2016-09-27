///
/// translit.cpp
///
/// Created on: Sep 19, 2016
///     Author: alexen
///

#include <utils/translit.h>
#include <unicode/translit.h>
#include <unicode/unistr.h>

#include <memory>


namespace {
namespace inner {


UnicodeString unaccentRules(
     "\\u02BA > ;"
     "\\u02B9 > ;"
     "\\u00EB > e;"
);


}  // namespace inner
} // namespace


std::string transliterate( const std::string& ruText )
{
     UErrorCode ec = U_ZERO_ERROR;
     UParseError pError;

     std::unique_ptr< Transliterator > transliterator(
          Transliterator::createInstance( "Russian-Latin/BGN", UTRANS_FORWARD, ec ) );

     std::unique_ptr< Transliterator > unaccent(
          Transliterator::createFromRules(
               "RBTUnaccent",
               inner::unaccentRules,
               UTRANS_FORWARD,
               pError,
               ec ) );

     UnicodeString ustr = ruText.c_str();
     transliterator->transliterate( ustr );
     unaccent->transliterate( ustr );

     std::string result;
     ustr.toUTF8String( result );

     return result;
}
