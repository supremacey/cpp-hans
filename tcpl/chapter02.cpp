#include <iostream>
#include <complex>
#include <string>

constexpr auto
compile_time() -> decltype(2*2)
{
	return 2 * 2;
}

constexpr int two_time(int time) { return 2 * time; }
constexpr auto FOUR = compile_time();
constexpr auto FOUR2 = two_time(10);

using namespace std;

double
square(double n)
{ 
	return n * n;
}

struct A{
	// TODO(maciej) - figure this one out
	// static constexpr string name = L"Maciej Faron";
	const int a;
	A(): a{10}
	{}

	A(int i): a{i}
	{}
};

void pointer_decay(const char * p) 
{
	std::cout << "I am pointing to the object of size " << sizeof(*p) << "\n";
}

int main(int argc, char * argv[]) {
#if 0
	complex<double> c1 {1.0,1.0};
	//int i {3.14}; // this will trow error and exception witch is good - exception auto - no typer conversion
	auto name = "Maciej Faron";
	std::cout << c1*c1 << "\n";
	cout << 3%-2 << " " << 3%2 << endl;

	int x[10] = {1,2,3,4,5,6,7,8,9,0};
	int* ip = &x[1];

	cout << x[1] << *(ip+1) << endl;

	A one, two {20};
	cout << one.a << " " << two.a << "\n";
#endif

	char name[7] {"Maciej"};  // charater literals are null terminated \0
	char* p = name;
	std::cout << name << " is size of " << sizeof(name) << " and pointer is size of " << sizeof(p) << "\n";
	for (int c : name)
		std::cout << "[" << c << "]\n";

	std::cout << name << "\n";
	name[6] = 'o';
	std::cout << name << "\n";
	pointer_decay(name);

	int i = 10;
	int j = 20;
	const int * p_to_ci = &i;
	int * const cp_to_i = &i;
	const int * const cp_to_ci = &i;

	std::cout << i << "\n";
	// std::cout << ++(*p_to_ci) << "\n";  // compile time error -> I am pointing to constat value
	std::cout << ++(*cp_to_i) << "\n";  // ok -> only pointer is constant not the value I am pointing
	// cp_to_i = &j;  // compile error -> the constant pointer cannot be modified
	std::cout << i << "\n";
	
	return 0;
}
