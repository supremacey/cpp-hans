#ifndef ELEMENT_H
#define ELEMENT_H

#include <iostream>

// TODO find solution for problem of default constructor and array of objects initialization
struct element {
	std::string _name;
	size_t _age;

	element():
		_name{"No name"},
		_age{0}
	{
		std::cout << "\telement() " << this << "\n";
	}

	element(const std::string& name, size_t age):
		_name{name},
		_age{age}
	{
		std::cout << "\telement(const std::string& name, size_t age) " << this << "\n";
	}

	element(const element& el):
		_name{el._name},
		_age{el._age}
	{
		std::cout << "\telement (const element& el) " << this<< "\n";
	}

	element& operator=(const element& el)
	{
		_name = el._name;
		_age = el._age;
		std::cout << "\telement& operator=(const element& el) " << this << "\n";
		return *this;
	}

	~element()
	{
		std::cout << "\t~element() " << this << "\n";
	}

	friend std::ostream& operator<<(std::ostream& lhs, const element& rhs);
};

std::ostream& operator<<(std::ostream& lhs, const element& rhs)
{
	lhs << rhs._name << " " << rhs._age;
	return lhs;
}

#endif  // ELEMENT_H
