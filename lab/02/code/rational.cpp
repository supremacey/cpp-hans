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
	if (denum == 0 )
		throw std::domain_error("Division by 0 (denum is 0).");

	// if num is 0 there is nothing we have to do	
	if (num == 0) {
		denum = 1;
		return;
	}
	
	// GCD can handle the sign?
	auto _divisor = rational::gcd(num, denum);
	num = num/_divisor;	
	denum = denum/_divisor;
}

rational operator - ( rational r ) {
	r.num *= -1;
	return r;

	auto _sign = ((r.num * r.denum) < 0) ? NEGATIVE : POSITIVE;
	r.num = std::abs(r.num);
	r.denum = std::abs(r.denum);

	if ( _sign==POSITIVE )
		r.num *= -1;

	return r;
}

rational operator + ( const rational& r1, const rational& r2 ) {
	rational _result = { r1.num * r2.denum + r2.num * r1.denum , r1.denum * r2.denum};
	//_result.normalize();
	return _result;
}

rational operator - ( const rational& r1, const rational& r2 ) {
	rational _result = { r1.num * r2.denum - r2.num * r1.denum , r1.denum * r2.denum};
	//_result.normalize();
	return _result;
}

rational operator * ( const rational& r1, const rational& r2 ) {
	rational _result = {r1.num * r2.num, r1.denum * r2.denum};
	//_result.normalize();
	return _result;
}

rational operator / ( const rational& r1, const rational& r2 ) {
	rational _result = {r1.num * r2.denum, r1.denum * r2.num};
	//_result.normalize();
	return _result;
}

bool operator == ( const rational& r1, const rational& r2 ) {
	return (r1.denum == r2.denum && r1.num == r2.num);
	auto _r1 = r1;
	auto _r2 = r2;
	_r1.normalize();
	_r2.normalize();
	
	if (r1.denum == r2.denum) return r1.num == r2.num;
	if (r1.num == r2.num) return r1.denum == r2.denum;

	return false;
}

bool operator != ( const rational& r1, const rational& r2 ) {
	return !(r1 == r2);
}

std::ostream& operator << ( std::ostream& stream, const rational& r ) {
	return stream << r.num << "/" << r.denum;
}

#endif

