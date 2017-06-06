#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "shapes.h"

struct rectangle : public surf {
	double x1, y1;  // upper left corner
	double x2, y2;  // width, height

	rectangle();
	rectangle(double, double, double);
	rectangle(double, double, double, double);
	rectangle(const rectangle&);

	rectangle& operator=(const rectangle&) = default;

	double area() const override;
	double circumference() const override;
	rectangle* clone() const & override;
	rectangle* clone() && override;
	void print( std::ostream& ) const override;

	~rectangle() = default;
};

rectangle::rectangle() : 
	x1{0}, y1{0}, x2{1}, y2{1}
{}

rectangle::rectangle(double x, double y, double side) :
	x1{x}, y1{y}, x2{side}, y2{side}
{}

rectangle::rectangle(double x, double y, double xx, double yy) :
	x1{x}, y1{y}, x2{xx}, y2{yy}
{}

rectangle::rectangle(const rectangle& r) :
	x1{r.x1}, y1{r.y1}, x2{r.x2}, y2{r.y2}
{}

//rectangle&
//rectangle::operator=(const rectangle& r)
//{
	//x1 = r.x1;
	//y1 = r.y1;
	//x2 = r.x2;
	//y2 = r.y2;
	//return (*this);
//}

inline double
rectangle::area() const
{
	return x2*y2;
}

inline double
rectangle::circumference() const
{
	return 2*x2+2*y2;
}

inline rectangle*
rectangle::clone() const &
{
	//std::cout << "rectangle::clone() const &\n";
	return new rectangle {*this};
}

inline rectangle*
rectangle::clone() &&
{
	//std::cout << "rectangle::clone() &&\n";
	return new rectangle {std::move(*this)};
}

inline void
rectangle::print(std::ostream& out) const
{
	out << "rectangle: " << x2 << "x" << y2 << " @ (" << x1 << ", " << y1 << ")";
}

#endif  // RECTANGLE_H
