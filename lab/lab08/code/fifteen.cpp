#include <stdexcept>
#include "fifteen.h"

fifteen::fifteen( )
{
}
  // Default constructor constructs the puzzle in solved state.

fifteen::fifteen( std::initializer_list< std::initializer_list< size_t >> init )
{
	auto szy = init.size();
	auto szx = init.begin()->size();
	if (szy != szx || szy != dimension)
		throw new std::invalid_argument("Input matrix is not NxN or N has the wrong size.");

	size_t ii, ij;
	ii = ij = 0;
	for (auto is : init) {
		for (auto num : is) {
			// TODO delete
			//std::cout << "Inserting " << num 
			//	<< " at [" << ii << "][" << ij << "]\n";
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
	return stream;
}
