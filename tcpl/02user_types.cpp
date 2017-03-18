#include <iostream>

struct Vector{
	int sz;
	double* elem;

};

void Vector_init(Vector& v, int s)
{
	v.sz = s;
	v.elem = new double[s];
}

void Vector_clean(Vector& v)
{
	delete [] v.elem;
}

//class Vec {
//public:
//	// TODO(maciej): Is there any reason for empty vector?
//	// Vec(): elem{nullptr}, curr{nullptr}, sz{0} {}
//	Vec(int s): elem{new double[s]}, curr{elem}, sz{s} {}
//	double& at(int i)
//	{
//		if (i < sz) return elem[i];
//		else std::cerr << "Index out of vector bound.\n";
//	}
//	double& operator [](int i) { return at(i); }
//	// TODO(maciej): implement those
//	double pop() {
//		return elem[--sz];
//	}
//	void push(double d) {
//		elem []	
//	}
//	int size() { return sz; }
//	~Vec() { delete [] elem; sz = 0; }
//private:
//	int sz;
//	double *elem;
//	double *curr;
//};

//void test_Vec()
//{
//	Vec v()
//}

int main(int argc, char* argv[])
{
	Vector v;
	Vector_init(v, 10);

	for (auto a : {1,2,3,4,5,6,7,8,9,10})
		v.elem[a-1] = a;

	double sum = 0;
	for (int i =0; i<v.sz; ++i)
		sum += v.elem[i];
	
	std::cout << sum << "\n";

	Vector_clean(v);

	return 0;	
}
