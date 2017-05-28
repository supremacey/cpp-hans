
#include "powerproduct.h"
#include <algorithm>


std::ostream& operator << ( std::ostream& out, const powvar & p )
{
   if( p.n == 0 )
   {
      out << "1"; // Should not happen, but we still have to print something.
      return out;
   }

   out << p.v;
   if( p.n == 1 )
      return out;

   if( p.n > 0 )
      out << "^" << p.n;
   else
      out << "^{" << p.n << "}";
   return out;
}


std::ostream& operator << ( std::ostream& out, const powerproduct& c )
{
   if( c. isunit( ))
   {
      out << "1";
      return out;
   }

   for( auto p = c. repr. begin( ); p != c. repr. end( ); ++ p )
   {
      if( p != c. repr. begin( ))
         out << ".";
      out << *p;
   }

   return out;
}


int powerproduct::power( ) const 
{
   int p = 0;
   for( auto pv : repr )
      p += pv. n;
   return p;
}


void
powerproduct::normalize( ) {
	auto desc_cmp = [](const powvar& lhs, const powvar& rhs){
		return lhs.v < rhs.v;
	};
	std::sort(repr.begin(), repr.end(), desc_cmp);

	auto top_val = repr.back();  // take first element and erase it
	repr.pop_back();

	std::vector<powvar> new_repr{};  // create a new vector
	new_repr.reserve(repr.size());

	for (auto last = repr.rbegin(); last!=repr.rend(); ++last) {
		if (last->v == top_val.v) {
			top_val.n += last->n;
		}
		else {
			new_repr.push_back(std::move(top_val));
			top_val = *last;
		}
	}

	new_repr.push_back(std::move(top_val));


	for (const auto& v : repr ) std::cout << v << " ";
	for (const auto& v : new_repr ) std::cout << v << " ";

	new_repr.shrink_to_fit();  // shrink new vector
	repr = std::move(new_repr);
}
	// 1. Sort the representation by variable. 
	// 2. Merge powvars with identical variable.
	// 3. Remove powvars with n == 0.

