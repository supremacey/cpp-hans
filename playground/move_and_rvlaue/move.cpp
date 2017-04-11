#include <iostream>
#include <vector>

using namespace std;

struct myvec {
	int *values;
	size_t capacity;
	size_t sz;

	myvec() {
		sz = 0;
		capacity = 10;
		values = new int[capacity];

		std::cout << "default myvec() " << this << " \n";
	}

	myvec(const myvec& mv) {
		capacity = mv.capacity;
		sz = mv.sz;
		values = new int[capacity];
		std::copy(mv.values, (mv.values + mv.sz), values);

		std::cout << "copy myvec() " << this << " \n";
	}
	// rvalue reference move copy constructor
	myvec(myvec&& mv) {
		values = mv.values;
		capacity =mv.capacity;
		sz = mv.sz;
		mv.values = nullptr;
		mv.capacity = 0;
		mv.sz = 0;
		std::cout << "copy move myvec() " << this << " \n";
	}
	myvec& operator=(const myvec& mv) {
		capacity = mv.capacity;
		sz = mv.sz;
		int* buff = new int[capacity];
		std::copy(mv.values, (mv.values + mv.sz), buff);

		delete [] values;
		values = buff;
		std::cout << "copy operator= " << this << " \n";
		return *this;
	}
	// rvalue reference move copy assignment operator
	myvec& operator=(myvec&& mv) {
		values = mv.values;
		capacity =mv.capacity;
		sz = mv.sz;
		mv.values = nullptr;
		mv.capacity = 0;
		mv.sz = 0;
		std::cout << "copy move operator= " << this << " \n";
		return *this;
	}

	myvec(size_t s) {
		sz = 0;
		capacity = s;
		values = new int[capacity];
	}

	~myvec() {
		delete [] values;

		std::cout << "destructor ~myvec() " << this << " \n";
	}

	void push_back(int i) { 
		if (sz == capacity) {
			capacity *= 2;
			int* buff = new int[capacity];
			std::copy(values, (values+sz), buff);
				
		}
		values[sz++] = i;
		std::cout << "push_back(" << i << ") to " << this << "\n";
	}

	int* begin() { return values; }
	const int* begin() const { return values; }
	int* end() { return values+sz; }
	const int* end() const { return values+sz; }
};

myvec
doubleMyvec(const myvec& mv)
{
	std::cout << "doubleMyvec start \n";
	myvec result;
	for (const int *it_b = mv.begin(), *it_e = mv.end(); it_b != it_e; ++it_b) {
		result.push_back(2* *it_b);
	}
	return result;
}

void
runMyvec()
{
	myvec v;

	for (int i = 0; i<10; ++i)
		v.push_back(i);

	v = doubleMyvec(v);

	int i;
	std::cin >> i;
}
#if 0
vector<int>
doubleVector(const vector<int>& v)
{
	vector<int> doubleVec;
	doubleVec.reserve(v.size());  // function makes a copy of original vector

	for (auto iter_b = v.begin(), iter_e = v.end(); iter_b != iter_e; ++iter_b)
		doubleVec.push_back(2 * *iter_b);

	return doubleVec;  // but here also makes a copy of the doubleVec
	// 2 copies: 1 at return, 2 at assigmnet operator/constructor
	// 1st could be optimised by the compiler
}

void
test()
{
	vector<int> v1 = {0,1,2,3,4,5};
	auto v2 = doubleVector(v1);

	for (auto& item : v2)
		cout << item << ", ";

	cout << endl;
}
#endif

int x=10;

int& getRef()
{
	return x;  // lvalue -> reference to a place in memory
}

int getVal()
{
	return x;  // rvalue -> temporary object
}

void
lval_rval()
{
	std::cout << x << "\n";
	getRef() = 3;
	std::cout << x << "\n";
	//getVal() = 4;  // error: expression is not assignable
	std::cout << x << "\n";

}
/*
 * rvalue reference is the reference that will bind only to the temporaty object -> they allow us to build
 * constructs that will know when the object is temporary and have proper action with it.
 * */
std::string
getString()
{
	return "Hello World!";
}

void printRef(const std::string& ref)
{
	std::cout << "(const std::string& ref) " << ref << "\n";
}
void printRef(std::string&& ref)
{
	std::cout << "(std::string&& ref) " << ref << "\n";
}

void
references()
{
	const std::string& clsref = getString(); // OK, it is temporary and will not be mutable
	//std::string& lsref = getString();   // Error, you will not change it since it is temporary
	const std::string&& crsref = getString();  // rval ref ok
	std::string&& rsref = getString();   // ok too! it is rval ref

	std::string name = "maciej";
	printRef(name);
	printRef(getString());

}
int
main()
{
	runMyvec();
	//lval_rval();
	//references();
	int z;
	std::cout << "main finishes\n";
	std::cin >> z;
}
