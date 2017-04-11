#include <fstream>
#include <iostream>
#include <random>

#include "listtest.h"
#include "vectortest.h"
#include "timer.h"

void
task1()
{
	std::ifstream myfile{"vectortest.cpp", std::ios_base::in};
	auto word_v = vectortest::readfile(myfile);
	for (auto w : word_v)
		std::cout << w << "\n";
}

void
task2()
{
	std::ifstream myfile{"test.txt", std::ios_base::in};
	auto myvec = vectortest::readfile(myfile);
	// Good info -> resizing a list doesn't benefit on performance
	std::list<std::string> mylist{};

	for (const auto &item : myvec )
		mylist.push_back(item);

	std::cout << mylist << "\n" << myvec << "\n";
}

void
task3_assign()
{
	std::ifstream myfile{"vectortest.cpp", std::ios_base::in};
	std::vector< std::string > vect = vectortest::readfile(myfile);

	std::cout << vect << "\n";

	// Or use timer:

	auto t1 = std::chrono::high_resolution_clock::now( ); 
	vectortest::sort_assign( vect );
	auto t2 = std::chrono::high_resolution_clock::now( );

	std::chrono::duration< double > d = ( t2 - t1 );
	std::cout << vect << "\n";

	std::cout << "sorting took " << d. count( ) << " seconds\n";
}

void
task3_move()
{
	std::ifstream myfile{"vectortest.cpp", std::ios_base::in};
	std::vector< std::string > vect = vectortest::readfile(myfile);

	std::cout << vect << "\n";

	// Or use timer:

	auto t1 = std::chrono::high_resolution_clock::now( ); 
	vectortest::sort_move( vect );
	auto t2 = std::chrono::high_resolution_clock::now( );

	std::chrono::duration< double > d = ( t2 - t1 );
	std::cout << vect << "\n";

	std::cout << "sorting took " << d. count( ) << " seconds\n";
}

void
task3_std()
{
	std::ifstream myfile{"vectortest.cpp", std::ios_base::in};
	std::vector< std::string > vect = vectortest::readfile(myfile);

	std::cout << vect << "\n";

	// Or use timer:

	auto t1 = std::chrono::high_resolution_clock::now( ); 
	vectortest::sort_std( vect );
	auto t2 = std::chrono::high_resolution_clock::now( );

	std::chrono::duration< double > d = ( t2 - t1 );
	std::cout << vect << "\n";

	std::cout << "sorting took " << d. count( ) << " seconds\n";
}

void
task4()
{
	size_t str_number = 10000;
	size_t str_size = 77;
	{
		auto strings = vectortest::randomstrings(str_number, str_size);
		timer assign{"Sorting with assign", std::cout};
		vectortest::sort_assign(strings);
	}
	{
		auto strings = vectortest::randomstrings(str_number, str_size);
		timer assign{"Sorting with move", std::cout};
		vectortest::sort_move(strings);
	}
	{
		auto strings = vectortest::randomstrings(str_number, str_size);
		timer assign{"Sorting with std::sort", std::cout};
		vectortest::sort_std(strings);
	}

}

void
task5()
{
	size_t str_number = 10000;
	size_t str_size = 77;
	{
		auto strings = listtest::randomstrings(str_number, str_size);
		timer assign{"Sorting with assign", std::cout};
		listtest::sort_assign(strings);
	}
	{
		auto strings = listtest::randomstrings(str_number, str_size);
		timer assign{"Sorting with move", std::cout};
		listtest::sort_move(strings);
	}
	{
		auto strings = listtest::randomstrings(str_number, str_size);
		timer assign{"Sorting with std::sort", std::cout};
		listtest::sort_std(strings);
	}

}

void test_reversi()
{
	auto myfile = std::ifstream("test.txt", std::ios_base::in);
	auto mylist = listtest::readfile(myfile);

	for (const auto& item : mylist)
		std::cout << item << "|";
	
	for (auto rb = mylist.rbegin(); rb != mylist.rend(); ++rb)
		std::cout << *rb << " ";

	std::cout << "\n";

}

int main( int argc, char* argv [] )
{
	//task1();
	
	//task2();

	//task3_assign();
	//std::cout << "\n";
	//task3_move();
	//std::cout << "\n";
	//task3_std();
	//std::cout << "\n";
	
	//task4();

	task5();
	
	//test_reversi();

	return 0;
}


