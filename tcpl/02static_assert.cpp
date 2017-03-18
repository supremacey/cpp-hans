#include <type_traits>

template <class T>
struct data_structure {
	static_assert(std::is_default_constructible<T>::value, "Data Structure requires default constructable elements.");
};

struct no_default_constr {
	no_default_constr() = delete;
};

int main() {
	// calling default constructor on both types
	data_structure<int> ok;
	//data_structure<no_default_constr> not_ok;
}
