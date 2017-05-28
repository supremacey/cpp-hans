#include "powerproduct.h"
#include "rational.h"
#include "bigint.h"

#include <iostream>
#include <string>
#include <cassert>

void tst_normalize() {
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

int main() {
	std::cout << "My tsts.\n";
	tst_normalize();
}
