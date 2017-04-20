#include <iostream>

namespace mmf {
	class string {
	private:
		char * data;
		std::size_t sz;
		std::size_t cap;
	public:
		string(): data{nullptr}, sz{0}, cap{0}
		{
			std::cout <<"\tC()\n";
		}

		string(const string& rhs):
			data{new char[rhs.cap]},
			sz{rhs.sz},
			cap{rhs.cap}
		{
			std::copy(rhs.data, (rhs.data + rhs.sz), data);
			std::cout << "\tCC(const lval&)\n";
		}
		
		string(string&& rhs):
			data{rhs.data},
			sz{rhs.sz},
			cap{rhs.cap}
		{
			rhs.data = nullptr;
			rhs.sz = 0;
			rhs.cap = 0;
			std::cout << "\tCC(&&)\n";
		}

		~string()
		{
			delete[] data;
			sz = 0;
			std::cout << "\t~()\n";
		}

		void push(char c)
		{
			if (cap == sz) {
				char *buff = new char[cap*2 + 1];
				std::copy(data, (data+ sz), buff);
				delete[] data;
				data = buff;
				cap = cap*2+1;
			}
			data[sz++] = c;
		}

		string operator+(char c)
		{
			push(c);
			return(*this);
		}

		string operator+(const string& rhs)
		{
			string result;
			result.data = new char[cap + rhs.cap];
			result.sz = sz + rhs.sz;
			result.cap = cap + rhs.cap;
			std::copy(data, (data + sz), result.data);
			std::copy(rhs.data, (rhs.data + rhs.sz), (result.data + sz));
			return(result);
		}

		string& operator+=(char c)
		{
			push(c);
			return(*this);
		}
		
		friend std::ostream& operator<<(std::ostream& lhs, const string& rhs);
	};
	std::ostream& operator<<(std::ostream& lhs, const string& rhs)
	{
		for(size_t i = 0; i < rhs.sz; ++i)
			lhs << rhs.data[i];
		return lhs;
	}

	class person {
	private:
		string name;
		string surname;
	public:
		person(): name{}, surname{}
		{
			std::cout << "\t person()\n";
		}

		person(const string& lhs, const string& rhs):
			name{lhs},  // CC for string will be called twice
			surname{rhs}
		{
			std::cout << "\t person(const string&, const string&)\n";
		}

		person(string&& lhs, string&& rhs):
			name{ std::forward<string&&>(lhs) },  // move CC for string will be called twice
			surname{ std::move(rhs) }
		{
			std::cout << "\t person(string&&, string&&)\n";
		}

		person(person&& rhs):
			name{ std::move(rhs.name) },
			surname{ std::move(rhs.surname) }
		{
			std::cout << "\t person(&&)\n";
		}

		person(const person& rhs):
			name{rhs.name},
			surname{rhs.surname}
		{
			std::cout << "\t person(const &)\n";
		}

		~person() 
		{
			std::cout << "\t ~person()\n";
		}
		
		friend std::ostream& operator<<(std::ostream& lhs, const person& rhs);
	};
	std::ostream& operator<<(std::ostream& lhs, const person& rhs)
	{
		return lhs << rhs.name << " " << rhs.surname;
	}

}

int main(int argc, char **argv)
{

	mmf::string name, surname;

	for (auto letter : "Maciej")
		name += letter;

	for (auto letter : "Faron")
		surname += letter;

	std::cout << "name: " << name << " surname: " << surname << "\n";

	mmf::person maciej{std::move(name), std::move(surname)};

	std::cout << "name: " << name << " surname: " << surname << "\n";
	std::cout << maciej << "\n";

	mmf::person pawel = std::move(maciej);

	std::cout << "maciej: " << maciej << "\n";
	std::cout << "pawel: " << pawel << "\n";



	return(0);
}
