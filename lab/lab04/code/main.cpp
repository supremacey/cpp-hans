#include "string.h"
#include "tests.h"
#include <iostream>
#include <stdexcept>
#include <vector>

// From the lecture. Not needed for the task:

//void fail_often( )
//{
//   srand( time( NULL ));
//   if( rand( ) & 1 )
//      throw std::runtime_error( "i failed" );
//}

void f( )
{
   string s = "this is a string";
   
   std::vector< string > vect = { "these", "are", "also", "string" };
   string more [] = {"these", "are", "even", "more", "string" };

   // fail_often( );
}

void test_randacc()
{
	std::cout << "operator[](size_t) ----------\n";
	string s = "hello";
	string s2 = "jello";
	std::cout << s.size() << " is the size of the string.\n";
	
	for (size_t i = 0; i<s.size(); ++i) {
		std::cout << s[i];
		s[i] -= 32;
	}
	std::cout << "\n";

	for (size_t i = 0; i<s.size(); ++i) {
		std::cout << s[i];
	}
	std::cout << "\n";

	for (size_t i = 0; i<s.size(); ++i) {
		std::cout << s2[i];
	}

	std::cout << "\n";
}

void test_addeq()
{
	std::cout << "operator+=(char) ----------\n";
	string s = "hello";
	s+='_';
	s+='w';
	s+='o';
	s+='r';
	s+='r';
	s+='l';
	s+='d';
	for (size_t i = 0; i<s.size(); ++i) {
		std::cout << s[i];
	}

	std::cout << "\noperator+=(string) ----------\n";
	string s2 = "! How are you doing?";
	s += s2;	
	for (size_t i = 0; i<s.size(); ++i) {
		std::cout << s[i];
	}
	std::cout << std::endl;
}

void test_add()
{
	std::cout << "\noperator+(string) ----------\n";
	string s1 = "Hello";
	string s2 = " world";
	string s3;
	std::cout << "Empty string: " << s3 << "\n";
	s3 = s1 + s2;
	std::cout << "s3 = s1 + s2: "<< s3 << "\n";
}

void test_logic()
{
	std::cout << "\noperator==(string, string) operator!=(string, string)----------\n";
	std::cout << test_strings::hw << "\n" << test_strings::li << "\n";
	std::cout << "hw == hw " << std::boolalpha << (test_strings::li == test_strings::li) << " li == li "
		<< std::boolalpha << (test_strings::li == test_strings::li) << "\n"; 
	std::cout << "hw != li " << std::boolalpha << (test_strings::hw != test_strings::li) << " li != hw "
		<< std::boolalpha << (test_strings::li != test_strings::hw) << "\n";

	string s1 = "aaa";
	string s2 = "Aa";
	string s3 = "ab";

	std::cout << "\noperator<(string, string) operator>(string, string)----------\n";
	std::cout << s1 << " < " << s2 << " : " << std::boolalpha << (s1 < s2) << "\n";
	std::cout << s2 << " < " << s3 << " : " << std::boolalpha << (s2 < s3) << "\n";
	std::cout << s1 << " > " << s2 << " : " << std::boolalpha << (s1 > s2) << "\n";
	std::cout << s2 << " > " << s3 << " : " << std::boolalpha << (s2 > s3) << "\n";
	std::cout << s2 << " < " << s2 << " : " << std::boolalpha << (s2 < s2) << "\n";
	std::cout << s2 << " > " << s2 << " : " << std::boolalpha << (s2 > s2) << "\n";

	std::cout << "\noperator<=(string, string) operator>=(string, string)----------\n";
	std::cout << s1 << " <= " << s2 << " : " << std::boolalpha << (s1 <= s2) << "\n";
	std::cout << s2 << " <= " << s3 << " : " << std::boolalpha << (s2 <= s3) << "\n";
	std::cout << s1 << " >= " << s2 << " : " << std::boolalpha << (s1 >= s2) << "\n";
	std::cout << s2 << " >= " << s3 << " : " << std::boolalpha << (s2 >= s3) << "\n";
	std::cout << s1 << " >= " << s1 << " : " << std::boolalpha << (s1 >= s1) << "\n";
	std::cout << s1 << " <= " << s1 << " : " << std::boolalpha << (s1 <= s1) << "\n";
}

void test_iterator()
{
	string s = "this is a string";
	std::cout << s << "\n";
	for( char& c : s )
		c = toupper(c);
	std::cout << s << "\n";
}

int main( int argc, char* argv [ ] )
{
   // Add more tests by yourself. Untested code = unwritten code. 


   string s;
   string s2 = "hello";

   s = s2;  // Assignment, not initialization.
   s = s;

   std::cout << "s = " << s << "\n";
   test_randacc();
   test_addeq();
   test_add();
   test_logic();
   test_iterator();
   return 0;
}


