#include <cmath>
#include <cassert>
#include <stdexcept>
#include "rational.h"

//#define POSITIVE true
//#define NEGATIVE false
constexpr bool NEGATIVE = true;
constexpr bool POSITIVE = false;
// Complete these methods:

#if 1 

int rational::gcd( int n1, int n2 ) {
    int a, b, r;

    if (n1 > n2 ) { a = n1; b = n2; }
    else {a = n2; b = n1;}

    while ((r = a%b) != 0) {
       a = b;
       b = r;
    }

    return b;
}

void rational::normalize( ) {
	// now this is infinity or undefined
	if (denm() == 0 )
		throw std::domain_error("Division by 0 (denum is 0).");

	// if num is 0 there is nothing we have to do	
	if (nm() == 0) {
		denm() = 1;
		return;
	}
	
	// GCD can handle the sign?
	auto _divisor = rational::gcd(nm(), denm());
	nm() = nm()/_divisor;	
	denm() = denm()/_divisor;
}

rational operator - ( rational r ) {
	r.nm() *= -1;
	return r;

	auto _sign = ((r.nm() * r.denm()) < 0) ? NEGATIVE : POSITIVE;
	r.nm() = std::abs(r.nm());
	r.denm() = std::abs(r.denm());

	if ( _sign==POSITIVE )
		r.nm() *= -1;

	return r;
}

rational operator + ( const rational& r1, const rational& r2 ) {
	rational _result = { r1.nm() * r2.denm() + r2.nm() * r1.denm() , r1.denm() * r2.denm()};
	//_result.normalize();
	return _result;
}

rational operator - ( const rational& r1, const rational& r2 ) {
	rational _result = { r1.nm() * r2.denm() - r2.nm() * r1.denm() , r1.denm() * r2.denm()};
	//_result.normalize();
	return _result;
}

rational operator * ( const rational& r1, const rational& r2 ) {
	rational _result = {r1.nm() * r2.nm(), r1.denm() * r2.denm()};
	//_result.normalize();
	return _result;
}

rational operator / ( const rational& r1, const rational& r2 ) {
	rational _result = {r1.nm() * r2.denm(), r1.denm() * r2.nm()};
	//_result.normalize();
	return _result;
}

bool operator == ( const rational& r1, const rational& r2 ) {
	return (r1.denm() == r2.denm() && r1.nm() == r2.nm());
	auto _r1 = r1;
	auto _r2 = r2;
	_r1.normalize();
	_r2.normalize();
	
	if (r1.denm() == r2.denm()) return r1.nm() == r2.nm();
	if (r1.nm() == r2.nm()) return r1.denm() == r2.denm();

	return false;
}

bool operator != ( const rational& r1, const rational& r2 ) {
	return !(r1 == r2);
}

std::ostream& operator << ( std::ostream& stream, const rational& r ) {
	return stream << r.nm() << "/" << r.denm();
}

#endif

