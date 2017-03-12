#include <iostream>
#include <string>

// (TODO):Maciej - add to binrary number conversion using bitstreams?
// (TODO):Maciej - when parsing a string use String Streams (sstream, inputss, outputss)

// create an enum to keep track of currnet roman number occurence
// in practice it tells whether to add or subtracut a value from total count
enum ROMAN_ARITHMETIC {I, V, X, L, M};

int to_arabic(std::string roman)
{
	int result = 0;
	char element = 'I';
	// reading single elements from the string
	switch(element) {
	case 'I' : break;  // 1
	case 'V' : break;  // 5
	case 'X' : break;  // 10
	case 'L' : break;  // 50
	case 'C' : break;  // 100
	case 'M' : break;  // 1000
	}

	return result;
}

std::string to_roman(int arabic) { return "not implemented"; }

int main(int argc, char* argv[])
{
	return 0;
}
