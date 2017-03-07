#include <cmath>
#include <stdexcept>
#include "rational.h"

#define POSITIVE 0
#define NEGATIVE 1
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
	if (num == 0)
		return;

	// how sign is preserved
	auto _sign = POSITIVE;
	if ((num * denum) > 0) 
		_sign = POSITIVE;
	else 
		_sign = NEGATIVE;

	num = std::abs(num);
	denum = std::abs(denum);

	auto _divisor = rational::gcd(num, denum);
	num /= _divisor;
	denum /= _divisor;

	// restore of sign
	if (_sign == NEGATIVE)
		num *= -1;
}

rational operator - ( rational r ) {
	auto _sign = ((r.num * r.denum) < 0) ? NEGATIVE : POSITIVE;
	r.num = std::abs(r.num);
	r.denum = std::abs(r.denum);

	if ( _sign==POSITIVE )
		r.num *= -1;

	return r;
}

rational operator + ( const rational& r1, const rational& r2 ) {
	rational _result = { r1.num * r2.denum + r2.num * r1.denum , r1.denum * r2.denum};
	_result.normalize();
	return _result;
}

rational operator - ( const rational& r1, const rational& r2 ) {
	rational _result = { r1.num * r2.denum - r2.num * r1.denum , r1.denum * r2.denum};
	_result.normalize();
	return _result;
}

rational operator * ( const rational& r1, const rational& r2 ) {
	return rational{r1.num * r2.num, r1.denum * r2.denum};
}

rational operator / ( const rational& r1, const rational& r2 ) {
	return rational{r1.num * r2.denum, r1.denum * r2.num};
}

bool operator == ( const rational& r1, const rational& r2 ) {
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
	stream << r.num << "/" << r.denum;
	return stream;
}

#endif

