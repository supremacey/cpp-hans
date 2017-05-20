#include <iomanip>
#include <stdexcept>
#include "fifteen.h"
#include "move.h"

fifteen::fifteen( )
{
	for (size_t i = 0; i<dimension * dimension; ++i) {
		table[i/dimension][i % dimension] = (i+1) % (dimension*dimension);
	}
	open_i = open_j = 3;
}
  // Default constructor constructs the puzzle in solved state.

fifteen::fifteen( std::initializer_list< std::initializer_list< size_t >> init )
{
	if (init.size() != init.begin()->size() || init.size() != dimension)
		throw new std::invalid_argument("Input matrix is not NxN or N has the wrong size.");

	size_t i, j;
	i = j = 0;
	for (auto is : init) {
		for (auto num : is) {
			table[i][j] = num;
			if (num == 0) {
				open_i = i;
				open_j = j;
			}
			++j;	
		}
		j = 0;
		++i;
	}
}

fifteen::position
fifteen::solvedposition( size_t val )
{
	if (val != 0)
		return position { (val-1)/dimension, ((val-1) % dimension)};	
	else 
		return position {dimension -1, dimension -1};
}

void
fifteen::makemove( move m )
{
	throw new illegalmove(m);
}
  // This method tries to make a move m. If it fails then 
  // it throws illegalmove( move ); 
  // Note that in C++, you don't have to declare possible exceptions.
  // A move is illegal if it would move the open place out of the
  // board. 

size_t
fifteen::distance( ) const
{
	size_t result = 0;
	for (size_t i =0; i<dimension; ++i) {
		for (size_t j=0; j<dimension; ++j) {
			result += fifteen::distance(position {i,j}, fifteen::solvedposition(table[i][j]));
		}
	}
	return result;
}
  // Estimated distance from solution. Use Manhattan distance,
  // see the wikipedia article. 

bool
fifteen::issolved( ) const
{
	return distance() == 0;
}
  // True if the puzzle is in solved state.

size_t
fifteen::hashvalue( ) const
{
	// TODO fix this
	return 0;
}
  // Construct a hash value on the state.

bool
fifteen::equals( const fifteen& other ) const
{
	// TODO a better way with hashes?
	return distance() == other.distance();
}
  // True if we are equal to other.

std::ostream& operator << ( std::ostream& stream, const fifteen& f )
{
	auto line = [&](){
		for (size_t i=0; i<f.dimension; ++i)
			stream << "+----";
		stream << "+\n";
	};

	for (size_t i =0; i<f.dimension; ++i) {
		line();
		for (size_t j =0; j<f.dimension; ++j) {
			if (i == f.open_i && j == f.open_j)
				stream << "|\033[1;31m" << std::setw(3) << f.table[i][j] << "\033[0m ";
			else
				stream << "|" << std::setw(3) << f.table[i][j] << " ";
		}
		stream << "|\n";
	}

	line();
	return stream;
}
