#include "stack.h"

stack::stack( std::initializer_list<double> d ) : current_size{ 0 },
						  current_capacity{ d.size()*2 },
						  tab{ new double[d.size()*2] }
{
	for (double i : d)
		push(i);
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
	for (size_t i = 0; i<s.current_size; ++i)
		buff[i] = s.tab[i];

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
	// TODO(maciej) how to unget last 2 characters from a stream

	if (s.current_size == 0)  return stream << "{}";

	stream << "{" << s.tab[0];
	for (size_t i = 1; i < s.current_size; ++i)
		stream << s.tab[i];
	return stream << "}";
}

