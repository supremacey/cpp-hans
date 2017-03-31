#include <iostream>
#include <cassert>
#include "stack.h"

void test() {
	stack s1 = { 1, 2, 3, 4, 5 };
	stack s2 = s1; // Copy constructor.
	// j is not size_t, because multiplying size_t with itself is
	// unnatural:
	for( unsigned int j = 0; j < 20; ++ j )
		s2. push( j * j );

	s1 = s2;
		// Assignment.
	s1 = s1;
		// Always check for self assignment.
	s1 = { 100,101,102,103 };
		// Works because the compiler inserts constructor and
		// calls assignment with the result.
		// Won’t compile. In order to get it compiled, remove const:
	std::cout << s1 << std::endl;
#if 0
	const stack& sconst = s1;
	sconst. top( ) = 20;
	sconst. push(15);
#endif 
}

void newTest()
{
	stack s1 = {1,2,3,4,5,6,7,8,9,0};
	std::cout << s1 << "\n";
	s1 = s1;
	stack s2 = s1;
	s2[5] = 1000;
	s2[0] = 1000;
	s2[2] = 1000;
	for (auto i : {0,1,2,3,4,5,6,7,8,9})
		std::cout << s1[i];
	std::cout << s1 << " "  << s2 << "\n";
}

int main(int argc, char* argv[])
{
	test();
	newTest();
	return 0;
}
