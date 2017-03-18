#ifndef _STACK
#define _STACK 1

#include <iostream>
#include <initializer_list>
#include <stdexcept>

class stack
{
	size_t current_size;
	size_t current_capacity;
	double* tab;
	void ensure_capacity( size_t c );
public:
	stack( ) : current_size{0},
			   current_capacity{0},
			   tab{nullptr}
	{}
	stack( std::initializer_list<double> d );
	stack( const stack& s ) : current_size{ s.current_size },
				  current_capacity{ s.current_capacity },
				  tab{ new double[s.current_capacity] }
	{
		std::copy(s.tab, (s.tab + s.current_size), tab);
	}
	~stack( ) {
		delete [] tab;
	}
	void operator = ( const stack& s );
	void push( double d );
	void pop( ) {
		if (current_size == 0)
			throw std::runtime_error("Stack already empty.");
		--current_size;
	}
	void reset( size_t s ) {
		if (s > current_size)
			throw std::logic_error("Cannot reset smaller stack.");
		current_size = s;
	}
	double& top() {
		if (current_size > 0)
			return tab[current_size - 1];
		throw std::out_of_range("Stack is empty.");
	}
	double top( ) const {
		if (current_size > 0)
			return tab[current_size - 1];
		throw std::out_of_range("Stack is empty.");
	}
	double operator[] (size_t i) const;
	double& operator[] (size_t i);
	size_t size( ) const { return current_size; }
	bool empty( ) const { return current_size == 0; }
	// Zadanie 4
	friend std::ostream& operator<< (std::ostream& stream, const stack& s);
};

//inline std::ostream&
//operator << (std::ostream& stream, const stack& s)
//{
//	// TODO(maciej) how to unge last 2 characters from a stream
//	stream << "{ ";
//	for (size_t i = 0; i < s.current_size; ++i)
//		stream << s.tab[i] << ", ";
//	return stream << "}";
//}

#endif // _STACK
