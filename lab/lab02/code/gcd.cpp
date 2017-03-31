#include <iostream>

int gcd(int n1, int n2) {
	int a,b,r;
	if(n1>n2){ a=n1; b=n2; }
	else { a = n2; b=n1; }
	if (b == 0) { throw std::runtime_error("division by 0")}
	while ((r = a%b) != 0) {
		std::cout << a << " " << b << " " << r << "\n";
		a = b;
		b = r;
	}

	return b;
}

int main() {
	int a,b;
	std::cin >> a;
	std::cin >> b;
	std::cout << gcd(a,b) << std::endl;	
}
