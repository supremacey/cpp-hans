#include "tree.h"

tree::tree( const tree& t )
{
   //std::cout << "\tCC(const tree&) " << t.functor() << " \n" ;
   pntr = t.pntr;
   if (pntr != nullptr)
	   ++(pntr->refcnt); 
}

void
tree::operator=( tree&& t ) 
{
	//std::cout << "\t=(tree&&)\n";
	
	if (pntr != nullptr)
		if ( --(pntr->refcnt)==0)
			delete pntr;

	pntr = t.pntr;
	t.pntr = nullptr;
}

void
tree::operator=( const tree& t ) 
{
	if (this != &t) {
		//std::cout << "\t=(const tree&)\n";

		if (pntr != nullptr)
			if ( --(pntr->refcnt)==0)
				delete pntr;

		pntr = t.pntr;
		++(pntr->refcnt); 
		std::cout << "\tOK\n";
	}
}

tree::~tree( )
{
	if (pntr != nullptr) {
		string tmp = functor();
		//std::cout << "\t~D(1/3) " << tmp
			//<< " " << (pntr->refcnt) << "\n";

		if ( --(pntr->refcnt) == 0) {
			//std::cout << "\t\t~D(2/3) " << tmp
				//<< " " << (pntr->refcnt) << "\n";

			delete pntr;
		}

		//std::cout << "\t\t\t~D(3/3) " << tmp
			//<< " " << (pntr->refcnt) << "\n";
	}
}

const string&
tree::functor( ) const
{
	return(pntr->f);
}

string&
tree::functor( )
{
	ensure_not_shared();
	return(pntr->f);
}

const tree&
tree::operator [ ] ( size_t i ) const
{
{
	// TODO fix this
	return (pntr->subtrees.at(i));
}

tree&
tree::operator [ ] ( size_t i )
{
{
	// TODO fix this
	ensure_not_shared();
	tree& result = pntr->subtrees.at(i);
	result.ensure_not_shared();
	return (result);
}

size_t
tree::nrsubtrees( ) const 
{
	// TODO fix this
	return(pntr->subtrees.size());
}

void
tree::ensure_not_shared() 
{
	if (pntr != nullptr)
		if (pntr->refcnt != 1) {
			trnode *buff = new trnode(pntr->f, pntr->subtrees, 1);
			--pntr->refcnt;
			pntr = buff;
		}
}

std::ostream&
operator<<(std::ostream& stream, const tree& t)
{
	stream << "(" << t.functor() << ")->{"; 
	for (
			size_t i = 1, sbtrees = t.nrsubtrees() + 1;
			i<sbtrees;
			++i
		) 
		stream << " " << i << "." << t[i];

	return(stream << " }");
}
