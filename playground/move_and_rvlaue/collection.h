#ifndef COLLECTION_H
#define COLLECTION_H

#include <iostream>
#include "element.h"
#include "collection_meta_data.h"

struct collection {
	collection_meta_data _meta_data;
	element* _elms;
	size_t _capacity;

	collection(const std::string& name):
		_meta_data{name, 0},
		_elms{new element[1]},
		_capacity{1}
	{
		std::cout << "\tcollection(std::string name) " << this << "\n";
	}

	collection(const collection_meta_data& meta_data):
		_meta_data{meta_data},
		_elms{new element[meta_data._sz*2+1]},
		_capacity{meta_data._sz*2+1}
	{
		std::cout << "\tcollection(const collection_meta_data& meta_data) " << this << "\n";
	}

	collection(const collection& col):
		_meta_data{col._meta_data},
		_elms{new element[col._capacity]},
		_capacity{col._capacity}
	{
		std::copy(col._elms, (col._elms + col._meta_data._sz), _elms);
		std::cout << "\tcollection(const collection& col) " << this << "\n";
	}

	~collection()
	{
		delete [] _elms;	
		std::cout << "\t~collection() " << this << "\n";
	}

	void push_back(const element& elem)
	{
		if (_meta_data._sz == _capacity) {
			_capacity *= 2;
			element* buff = new element[_capacity];
			std::copy(_elms, (_elms + _meta_data._sz), buff);
			delete [] _elms;
			_elms = buff;
		}
		_elms[_meta_data._sz++] = elem; // copy constructor call here
	}

	friend std::ostream& operator<<(std::ostream& lhs, const collection& rhs);
};

std::ostream& operator<<(std::ostream& lhs, const collection& rhs)
{
	lhs << rhs._meta_data << " with elements:\n{\n";
	for (size_t i = 0; i<rhs._meta_data._sz; ++i)
		lhs << "\t" << rhs._elms[i] << "\n";
	lhs << "}\n";
	return lhs;
}

#endif  // COLLECTION_H
