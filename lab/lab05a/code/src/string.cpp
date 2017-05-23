#include <stdexcept>
#include "string.h"

char
string::operator[](size_t i) const
{
	if (i < len)
		return p[i];
	else throw std::out_of_range("char string::operator[]");
}
char&
string::operator[](size_t i)
{
	if (i < len)
		return p[i];
	else throw std::out_of_range("char string::operator[]");
}
void
string::operator+=(char c)
{
	// allocating the len + 1 and increasing len att the same time
	char *buff = new char[++len];
	std::copy(p, (p+(len-1)), buff);
	buff[len-1] = c;
	delete [] p;
	p = buff;
}
void
string::operator+=(const string& s)
{
	char *buff = new char[len + s.len];
	std::copy(p, (p+len), buff);
	std::copy(s.p, (s.p+s.len), (buff+len));
	delete [] p;
	len += s.len;
	p = buff;
}
string
operator+(const string& s1, const string& s2)
{
	string result{s1};
	result += s2;
	return result;
}

#if 1
// Remove the #if, when you have finished operator[]:

std::ostream& operator << ( std::ostream& out, const string& s )
{
	for (auto& c : s)
		out << c;
   //for( size_t i = 0; i < s.size( ); ++ i )
      //out << s[i];
   return out; 
}

#endif

bool
operator == ( const string& s1, const string& s2 ) 
{
	if (s1.size() == s2.size()) {
		for (size_t i = 0; i<s1.size(); ++i)
			if (s1[i] != s2[i])
				return false;

		return true;
	}
	return false;
}
bool
operator != ( const string& s1, const string& s2 )
{
	return !(s1 == s2);
}
bool
operator < ( const string& s1, const string& s2 )
{
	size_t l = std::min(s1.size(), s2.size());

	for (size_t i = 0; i<l; ++i)
		if (s1[i] != s2[i])
			return s1[i] < s2[i];
	
	return s1.size() < s2.size();
}
bool
operator > ( const string& s1, const string& s2 )
{
	return !(s2 < s1) && (s1.size() > s2.size());
}
bool
operator <= ( const string& s1, const string& s2 )
{
	return !(s1 > s2);  // OK
}
bool
operator >= ( const string& s1, const string& s2 )
{
	return !(s1 < s2); // OK
}



