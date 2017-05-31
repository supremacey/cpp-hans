#include "polynomial.h"
#include "powerproduct.h"
#include "rational.h"
#include "bigint.h"

#include <iostream>
#include <string>
#include <cassert>

void tst_normalize() {
	std::cout << "--------------------------------------------------------------------------------\n";
	std::cout << "Test: powerproduct.normalize().\n";
	powvar v1{"x", 2};   // x^2
	powvar v2{"y", 2};   // y^2
	powvar v3{"x", 1};   // x
	powvar v4{"y", -2};  // y^-2
	powvar v5{"x", 0};   // x^0
	powvar v6{"yx", 2};  // yx^2
	powvar v7{"xy", 2};  // xy^2

	powerproduct p1{};
	//powerproduct p1 = {v1,v2,v3,v4,v5};	
	p1.repr.push_back(v1);
	p1.repr.push_back(v2);
	p1.repr.push_back(v3);
	p1.repr.push_back(v4);
	p1.repr.push_back(v5);
	p1.repr.push_back(v6);
	p1.repr.push_back(v7);
	std::cout << "before normalization: " << p1 << "\n";
	p1.normalize();
	std::cout << "after normalization: " << p1 << "\n";
}

void tst_cmp()
{
	std::cout << "--------------------------------------------------------------------------------\n";
	std::cout << "Test: powerproduct.compare().\n";
	powvar v1{"x", 7};
	powvar v2{"x", -7};
	powvar v3{"y", 1};

	powerproduct p1 {v1,v3};
	powerproduct p2 {v2,v3};
	powerproduct p3 {v1,v2,v3};
	powerproduct p4 {v3};

	auto say = [](const powerproduct& lhs, const powerproduct& rhs){
		std::cout << lhs << " and " << rhs << ": " << powerproduct::compare(lhs,rhs) << "\n";
	};
	say(p1,p2);
	say(p2,p1);
	say(p3,p4);
	auto print = [](const powerproduct& lhs, const std::string& msg, std::ostream& out){
		out << "Printing: " << msg << "\n";
		for (auto& pv : lhs.repr)
			out << pv << "\t";
		out << "\n";
		return;
	};
	print (p1, "p1", std::cout);
	print (p2, "p2", std::cout);
	print (p3, "p3", std::cout);
	print (p4, "p4", std::cout);
}
void tst_mul()
{
	std::cout << "--------------------------------------------------------------------------------\n";
	std::cout << "Test: operator * ().\n";
	powvar v1{"x", 7};
	powvar v2{"x", -7};
	powvar v3{"y", 1};

	powerproduct p1 {v1};
	powerproduct p2 {v2};
	powerproduct p3 {v3};
	auto say = [](const powerproduct& lhs, const powerproduct& rhs){
		std::cout << lhs << " * " << rhs << "= " << (lhs*rhs) << "\n";
	};
	say(p1,p2);
	say(p2,p1);
	say(p3,p2);
}

void test_polynomial_mul()
{
	std::cout << "--------------------------------------------------------------------------------\n";
	std::cout << "polynomial operator* ().\n";
	
	polynomial<double> p1{powerproduct{"x", 2}};
	p1[powerproduct{"y", 1}] = 2;
	polynomial<double> p2{powerproduct{"z", 3}};
	p2[powerproduct{"y", 1}] = 2;
	std::cout << p1 << " * " << p2 << " = " << (p1*p2) <<"\n";
}

int main() {
	std::cout << "My tsts.\n";
	tst_normalize();
	tst_cmp();
	tst_mul();
	test_polynomial_mul();
}
