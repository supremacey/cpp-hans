#include <stdexcept>
#include <iostream>

int main() {
	try
	{
		throw std::out_of_range("Beep-boopa.");
	}
	catch (std::out_of_range e)
	{
		std::cout << "Sorry, you have got a runtime error.\n";
		std::cout << e.what();
		throw e;
	}
	return 0;
}
