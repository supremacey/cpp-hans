#ifndef MAPS_TEST_HPP
#define MAPS_TEST_HPP

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <map>
#include <unordered_map>

#include "maps.hpp"
#include "umaps.hpp"

std::vector<std::string>
read_file(const std::string& file_name)
{
	std::vector<std::string> result{};
	std::ifstream ifile{file_name, std::ios::in};

	std::string word{};
	char c;
	while (ifile.get(c)) {
		if (std::isspace(c) || std::ispunct(c)) {
			if (word.size() > 0)
				result.push_back(std::move(word));
		}
		else {
			//word += std::tolower(c);
			word += c;
		}
	}
	// for remaining word
	if (word.size() > 0)
		result.push_back(std::move(word));

	return result;
}

template<typename C = std::less<std::string>>
void
test_freq(const std::vector<std::string>& txt)
{
	std::cout << "Text with " << txt.size() << " words.\n";

	auto bag_of_words = frequencytable<C>(txt);
	std::cout << bag_of_words;
}

void
test_cio()
{
	std::cout << "Case_insensitive_cmp test.\n";
	case_insensitive_cmp c{};
	std::cout << std::boolalpha 
		<< "c( \"a\", \"A\" ): " << c( "a", "A" ) << "\n"
		<< "c( \"aaa\", \"A\" ): " << c( "aaa", "A" ) << "\n"
		<< "c( \"A\", \"a\" ): " << c( "A", "a" ) << "\n"
		<< "c( \"A\", \"aaa\" ): " << c( "A", "aaa" ) << "\n"
		<< "c( \"a\", \"b\" ): " << c( "a", "b" ) << "\n"
		<< "c( \"A\", \"b\" ): " << c( "A", "b" ) << "\n";
}

void
test_cih()
{
	std::cout << "case_insensitive_hash test.\n";
	std::vector<std::string> vs = {"maciej", "MACIEJ", "Maciej", "MaCIeJ"};
	case_insensitive_hash h;
	for (const auto& item : vs)
		std::cout << item << ": " << h(item) << "\n";
}

void
test_cie()
{
	std::cout << "case_insensitive_equality test.\n";
	case_insensitive_equality e{};
	std::cout << std::boolalpha 
		<< "e( \"a\", \"A\" ): " << e( "a", "A" ) << "\n"
		<< "e( \"aaa\", \"A\" ): " << e( "aaa", "A" ) << "\n"
		<< "e( \"A\", \"a\" ): " << e( "A", "a" ) << "\n"
		<< "e( \"A\", \"aaa\" ): " << e( "A", "aaa" ) << "\n"
		<< "e( \"a\", \"b\" ): " << e( "a", "b" ) << "\n"
		<< "e( \"A\", \"b\" ): " << e( "A", "b" ) << "\n";
}

template< typename H = std::hash< std::string >,
	      typename E = std::equal_to< std::string >>
void
test_hfreq(const std::vector<std::string>& txt)
{
	std::cout << "Text with " << txt.size() << " words.\n";

	auto bag_of_words = hashed_frequencytable<H, E>(txt);
	std::cout << bag_of_words;
}

template< typename C = std::less<std::string>,
	      typename H = std::hash< std::string >,
	      typename E = std::equal_to< std::string >>
void
test_book()
{
	std::cout << "Maps test using first book of 'Confessiones'.\n";
	auto book = read_file("book1.txt");
	auto bag = frequencytable<C>(book);
	auto ubag = hashed_frequencytable<H, E>(book);

	std::vector<std::string> look_for = {"magnus", "hominum", "memoria"};
	for (const auto& item : look_for)
		std::cout << item << ": " << ubag.at(item) << "\n";

	auto find_most_frq = [&](){
		unsigned int max = 0;
		std::string word;
		for (const auto& item : bag)
			if (item.second > max) {
				max = item.second;
				word = item.first;
			}
		std::cout << "most frequent word in bag " << word << ": " << max << "\n";

		word = "";
		max = 0;
		for (const auto& item : ubag)
			if (item.second > max) {
				max = item.second;
				word = item.first;
			}
		std::cout << "most frequent word in ubag " << word << ": " << max << "\n";
	};
	find_most_frq();
}
#endif
