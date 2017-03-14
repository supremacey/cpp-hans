#include <iostream>
#include "stack.h"

stack::stack( std::initializer_list<double> d ) : current_size{ d.size() },
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
	// TODO(maciej) You can merge last 2 operations into 1
	ensure_capacity(current_size + 1);
	tab[current_size - 1] = d;
	++current_size;
}
