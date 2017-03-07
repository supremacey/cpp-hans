
#include "rational.h"
#include "matrix.h"

void task04() {
   rational r1{1,2};
   rational r2{1,3};
   rational r3{-2,7};
   rational r4{2,8};

   rational r5{-1,3};
   rational r6{2,7};
   rational r7{2,5};
   rational r8{-1,7};

   matrix m1 {{r1,r2},{r3,r4}};
   matrix m2 {{r5,r6},{r7,r8}};

   std::cout << m1 * m2 << "\n";
   std::cout << m1.inverse() << std::endl;
   std::cout << m1 * m1.inverse() << std::endl;
}

int main( int argc, char* argv [ ] )
{
#if 0
   rational r1( 2, 6 );
   rational r2( 4, 3 ); 
   rational r3( 5,6 );
   rational r4( 1, 2 );

   matrix m1 = { { 2, 3 }, { 4, 6 } };
   std::cout << m1 << "\n";

   matrix m2 = { { 5,4 }, { 6, rational(1,2) } }; 
   std::cout << m2 << "\n";

   matrix m3 = { { 4,5}, { -1, 2 }};

   std::cout << m1. determinant( ) << "\n";

   std::cout << m1. adjugate( ) << "\n";
   std::cout << m1. inverse( ) * m1 << "\n";
#endif
	task04();
}

