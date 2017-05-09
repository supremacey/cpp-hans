#ifndef MAPS_HPP
#define MAPS_HPP

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>

struct case_insensitive_cmp {
	bool operator()(const std::string& lhs, const std::string& rhs) const;
};


template<typename C = std::less<std::string>>
std::map<std::string, unsigned int, C>
frequencytable(const std::vector<std::string> text)
{
	std::map<std::string, unsigned int, C> result {};
	for (const auto & item : text)
		result[item]++;
	return result;
}

template<typename C>
std::ostream&
operator<<(std::ostream& lhs,
		   const std::map<std::string, unsigned int, C>& rhs)
{
	for (const auto & p: rhs)
		lhs << p.first << ": " << p.second << "\n";
	
	return lhs;
}

bool
case_insensitive_cmp::operator()
	(const std::string& lhs, const std::string& rhs) const
{
	auto len = (lhs.size() < rhs.size()) ? lhs.size() : rhs.size();
	for(size_t i = 0; i<len; ++i)
		if (std::tolower(lhs[i]) != std::tolower(rhs[i]))
			return std::tolower(lhs[i]) < std::tolower(rhs[i]);

	return lhs.size() < rhs.size();
	//return lhs < rhs;
}


#endif
