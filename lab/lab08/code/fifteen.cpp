#include <iomanip>
#include <stdexcept>
#include "fifteen.h"

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

	size_t ii, ij;
	ii = ij = 0;
	for (auto is : init) {
		for (auto num : is) {
			table[ii][ij] = num;
			if (num == 0) {
				open_i = ii;
				open_j = ij;
			}
			++ij;	
		}
		ij = 0;
		++ii;
	}
}

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
