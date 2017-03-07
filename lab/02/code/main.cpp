#include <cassert>
#include "rational.h"
#include "matrix.h"

void task04and05() {
   rational r1{1,2};
   rational r2{1,3};
   rational r3{-2,7};
   rational r4{2,8};

   rational r5{-1,3};
   rational r6{2,7};
   rational r7{2,5};
   rational r8{-1,7};

   //------------------------- task 04 -----------------------
   matrix m1 {{r1,r3},{r2,r4}};
   matrix m2 {{r5,r7},{r6,r8}};

   std::cout << m1 * m2 << "\n";
   std::cout << m1.inverse() << std::endl;
   //------------------------- task 04 -----------------------
   //
   //------------------------- task 05 -----------------------
   matrix m3 = {{r2,r4},{r6,r8}};
   vector v1 = {r1,r2};

   std::cout << "Matrix multiplication is asociative\n";
   std::cout << (m1*m2)*m3 <<"\n"<< m1*(m2*m3) << "\n";

   //std::cout << "Matrix multiplication with addition is distributive\n";
   //std::cout << ((m1+m2)*m3 - (m1*m3 + m2*m3)) << "\n";

   //std::cout << "Matrix multiplicaiton coresponds to composition of application\n";
   //std::cout << (m1(m2(v1)) - (m1*m2)(v1))<< "\n";

   //std::cout << "Detrminant commutes over multiplication\n";
   //std::cout << ((m1.determinant() * m2.determinant()) - (m1*m2).determinant()) << "\n";

   //std::cout << "Inverse is indeed inverse\n";
   //std::cout << m1 * m1.inverse() << std::endl;
   ////------------------------- task 05 -----------------------
}

//void test(){
//	int x = -25;
//	int y = 25;
//	for (float a=x; a<y; ++a)
//		for (float b=x; b<y; ++b)
//			for (float c=x; c<y; ++c)
//				for (float d=x; d<y; ++d)
//					if (b!=0 && d!=0 && c!=0) {
//						assert ((((rational){a,b} + (rational){c,d}).vl()-(a/b+c/d)) < 0.001);
//						assert ((((rational){a,b} - (rational){c,d}).vl()-(a/b-c/d)) < 0.001);
//						assert ((((rational){a,b} / (rational){c,d}).vl()-((a/b) / (c/d))) < 0.001);
//						assert ((((rational){a,b} * (rational){c,d}).vl()-((a/b) * (c/d))) < 0.001);
//					}
//}

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
	task04and05();
//	test();
}

