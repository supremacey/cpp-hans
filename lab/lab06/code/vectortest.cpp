#include "vectortest.h"

#include <random>
#include <chrono> 
#include <algorithm>
#include <iostream>
#include <sstream>
#include <locale>

std::vector< std::string >
vectortest::randomstrings( size_t nr, size_t s )
{
   static std::default_random_engine gen( 
      std::chrono::system_clock::now( ). time_since_epoch( ). count( ) );
         // Narrowing long int into int, but that is no problem.

   static std::string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ012345689";
   static std::uniform_int_distribution<int> distr( 0, alphabet. size( ) - 1);
      // More narrowing.

   std::vector< std::string > res;

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
         

std::vector<std::string> 
vectortest::readfile( std::istream& input ) 
{
	std::vector<std::string> result;
	
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

void vectortest::sort_assign( std::vector< std::string > & v )
{
	for (size_t j = 0; j<v.size(); ++j) {
		for (size_t i = 0; i<j; ++i) {
			if (v[j] < v[i]) {
				std::string s = v[i];
				v[i] = v[j];
				v[j] = s;
			}
		}
	}
}

void vectortest::sort_move( std::vector< std::string > & v )
{
	for (size_t j = 0; j<v.size(); ++j) {
		for (size_t i = 0; i<j; ++i) {
			if (v[j] < v[i])
				std::swap(v[i], v[j]);
		}
	}
			
}

void vectortest::sort_std( std::vector< std::string > & v )
{
	std::sort(v.begin(), v.end());
}

std::ostream& 
operator << ( std::ostream& out, const std::vector< std::string > & vect ) 
{ 
	out << "{ ";

	for (auto & item : vect)
		out << item << " ";

	return out << "}";
}



