
#ifndef STRING_INCLUDED 
#define STRING_INCLUDED 1

#include <iostream> 
#include <cstring>

class string
{
   size_t len;
   char *p; 

public: 
   string( )
      : len{0},
        p{ nullptr }   // Works, see the slides. 
   { }

   string( const char* s )
      : len{ strlen(s) },
        p{ new char[ len ] }
   {
      for( size_t i = 0; i < len; ++ i )
         p[i] = s[i]; 
   }

   string( const string& s )
      : len{ s. len },
        p{ new char[ len ] }
   {
      for( size_t i = 0; i < len; ++ i )
         p[i] = s.p[i]; 
   }

   void operator = ( const string& s )
   { 
      if( len != s.len )
      {
         delete[] p; 
         len = s. len;
         p = new char[ len ];
      }

      for( size_t i = 0; i < len; ++ i )
         p[i] = s.p[i];
   }

   size_t size( ) const { return len; }

   ~string( )
   {
      delete[] p;
   }

};

std::ostream& operator << ( std::ostream& out, const string& s );

#endif


