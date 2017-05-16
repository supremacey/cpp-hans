#ifndef UMAPS__HPP
#define UMAPS__HPP

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <functional>
#include <algorithm>

struct case_insensitive_hash {
	size_t operator()( const std::string& s ) const;
};

struct case_insensitive_equality {
	bool operator()( const std::string& s1, const std::string& s2 ) const;
};

size_t
case_insensitive_hash::operator()( const std::string& s ) const
{
	// bad - kopiowanie stringa do pamięci
	// iteruj po każdej litercce i napisz własną funkcję hashującą, np.
	// h = h * bigPrime + s[i]
	std::string lwr{s};
	std::transform(lwr.begin(), lwr.end(), lwr.begin(), ::tolower);
	std::hash<std::string> hf;
	return hf(lwr);
}

bool
case_insensitive_equality::operator()
	( const std::string& s1, const std::string& s2 ) const
{
	auto len = (s1.size() < s2.size()) ? s1.size() : s2.size();
	for (size_t i = 0; i<len; ++i) {
		if ( !(tolower(s1[i]) == tolower(s2[i])) ) return false;
	}
	return true;
}

template< typename H = std::hash< std::string >,
	      typename E = std::equal_to< std::string >>
std::unordered_map< std::string, unsigned int, H, E >
hashed_frequencytable( const std::vector<std::string> & text )
{
	std::unordered_map< std::string, unsigned int, H, E > result{};
	for (const auto& item : text) {
		result[item]++;
	}
	return result;
}

template< typename H = std::hash< std::string >,
	      typename E = std::equal_to< std::string >>
std::ostream&
operator<<(std::ostream& lhs,
		   const std::unordered_map< std::string, unsigned int, H, E >& rhs)
{
	for (const auto& p: rhs)
		lhs << p.first << ": " << p.second << "\n";
	
	return lhs;
}

#endif
