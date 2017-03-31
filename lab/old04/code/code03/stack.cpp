#include "stack.h"
#include <algorithm>
#include <iterator>

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

stack::stack( ) : current_size{0},
		   current_capacity{0},
		   tab{nullptr}
{}

stack::stack( std::initializer_list<double> d ) : current_size{ d.size() },
						  current_capacity{ d.size()*2 },
						  tab{ new double[d.size()*2] }
{
	std::copy(d.begin(), d.end(), tab);
}

stack::stack( const stack& s ) : current_size{ s.current_size },
			  current_capacity{ s.current_capacity },
			  tab{ new double[s.current_capacity] }
{
	std::copy(s.tab, (s.tab + s.current_size), tab);
}

stack::~stack( ) {
	delete [] tab;
}

void
stack::push( double d )
{
	ensure_capacity(current_size + 1);
	tab[current_size++] = d;
}

void
stack::pop( ) {
	if (current_size == 0)
		throw std::runtime_error("Stack already empty.");
	--current_size;
}

void
stack::reset( size_t s ) {
	if (s > current_size)
		throw std::logic_error("Cannot reset smaller stack.");
	current_size = s;
}

double&
stack::top() {
	if (current_size > 0)
		return tab[current_size - 1];
	throw std::out_of_range("Stack is empty.");
}

double
stack::top( ) const {
	if (current_size > 0)
		return tab[current_size - 1];
	throw std::out_of_range("Stack is empty.");
}

void
stack::operator=( const stack& s ) {
	double * buff = new double [s.current_capacity];
	std::copy(s.tab, (s.tab+s.current_size), buff);

	current_size = s.current_size;
	current_capacity = s.current_capacity;
	delete [] tab;
	tab = buff;
}

//stack
//stack::operator+(const stack& s) const
//{
//	stack result{};
//	result.current_capacity = current_capacity + s.current_capacity;
//	result.current_size = current_size + s.current_size;
//	result.tab = new double[result.current_capacity];
//
//	std::copy(tab, (tab+current_size), result.tab);
//	std::copy(s.tab, (s.tab+s.current_size), (result.tab+current_size));
//	return result;	
//}

double
stack::operator[] (size_t i) const
{
	if (i >= current_size)
		throw std::out_of_range("Out of range stack random access.");
	return tab[current_size - (i+1)];
}

double&
stack::operator[] (size_t i)
{
	if (i >= current_size)
		throw std::out_of_range("Out of range stack random access.");
	return tab[current_size - (i+1)];
}

void
stack::operator+=(double d)
{
	push(d);
}

void
stack::operator+=(const stack& s)
{
	size_t new_size = current_size + s.current_size;
	double *buff = new double [new_size*2];

	std::copy(tab, (tab+current_size), buff);
	std::copy(s.tab, (s.tab+s.current_size), (buff+current_size));

	tab = buff;
	current_size = new_size;
	current_capacity = new_size * 2;
}

// NEW
std::ostream&
operator << (std::ostream& stream, const stack& s)
{
	stream << "{";
	std::copy(s.tab, (s.tab+s.current_size),
			std::ostream_iterator<double>(stream, " "));
	return stream << "}";
}
#if 0
// OLD
std::ostream&
operator << (std::ostream& stream, const stack& s)
{
	stream << "{";
	for (size_t i =0; i<s.current_size; ++i)
		stream << ", " << s.tab[i];
	return stream << "}";
}
#endif

stack
operator+(const stack& a, const stack& b)
{
	stack result{};

	for(size_t i = a.size()-1; i>0; --i)
	result.push(a[0]);

	for(size_t i = b.size()-1; i>0; --i)
		result.push(b[i]);
	result.push(b[0]);

	return result;
}
