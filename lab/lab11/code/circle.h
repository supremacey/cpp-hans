#ifndef CIRCLE_H
#define CIRCLE_H
#include "shapes.h"

constexpr double pi = 3.141592653589793238462643383;

struct circle : public surf {
	double x; 		// Position of center.
	double y;
	double radius;

	circle();
	circle(double, double, double);
	circle(const circle&);

	circle& operator=(const circle& c) = default;

	double area() const override;
	double circumference() const override;
	circle* clone() const & override;
	circle* clone() && override;
	void print(std::ostream&) const override;
};

circle::circle() : 
	x{0}, y{0}, radius{1}
{}

circle::circle(double _x, double _y, double _radius) :
	x{_x}, y{_y}, radius{_radius}
{}

circle::circle(const circle& c) :
	x{c.x}, y{c.y}, radius{c.radius}
{}

//circle&
//circle::operator=(const circle& c)
//{
	//x = c.x;
	//y = c.y;
	//radius = c.radius;
	//return (*this);
//}

inline double
circle::area() const
{
	return pi*radius*radius;
}

inline double
circle::circumference() const
{
	return 2*pi*radius;
}

// TODO fix those
inline circle*
circle::clone() const &
{
	//std::cout << "circle::clone() const &\n";
	return new circle{*this};
}
// TODO fix those
inline circle*
circle::clone() &&
{
	//std::cout << "circle::clone() &&\n";
	return new circle {std::move(*this)};
}

inline void
circle::print(std::ostream& out) const
{
	out << "circe: r " << radius << " @ (" << x << ", " << y << ")";
}

#endif  // CIRCLE_H
