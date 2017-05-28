
#ifndef POWERPRODUCT_INCLUDED 
#define POWERPRODUCT_INCLUDED 1

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>


// powvar is a silly name. There doesn't seem to exist a standard name.
// A powvar is a variable to some integer power, for example x^10 
// or y^{-5}.

struct powvar
{
   std::string v;  // variable
   int n;		   // exponent

   powvar( const std::string& nv, int n = 1 )
      : v{nv}, n{n}
   { 
	   // TODO Added to normalize input
	   std::sort(v.begin(), v.end());
   }

};

std::ostream& operator << ( std::ostream &, const powvar & );

// A power product is a sequence of powvars, sorted by the variable.
// For example x^{10}.y^{-5}, z^{3}.
// They are always normalized:
// Identical variables are merged, and zero powers are removed:
// x^{2}.x^{3}.y^{3}.y^{-2}.y^{-1} ==> x^{5}.

struct powerproduct
{

   std::vector< powvar > repr;

   powerproduct( ) { }

   powerproduct( const std::string& s, int n = 1 )
      : repr( { powvar(s,n) } )
   { normalize( ); } // for a single variable without exponent   

   powerproduct( const powvar& p )
      : repr( { p } )
   { normalize( ); }  // for variable and exponent repr as powvar

   powerproduct( std::initializer_list< powvar > repr )
      : repr{ repr }
   { normalize( ); }  // with ini_list

   powerproduct( const std::vector< powvar > & repr )
      : repr{ repr }
   { normalize( ); }

   powerproduct( std::vector< powvar > && repr )
      : repr{ std::move( repr ) }
   { normalize( ); }
 

   bool isunit( ) const { return repr. size( ) == 0; }
   size_t size( ) const { return repr. size( ); }
   powvar operator [] ( size_t i ) const { return repr[i]; }
   powvar& operator [] ( size_t i ) { return repr[i]; }


   int power( ) const;
   
   static int compare( const powerproduct& c1, const powerproduct& c2 );

   // Contrary to Java, structs defined inside other structs
   // have no connection with the other struct.
   // The only difference is that you must write powerproduct::cmp instead
   // of cmp.

   struct cmp
   {
      bool operator() ( const powerproduct& c1, const powerproduct& c2 )
      {
         return compare( c1, c2 ) == -1;
      }
   };

   void normalize( );
      // 1. Sort the representation by variable. 
      // 2. Merge powvars with identical variable.
      // 3. Remove powvars with n == 0.

};


powerproduct operator * ( powerproduct c1, const powerproduct& c2 );

std::ostream& operator << ( std::ostream&, const powerproduct&  );

#endif 

