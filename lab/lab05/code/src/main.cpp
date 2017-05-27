#include <iostream>
#include <functional>

#include "tree.h"
#include "string.h"

void test1()
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
}

void test2()
{
	tree t1{ string("Hello")};
	tree t2 = t1;
	std::cout << t2.functor() << "\n";
}

void test3()
{
	tree t1 {string("Hello")};
	tree t2 {string("World")};
	tree t3 {string{"Have 2"}, {t1,t2}};
	const tree& t = t3;
	for (size_t i = 0; i<t.nrsubtrees(); ++i) {
		std::cout << t[i] << std::endl;
	}
}

void test4()
{
	tree t1 {string("Hello")};
	tree t2 {string("World")};
	tree t3 {string{"Have 2"}, {t1,t2}};
	std::cout << t3 << "\n";

	tree repl {string("Goodbye"), {t2}};
	auto t4 = subst(t3, "Hello", repl);

	std::cout << t3 << "\n";
	std::cout << t4 << "\n";
}

void test5()
{
	tree t1 {string("Hello")};
	std::cout << "t1 address: " << t1.getaddress() << "\n";
	tree t2 {string("World")};
	std::cout << "t2 address: " << t2.getaddress() << "\n";

	tree t3 {string{"Have 2"}, {t1,t2}};
	std::cout << "t3 address: " << t3.getaddress() << "\n";

	tree repl {string("Goodbye"), {t2}};
	auto t4 = subst(t3, "Hello", repl);

	std::cout << "--------------------------\n";
	std::cout << t3 << "\n";
	std::cout << "t3 address: " << t3.getaddress() << "\n";
	for(size_t i =0; i<t3.nrsubtrees(); ++i)
		std::cout << "t3[" << i << "] address " << t3[i].getaddress() << "\n";

	std::cout << "--------------------------\n";
	std::cout << t4 << "\n";
	std::cout << "t4 address: " << t4.getaddress() << "\n";
	for(size_t i =0; i<t4.nrsubtrees(); ++i)
		std::cout << "t4[" << i << "] " << t4[i].functor() << " address " << t4[i].getaddress() << "\n";
}

//void tree_test()
//{
//	 auto tp = [](const tree& t){
//		std::cout << "tree: @" << t.getaddress() << "\t";
//		std::cout << t << "\n";
//	 };
//	 auto tmap = [](const tree& t, std::function<void(const tree&)> f){
//		f(t);
//		for (size_t i=0; i<t.nrsubtrees(); ++i) {
//			f(t[i]);
//		}
//	};
//
//	tree t1 {"Hello"};
//	tree t2 {"World"};
//	tree t3 {"Sentence", {t1,t2}};
//	tmap(t1, tp);
//	tmap(t2, tp);
//	tmap(t3, tp);
//	std::cout << "----------- Subst test ------------\n";
//	auto t4 = subst(t3, "Hello", {"Goodbye"});
//	tmap(t4, tp);
//}
void tp(const tree& t)
{
    std::cout << "tree: @" << t.getaddress() << "\t";
    std::cout << t << "\n";
}
void tmap(const tree& t, std::function<void(const tree&)> f)
{
    f(t);
    for (size_t i=0; i<t.nrsubtrees(); ++i) {
        if (t[i].nrsubtrees() != 0) {
            tmap(t[i],f);
        }
        else {
            f(t[i]);
        }
    }
}

void tree_test()
{
    tree t1 {"Hello"};
    tree t2 {"World"};
    tree t3 {"Sentence", {t1,t2}};
    tree t4 {"Hello", {t3}};
    tmap(t1, tp);
    tmap(t2, tp);
    tmap(t3, tp);
    tmap(t4, tp);
    std::cout << "----------- Subst test ------------\n";
    std::cout << "t = subst(t4, \"Hello\", {\"Goodbye\"})-\n";
    //auto t = subst(t4, "Hello", {"Goodbye"});
    //tmap(t, tp);
    auto t = subst(t4, "Helo", {"Goodbye"});
    tmap(t, tp);
}


int main()
{
	//test1()
	//test2();
	//test3();
	//test4();
	//test5();
	tree_test();
	std::cout << "End of program.\n";
	return(0);
}



