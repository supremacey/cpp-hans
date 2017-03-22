
#include "string.h"

#if 0
// Remove the #if, when you have finished operator[]:

std::ostream& operator << ( std::ostream& out, const string& s )
{
   for( size_t i = 0; i < s.size( ); ++ i )
      out << s[i];
   return out; 
}

#endif


