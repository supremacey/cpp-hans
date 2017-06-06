#ifndef SURFACE_H
#define SURFACE_H
#include "shapes.h"
#include <algorithm>

struct surface {
	surf* ref;

	surface(const surface& s);
	surface(surface&& s);

	surface(const surf& s);
	surface(surf&& s);

	void operator=(const surface& s);
	void operator=(surface&& s);

	void operator=(const surf& s);
	void operator=(surf&& s);

	~surface() { delete ref; }

	const surf& getsurf() const { return *ref; }
		// There is no non-const access, because
		// changing would be dangerous.
};

std::ostream& operator << ( std::ostream& stream, const surface& s )
{
	s.getsurf().print(stream);
	return stream;
}

surface::surface(const surface& s ) :
	ref{s.ref->clone()}
{} 
surface::surface(surface&& s ) :
	ref{std::move(*s.ref).clone()}  // couldnt just take a pointer/swap a pointer?
{}
surface::surface(const surf& s) :
	ref{s.clone()}
{} // we cannot use smart pointers to stack-created variables <- we shouldnt free them 
surface::surface(surf&& s) :
	ref{std::move(s).clone()}
{}

void
surface::operator=(const surface& s)
{
	*this = surface(s);
}
void
surface::operator=(surface&& s)
{
	std::swap(ref, s.ref);
}

void
surface::operator=(const surf& s)
{
	if (&s != ref) {
		delete ref;
		ref = s.clone();
	}
}
void
surface::operator=(surf&& s)
{
	if (&s != ref) {
		delete ref;
		ref = std::move(s).clone();
	}
}

#endif  // SURFACE_H
