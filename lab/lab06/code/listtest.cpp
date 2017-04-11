
#include "listtest.h"

#include <random>
#include <chrono>
#include <algorithm>
#include <locale>
#include <sstream>

// Sort the list with bubble sort, using assignments for the exchanges.
void
listtest::sort_assign( std::list< std::string > & l )
{
	for (auto it_e = l.end(); it_e != l.begin(); --it_e) {
		for (auto it = l.begin(), itn = ++l.begin(); itn != it_e; ++it, ++itn) {
			if ( (*itn) < (*it) ) {
				auto s = *it;
				*it = *itn;
				*itn = s;
			}
		}
	}
}
// Sort the list with bubble sort, using std::swap for the exchanges.
void
listtest::sort_move( std::list< std::string > & l )
{
	for (auto it_e = l.end(); it_e != l.begin(); --it_e) {
		for (auto it = l.begin(), itn = ++l.begin(); itn != it_e; ++it, ++itn) {
			if ( (*itn) < (*it) ) {
				std::iter_swap(it, itn);
			}
		}
	}
}
// Sort using std::sort.
void
listtest::sort_std( std::list< std::string > & l )
{
	l.sort();
}

std::list< std::string >
listtest::randomstrings( size_t nr, size_t s ) {
   static std::default_random_engine gen( 
      std::chrono::system_clock::now( ). time_since_epoch( ). count( ) );
         // Narrowing long int into int, but that is no problem.

   static std::string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ012345689";
   static std::uniform_int_distribution<int> distr( 0, alphabet. size( ) - 1);
      // More narrowing.

   std::list< std::string > res;

   for( size_t i = 0; i < nr; ++ i )
   {
      std::string rand;
      for( size_t j = 0; j < s; ++ j )
      {
         rand. push_back( alphabet[ distr( gen ) ] );  
      }

      res. push_back( std::move( rand ));
   }
   return res;
}

std::list<std::string> 
listtest::readfile( std::istream& input ) 
{
	std::list<std::string> result;
	
	char c;
	bool word;
	std::stringstream myss;

	while ((input.get(c)).good()) {
		if (std::isspace(c) || std::ispunct(c))	{
			if (word) {
				result.push_back(myss.str());
				myss.str("");
				word = false;
			}
			continue;
		}
		myss << c;
		word = true;
	}

	result.push_back(myss.str());
	 
	return result;

}

std::ostream& 
operator << ( std::ostream& out , const std::list< std::string > & l)
{
	out << "{ ";

	for (auto& item : l)
		out << item << " ";

	return out << "}";
}




