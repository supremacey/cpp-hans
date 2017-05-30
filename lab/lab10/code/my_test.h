#include <iostream>
#include <string>

namespace mmf {
	class Meter {
		double val;
	public:
		explicit constexpr Meter(double meter) : val{meter} {}
	};

	void test1() {
		std::cout << "Test meters\n";
		Meter m2 {3.0};
	}
}
