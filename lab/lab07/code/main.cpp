#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>

#include "maps.hpp"
#include "umaps.hpp"
#include "maps_tests.hpp"


int
main(int argc, char **argv)
{
	auto txt = read_file("test.txt");
	auto small = read_file("small.txt");
	//test_freq(txt);
	//test_freq<case_insensitive_cmp>(small);
	//test_cio();
	//test_cih();
	//test_cie();
	//test_hfreq(txt);
	//test_hfreq<case_insensitive_hash, case_insensitive_equality>(small);
	test_book<case_insensitive_cmp, case_insensitive_hash, case_insensitive_equality>();
	return 0;
}
