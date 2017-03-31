#include "stack.h"
#include <algorithm>
#include <iterator>

stack::stack( std::initializer_list<double> d ) : current_size{ d.size() },
						  current_capacity{ d.size()*2 },
						  tab{ new double[d.size()*2] }
{
	std::copy(d.begin(), d.end(), tab);
}

void
stack::ensure_capacity( size_t c )
{
	if( current_capacity < c )
	{
		// New capacity will be the greater of c and 
		// 2 * current_capacity.
		if( c < 2 * current_capacity )
			c = 2 * current_capacity;

		double* newtab = new double[ c ];
		for( size_t i = 0; i < current_size; ++ i )
			newtab[i] = tab[i];

		current_capacity = c;
		delete[] tab;
		tab = newtab;
	} 
}

void
stack::push( double d )
{
	ensure_capacity(current_size + 1);
	tab[current_size++] = d;
}
void stack::operator = ( const stack& s ) {
	double * buff = new double [s.current_capacity];
	std::copy(s.tab, (s.tab+s.current_size), buff);

	current_size = s.current_size;
	current_capacity = s.current_capacity;
	delete [] tab;
	tab = buff;
}
// operator either can be defined here or be inlined in header class
// notice that it doesn't have the class specifier (stack::) since
// it is a friend, not a class method
std::ostream&
operator << (std::ostream& stream, const stack& s)
{
	// TODO(maciej) Make it more cool with streambuffer or i don't know :) 
	stream << "{";
	std::copy(s.tab, (s.tab+s.current_size), std::ostream_iterator<double>(stream, " "));
	return stream << "}";
}
double
stack::operator[] (size_t i) const
{
	if (i >= current_size) throw std::out_of_range("Out of range stack random access.");
	return tab[i];
}
double&
stack::operator[] (size_t i)
{
	if (i >= current_size) throw std::out_of_range("Out of range stack random access.");
	return tab[i];
}
