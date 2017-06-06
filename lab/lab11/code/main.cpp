#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

#include "shapes.h"
#include "rectangle.h"
#include "triangle.h"
#include "circle.h"
#include "surface.h"

void shapes_test();
std::ostream& operator << ( std::ostream& stream, const std::vector< surface > & table );
void print_statistics( const std::vector< surface > & table );
void handler_test();
void surface_test();

int main()
{
	std::cout << "List 11 - Inheritance\n";
	//shapes_test();
	std::cout << "--------------------------------------------------------------------------------\n";
	surface_test();
	std::cout << "--------------------------------------------------------------------------------\n";
	handler_test();
	return 0;
}

void shapes_test()
{
	auto about = [](const surf& r) {
		std::cout << "surface ("<< &r << ") ";
		r.print(std::cout);
		std::cout << " has area: " << r.area() << " and circumference: " << r.circumference() << "\n";
	};

	rectangle r {1,1,10,20};
	triangle t {0, 0, 10, 0, 0, 10};
	circle c {0,0,10};

	auto r2 = r;
	auto t2 = t;
	auto c2 = c;


	about(r);
	about(t);
	about(c);

	std::cout << "Copies\n";
	about(r2);
	about(t2);
	about(c2);
}

std::ostream& operator << ( std::ostream& stream, const std::vector< surface > & table )
{
	for( size_t i = 0; i < table. size( ); ++ i ) {
		stream << i << "-th element = " << table [i] << "\n"; 
	}
	return stream;
}

void print_statistics( const std::vector< surface > & table )
{
	double total_area = 0.0;
	double total_circumference = 0.0;

	for( const auto& s : table ) {
		std::cout << "adding info about " << s << "\n";
		total_area += s.getsurf().area();
		total_circumference += s.getsurf().circumference();
	}

	std::cout << "total area is " << total_area << "\n";
	std::cout << "total circumference is " << total_circumference << "\n";
}

void handler_test()
{
	rectangle r1 {0,0,10,10};
	rectangle r2 {10,10,5,7};
	circle c1 {};
	circle c2 {2,2,17};

	std::vector<surface> scene { triangle{0,0,10,10,5,20} };
	scene.push_back(r1);
	scene.push_back(r2);
	scene.push_back(c2);
	scene.push_back(c1);

	std::cout << "operator<< test.\n";
	std::cout << scene;
	
	std::cout << "statistics test.\n";
	print_statistics(scene);
}

void surface_test()
{
	std::cout << "Surface test.\n";
	circle c{};

	std::cout << "Creating from value\n";
	surface s1 {c};

	std::cout << "Temporary value constructor.\n";
	surface s3 {rectangle(10,10,10,10)};

	std::cout << "Asignment constructor\n";
	surface s2 = s1;

	std::cout << "Move constructor\n";
	surface s4 {std::move(s3)};

	std::cout << "Assignment operator\n";
	s1 = s4;

	std::cout << "Move operator\n";
	s2 = std::move(s4);

	std::vector<surface> scene {s1, s2};
	std::cout << scene << "\n";
}
