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
		// TODO(maciej) How to implement copy constructor since we cannot access the memory
	}
	~stack( ) {
		if (current_capacity > 0 )
			delete [] tab;
		current_size = 0;
		current_capacity = 0;
	}
	void operator = ( const stack& s ) {
		// TODO(maciej) Fix it
		while ( !(s.empty()) ) {
			push(s.top());
			//s.pop();
		}
	}
	void push( double d );
	void pop( ) {
		if (current_size ==  0)
			throw std::runtime_error("Stack already empty.");

		--current_size;
	}
	void reset( size_t s ) {
		if (s > current_size)
			throw std::logic_error("Cannot reset smaller stack.");

		while( current_size > s)
			pop();
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
	size_t size( ) const { return current_size; }
	bool empty( ) const { return current_size == 0; }
	// Zadanie 4
	friend std::ostream& operator << (std::ostream stream, const stack& s);
};

std::ostream&
operator << (std::ostream stream, const stack& s)
{
	// TODO(maciej) how to unget last 2 characters from a stream
	stream << "{ ";
	for (size_t i = 0; i < s.current_size; ++i)
		stream << s.tab[i] << ", ";
	return stream << "}";
}

#endif // _STACK
