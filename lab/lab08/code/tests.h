#include <vector>
#include <iostream>
#include "move.h"
#include "fifteen.h"

// Tests --------------------------------------------------
void test1()
{
	std::cout << "---------------------------\n";
	std::cout << "Testing printing and constructors\n";
	fifteen f{ { 1, 3, 4, 12 }, 
	       { 5, 2, 7, 11 }, 
	       { 9, 6, 14, 10 }, 
	       { 13, 15, 0, 8 } } ;
	std::cout << f << "\n";

	fifteen f2 {};
	std::cout << f2 << "\n";
}

void test2()
{
	fifteen f2 {};
	fifteen f{ { 1, 3, 4, 12 }, 
	       { 5, 2, 7, 11 }, 
	       { 9, 6, 14, 10 }, 
	       { 13, 15, 0, 8 } } ;

	std::cout << "---------------------------\n";
	std::cout << "Testing equals() function\n";
	std::cout << f << "and\n" << f << "are equal? " << std::boolalpha << f.equals(f) << "\n";

	std::cout << "---------------------------\n";
	std::cout << "Testing issolved() function\n";
	std::cout << f2 << "is solved?: " << std::boolalpha << f2.issolved() << "\n";
	std::cout << f << "is solved?: " << std::boolalpha << f.issolved() << "\n";

	std::cout << "---------------------------\n";
	std::cout << "Testing distance() function\n";
	std::cout << f2 << "distance to solve is: " << f2.distance() << "\n";
	std::cout << f << "distance to solve is: " << f.distance() << "\n";
}

void test4()
{
	std::cout << "---------------------------\n";
	std::cout << "Testing position() function\n";
	auto tiles = fifteen::dimension * fifteen::dimension;
	for (size_t a = 0; a<tiles; ++a) {
		auto p = fifteen::solvedposition(a);
		std::cout << "The position of " << a << " is: [" << p.first << ", " << p.second << "]\n";
	}
}

void test5()
{
	std::cout << "---------------------------\n";
	std::cout << "Testing hashvalue() function\n";
	fifteen fd{};
	fifteen f{ { 1, 3, 4, 12 }, 
	       { 5, 2, 7, 11 }, 
	       { 9, 6, 14, 10 }, 
	       { 13, 15, 0, 8 } } ;
	std::cout << "Hash: " << f.hashvalue() << "\n" << f;
	std::cout << "Hash: " << fd.hashvalue() << "\n" << fd;
}

void test6()
{
	std::cout << "---------------------------\n";
	std::cout << "Testing makemove() function\n";
	fifteen f{ { 1, 3, 4, 12 }, 
	       { 5, 2, 7, 11 }, 
	       { 9, 6, 14, 10 }, 
	       { 13, 15, 0, 8 } } ;
	std::vector<move> moves = {move::up, move::left, move::right, move::down};
	std::cout << "Starting with\n" << f;
	for (auto& m : moves) {
		std::cout << "Making move: " << m << "\n";
		f.makemove(m);
		std::cout << f;
	}

	try {
		std::cout << "Illigal move: " << move::down << "\n";
		f.makemove(move::down);
	}
	catch (illegalmove ime) {
		std::cout << "catching\n";
	}
}
