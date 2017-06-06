#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "shapes.h"
#include <cmath>

struct triangle : public surf{
	double x1, y1;  // Positions of corners.
	double x2, y2;
	double x3, y3;

	triangle();
	triangle(double, double, double, double, double, double);
	triangle(const triangle&); // could be default also

	triangle& operator=(const triangle&) = default;

	double area() const override;
	double circumference() const override;
	triangle* clone() const & override;
	triangle* clone() && override;
	void print(std::ostream&) const override;
};

triangle::triangle() : 
	x1{0}, y1{0}, x2{1}, y2{0},  x3{0}, y3{1}
{}

triangle::triangle(double x, double y, double xx, double yy, double xxx, double yyy) :
	x1{x}, y1{y}, x2{xx}, y2{yy}, x3{xxx}, y3{yyy}
{}

triangle::triangle(const triangle& t) :
	x1{t.x1}, y1{t.y1}, x2{t.x2}, y2{t.y2}, x3{t.x3}, y3{t.y3}
{}

//triangle&
//triangle::operator=(const triangle& r)
//{
	//x1 = r.x1;
	//y1 = r.y1;
	//x2 = r.x2;
	//y2 = r.y2;
	//return (*this);
//}

inline double
triangle::area() const
{
	return 0.5 * fabs(x1*y2 + x2*y3 + x3*y1 - x1*y3 - x3*y2 - x2*y1);
}

inline double
triangle::circumference() const
{
	auto result = hypot(x1-x2, y1-y2);
	result += hypot(x1-x3, y1-y3);
	result += hypot(x3-x2, y3-y2);
	return result;
}

inline triangle*
triangle::clone() const &  // without it would be possible to call it on value?
{
	//std::cout << "triangle::clone() const &\n";
	return new triangle{*this};
}

inline triangle*
triangle::clone() &&
{
	//std::cout << "triangle::clone() &&\n";
	return new triangle {std::move(*this)};
}

inline void
triangle::print(std::ostream& out) const
{
	out << "triangle: @ {(" << x1 << ", " << y1 << "), ("
		<< x2 << ", " << y2 << "), ("
		<< x3 << ", " << y3 << ")}";
}

#endif  // TRIANGLE_H
