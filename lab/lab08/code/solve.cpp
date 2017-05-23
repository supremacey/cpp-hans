
#include "move.h"
#include "fifteen.h" 
#include <unordered_map>
#include <queue>


// Table of states and their levels:

using leveltable = 
std::unordered_map< fifteen, unsigned int, 
                    fifteen_hash, fifteen_equals > ;


#if 0

leveltable 
solve( const fifteen& start )
{
   leveltable levels;

   std::priority_queue< fifteen, std::vector< fifteen >, 
                        fifteen_further > unchecked;

   unchecked. push( start );
   levels[ start ] = 0; 

   // We have start unexplored, at its level is zero.

   std::vector<move> moves = { move::up, move::down, move::left, move::right };
      // All possible moves in a vector.

   // As long as there is a state whose neighbours are unexplored,
   // we explore them:

   while( unchecked. size( ))
   {
      fifteen best = unchecked. top( );
      unsigned int level = levels [ best ]; 
         // The best state is the state that is closest to the
         // solution. level is the number of moves that was required
         // to reach it.
   
      std::cout << "best = " << best << "\n";
      std::cout << "distance = " << best. distance( ) << "\n";

      if( best. issolved( ))
         return levels;

      unchecked. pop( ); 

      for( auto m : moves )
      {
         fifteen next = best;
         try
         {
            next. makemove( m );
            auto p = levels. find( next );
            if( p == levels. end( ) || level + 1 < p -> second ) 
            {
               // We did not reach next before, or we reached it
               // in more steps. 

               levels[ next ] = level + 1; 
               unchecked. push( next );
            }
         }
         catch( illegalmove& m ) { /* catch and do nothing */ } 
      }
   }

   return levels;  // In move we trust.  
}

#endif

std::list< move > findpath( const leveltable& levels,
                            fifteen f, unsigned int level )
{

   std::vector<move> moves = { move::up, move::down, move::left, move::right };
      // All possible moves in a vector.

   std::list< move > path;

   return path;
}
 
// Tests --------------------------------------------------
void test1()
{
	std::cout << "---------------------------\n";
	std::cout << "Testing printing and constructors\n";
	fifteen f{ { 1, 3, 4, 12 }, 
	       { 5, 2, 7, 11 }, 
	       { 9, 6, 14, 10 }, 
	       { 13, 15, 0, 8 } } ;
	std::cout << f << "\n";

	fifteen f2 {};
	std::cout << f2 << "\n";
}

void test2()
{
	fifteen f2 {};
	fifteen f{ { 1, 3, 4, 12 }, 
	       { 5, 2, 7, 11 }, 
	       { 9, 6, 14, 10 }, 
	       { 13, 15, 0, 8 } } ;

	std::cout << "---------------------------\n";
	std::cout << "Testing equals() function\n";
	std::cout << f << "and\n" << f << "are equal? " << std::boolalpha << f.equals(f) << "\n";

	std::cout << "---------------------------\n";
	std::cout << "Testing issolved() function\n";
	std::cout << f2 << "is solved?: " << std::boolalpha << f2.issolved() << "\n";
	std::cout << f << "is solved?: " << std::boolalpha << f.issolved() << "\n";

	std::cout << "---------------------------\n";
	std::cout << "Testing distance() function\n";
	std::cout << f2 << "distance to solve is: " << f2.distance() << "\n";
	std::cout << f << "distance to solve is: " << f.distance() << "\n";
}

void test4()
{
	std::cout << "---------------------------\n";
	std::cout << "Testing position() function\n";
	auto tiles = fifteen::dimension * fifteen::dimension;
	for (size_t a = 0; a<tiles; ++a) {
		auto p = fifteen::solvedposition(a);
		std::cout << "The position of " << a << " is: [" << p.first << ", " << p.second << "]\n";
	}
}

void test5()
{
	std::cout << "---------------------------\n";
	std::cout << "Testing hashvalue() function\n";
	fifteen fd{};
	fifteen f{ { 1, 3, 4, 12 }, 
	       { 5, 2, 7, 11 }, 
	       { 9, 6, 14, 10 }, 
	       { 13, 15, 0, 8 } } ;
	std::cout << "Hash: " << f.hashvalue() << "\n" << f;
	std::cout << "Hash: " << fd.hashvalue() << "\n" << fd;
}

void test6()
{
	std::cout << "---------------------------\n";
	std::cout << "Testing makemove() function\n";
	fifteen f{ { 1, 3, 4, 12 }, 
	       { 5, 2, 7, 11 }, 
	       { 9, 6, 14, 10 }, 
	       { 13, 15, 0, 8 } } ;
	std::vector<move> moves = {move::up, move::left, move::right, move::down};
	std::cout << "Starting with\n" << f;
	for (auto& m : moves) {
		std::cout << "Making move: " << m << "\n";
		f.makemove(m);
		std::cout << f;
	}

	try {
		std::cout << "Illigal move: " << move::down << "\n";
		f.makemove(move::down);
	}
	catch (std::runtime_error ime) {
		std::cout << "catching\n";
		//std::cout << "Illegal move: " << ime << "\n";
	}
}


//void the_main()
//{
//   leveltable test;
//
//   fifteen f{ { 1, 3, 4, 12 }, 
//              { 5, 2, 7, 11 }, 
//              { 9, 6, 14, 10 }, 
//              { 13, 15, 0, 8 } } ;
//  
//
//   auto dist = solve(f);
//   for( const auto& p : dist )
//   {
//      std::cout << "---------------------------\n";
//      std::cout << p.first << " " << p. second << "\n";
//   }
//
//   auto path = findpath( dist, fifteen( ), dist[ fifteen( ) ] );
//   for( move m : path )
//      std::cout << m << "\n";
//}

int main( int argc, char* argv [] )
{
	//test1();
	//test2();
	//test4();
	//test5();
	test6();
   return 0;
}


