#ifndef SHAPES_H
#define SHAPES_H

struct surf {
	virtual double area() const = 0;
	virtual double circumference() const = 0;
	virtual surf* clone() const & = 0;
	virtual surf* clone() && = 0;
	virtual void print(std::ostream&) const = 0;
	virtual ~surf( ) {};
};

#endif  // SHAPES_H
