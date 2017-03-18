#include <iostream>
#include <numeric>
namespace mmf
{
// Pure interface to abstract type
// virtual -> may be redefined later in a class derived from this one.
// pure virtual; that is, some class derived from Container must define the function.
// since Container does not provide definition for pure virtual functions the object of that type
// cannot be created, making Constainer an interface only class to classes implementing pure virtual functions
// Such class (Container) is called an ABSTRACT CLASS
// Class that provides interface to variety other classes is usually called POLYMORPHIC CLASS
class Container {
public:
	// no constructor since there is nothing to initialize
	virtual double& operator[](int) = 0;  // pure virtual function
	virtual int size() const = 0;   // const memeber function, pure virtual too
	virtual ~Container() {}  // destructor
	// destructor is necessary since when handling through the reference or pointer 
	// to abstract class, the implementing class can call its destructor when someone
	// destroys it throug that abstract reference
};

class Vector : public Container {
private:
	size_t sz;
	double *elem;
public:
	Vector() = delete;
	Vector(size_t s): sz{s}, elem{new double[s]} {}
	~Vector() {
		delete [] elem;
	}
	double& operator[](int i) {
		return elem[i];
	}
	int size() const {
		return sz;
	}
};

}

void fill(mmf::Container& c)
{	
	std::iota(&c[0], &c[c.size()], 0);
}

void print(mmf::Container& c) {
	for (size_t i = 0; i<c.size(); ++i)
		std::cout << c[i] << " ";
}

int main()
{
	mmf::Vector v1 {10};
	fill(v1);
	print(v1);
	return 0;
}
