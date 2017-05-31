#include <iostream>
#include <iomanip>
#include "units.h"

// Useful if you want to compute the yield of an atomic bomb:

#if 0
quantity::energy mc2( quantity::mass m )
{
   auto C = 299792458.0_mps;   
   return m * C * C;
}
#endif 

void test_mul()
{
	auto meter = 1.0_m;
	auto second = 1.0_sec;
	auto velocity = meter/second;
	std::cout << meter << " meter per " << second << " second = " << velocity << " in meters per second" << "\n";
}

void test_main()
{
   std::cout << 9.81 * 1.0_m / ( 1.0_sec * 1.0_sec ) << "\n";
      // Acceleration on earth.

   std::cout << 1.0_m << "\n";
   std::cout << 2.0_hr << "\n";
   
   std::cout << 1000.0_watt << "\n";
}

void battery_test()
{
	std::cout << "Battery test\n";
	auto capacity = 0.800_A * 1.0_hr;
	auto voltage = 1.2_V;
	auto energy = capacity * voltage;;
	std::cout << "battry with " 
		<< capacity << " capacity and "
		<< voltage << " voltage contains "
		<< energy << " of energy when fully cahrged.\n";
	std::cout << "----------------------------------\n";
}

void car_test()
{
	std::cout << "Car test\n";
	auto vA = 100.0_kmh;
	auto rvB = 30.0_kmh;
	auto vB = vA + rvB;
	std::cout << "Car a has a velocity: " << vA
		<< " and car B has velovity: " << vB << "\n";

	std::cout << "Kineti energy of car B is "
		<< 1200.0_kg * vB*vB *0.5<< "\n";

	auto u = [](const quantity::speed& v1, const quantity::speed& v2) {
		return (v1+v2)/(1.0 + (v1*v2)/(c*c));
	};
	std::cout << "ccording to the addition law of special relativity "
		"speed of car B is: " << std::setprecision(20) << u(vA, rvB) << ".\n";
	std::cout << "----------------------------------\n";
}

void nuclear_test()
{
	std::cout << "Nuclear test\n";
	std::cout << "----------------------------------\n";
	auto tsarM = 2.3_kg;
	auto E = [](const quantity::mass& m){ return m*c*c; };
	auto tsarE = E(tsarM);
	std::cout << "Tsar Bomb is capable to release: "
		<< tsarE  << " of energy, which is equivalent to "
		<< tsarE/TNT_Epg << " of TNT has.\n";
}

int main( int argc, char* argv [ ] )
{
	std::cout << std::setprecision(20);
	test_mul();
	test_main();
	battery_test();
	car_test();
	nuclear_test();
	return 0;
}


