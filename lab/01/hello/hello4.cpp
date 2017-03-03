#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
    std::cout << "what is your name?\n";
	std::string name, surname;
	std::cin >> name >> surname;
	
	std::cout << "hello, " << name << " " << surname << "!\n";
    return 0;
}
