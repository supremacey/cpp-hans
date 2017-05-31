
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
	if (repr.size() == 0) return;
	std::sort(repr.begin(), repr.end(), desc_cmp);

	auto top_val = repr.back();  // take first element and erase it
	repr.pop_back();

	// using two iterators you can save on this vector
	std::vector<powvar> new_repr{};  // create a new vector
	new_repr.reserve(repr.size());

	for (auto last = repr.rbegin(); last!=repr.rend(); ++last) {
		if (last->v == top_val.v) {
			top_val.n += last->n;
		}
		else {
			if (top_val.n != 0)
				new_repr.push_back(std::move(top_val));
			top_val = *last;
		}
	}

	new_repr.push_back(std::move(top_val));

	new_repr.shrink_to_fit();  // shrink new vector
	repr = std::move(new_repr);
}
	// 1. Sort the representation by variable. 
	// 2. Remove powvars with n == 0.
	// 3. Merge powvars with identical variable removing 0.
int
powerproduct::compare( const powerproduct& c1, const powerproduct& c2 )
{
	// compare value -> if same compare lexicographically
	auto c1it = c1.repr.cbegin();
	auto c2it = c2.repr.cbegin();
	int r = 0;
	while (c1it != c1.repr.end() && c2it != c2.repr.end()) {
		if (r = (c1it->n - c2it->n))
			return r>0? 1 : -1;
		if ( !(c1it->v == c2it->v))
			return (c1it->v > c2it->v)? 1 : -1;
		++c1it;
		++c2it;
	}
	if (c1.repr.size() < c2.repr.size()) return -1;
	else if (c1.repr.size() > c2.repr.size()) return 1;
	return 0;
}

powerproduct
operator * ( powerproduct c1, const powerproduct& c2 )
{
	c1.repr.insert(c1.repr.end(), c2.repr.begin(), c2.repr.end());
	c1.normalize();
	return c1;
}

