#ifndef COLLECTION_MD_H
#define COLLECTION_MD_H

#include "element.h"

struct collection_meta_data {
	std::string _name;
	size_t _sz;

	collection_meta_data(const std::string& name, size_t sz):
		_name{name},
		_sz{sz}
	{
		std::cout << "\tcollection_meta_data(const std::string& name, size_t sz) " << this << "\n";
	}

	collection_meta_data(const collection_meta_data& cm):
		_name{cm._name},
		_sz{cm._sz}
	{
		std::cout << "\tcollection_meta_data (const collection_meta_data& cm) " << this<< "\n";
	}

	collection_meta_data& operator=(const collection_meta_data& cm)
	{
		_name = cm._name;
		_sz = cm._sz;
		std::cout << "\tcollection_meta_data& operator=(const collection_meta_data& cm) " << this << "\n";
		return *this;
	}

	~collection_meta_data()
	{
		std::cout << "\t~collection_meta_data() " << this << "\n";
	}

	friend std::ostream& operator<<(std::ostream& lhs, const collection_meta_data& rhs);
};

std::ostream& operator<<(std::ostream& lhs, const collection_meta_data& rhs)
{
	lhs << "Collection: \"" << rhs._name << "\" of size " << rhs._sz;
	return lhs;
}

#endif  // COLLECTION_MD_H
