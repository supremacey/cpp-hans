#include <iostream>
#include <string>
#include <utility>
#include <memory>

#include "element.h"
#include "collection_meta_data.h"
#include "collection.h"

int
main()
{
	std::cout << "Creating 3 elemnt objects\n";
	element maciej {"Maciej Faron", 23};
	element slawek {"Sławek Biczuk", 23};
	element pawel {"Paweł Jasik", 23};

	std::cout << "Creating colleciton metadata object\n";
	collection_meta_data meta_data {"Siusiaczki", 0};

	std::cout << "Creating collection object\n";
	collection siusiaczki {meta_data};

	std::cout << "\nsiusiaczki.push_back(maciej);\n";
	siusiaczki.push_back(maciej);
	std::cout << "\nsiusiaczki.push_back(slawek);\n";
	siusiaczki.push_back(slawek);
	std::cout << "\nsiusiaczki.push_back(pawel);\n";
	siusiaczki.push_back(pawel);

	std::cout << siusiaczki;

	std::cout << "\nsiusiaczki.push_back(element{\"Karol Biczuk\", 21});\n";
	siusiaczki.push_back(element{"Karol Biczuk", 21});

	std::cout << siusiaczki;
}
