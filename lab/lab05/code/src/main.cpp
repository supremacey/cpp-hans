#include <iostream>

#include "tree.h"
#include "string.h"


int main()
{
	std::cout << "creating tree a\n";
	tree t1( string( "a" ));
	std::cout << t1 << "\n";

	std::cout << "creating tree b\n";
	tree t2( string( "b" )); 
	std::cout << t2 << "\n";

	std::cout << "creating tree f\n";
	tree t3 = tree( string( "f" ), { t1, t2 } ); 
	std::cout << t3 << "\n";

	std::cout << "creating vector< tree > arguments\n";
	std::vector< tree > arguments = { t1, t2, t3 };
	std::cout << "creating tree F\n";
	std::cout << tree( "F", std::move( arguments )) << "\n";

	std::cout << "assignment t2=t3\n";
	t2 = t3;
	std::cout << "move t2=move(t3)\n";
	t2 = std::move(t3);

	std::cout << "End of programme\n";
	return(0);
}



