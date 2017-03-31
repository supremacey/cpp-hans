#include <iostream>
#include <cassert>
#include <stdexcept>
#include <iterator>
#include <algorithm>
#include "stack.h"

#define OLD	0

#if OLD
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
#endif // OLD

// Random access operator test
void test_randacc()
{
	stack s1{1,2,3,4,5};
	const stack s2{6,7,8,9,0};
	std::cout << "operator[] test\n";
	std::cout << "s1: " << s1 << "\n";
	std::cout << "s2: " << s2 << "\n";

	for (size_t i = 0; i<s2.size(); ++i)
		std::cout << "s2[" << i << "] = " << s2[i] << "\n";

	for (size_t i = 0; i<s2.size(); ++i)
		std::cout << "s1[" << i << "] = s2[" << i <<"] = " << (s1[i] = s2[i]) << "\n";

	for (size_t i = 0; i<s1.size(); ++i)
		++s1[i];

	std::cout << "++s1[i] for each s1 element: " << s1 << "\n";
}
// += operators test
void test_adeq()
{
	stack s1{1,2,3,4,5};
	stack s2{6,7,8,9,0};
	stack s3{};
	std::cout << "operator+= test\n";
	std::cout << "s1: " << s1 << "\ns2: " << s2 << "\ns3: " << s3 <<  "\n";

	for (auto d : {-3,-2,-1}) {
		s3 += d;
		std::cout << "s3 += " << d << ": " << s3 << "\n";
	}

	s3 += s1;
	std::cout << "s3 += s1: " << s3 << "\n";
 
	s3 += s2;
	std::cout << "s3 += s2: " << s3 << "\n";

	s3 += s3;
	std::cout << "s3 += s3: " << s3 << "\n";
}
// addition (+) operator test
void test_add()
{
	stack s1{1,2,3,4,5};
	stack s2{6,7,8,9,0};
	stack s3 = s1+s2;
	std::cout << "operator+ test\n";
	std::cout << "s1: " << s1 << "\ns2: " << s2 << "\n";
	std::cout << "s3 = s1 + s2: " << s3 << "\n";
	std::cout << "s1 + s3 + s2: " << s1 + s3 + s2 << "\n";
}

int main()
{
#if OLD
	test();
	newTest();
#endif
	test_randacc();
	test_add();
	test_adeq();
	return 0;
}
