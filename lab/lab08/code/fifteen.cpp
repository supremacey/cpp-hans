#include "fifteen.h"

fifteen::fifteen( )
{
}
  // Default constructor constructs the puzzle in solved state.

fifteen::fifteen( std::initializer_list< std::initializer_list< size_t >> init )
{
	auto zsy = init.size();
	auto szx = init[0].size();
	std::cout << szy << " " << szx << "\n";
}

std::ostream& operator << ( std::ostream& stream, const fifteen& f )
{
}
