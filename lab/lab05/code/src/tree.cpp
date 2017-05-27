#include "tree.h"

tree::tree( const tree& t )
{
   pntr = t.pntr;
   ++(pntr->refcnt); 
}

void
tree::operator=( tree&& t ) 
{
	std::swap(pntr, t.pntr);
}

void
tree::operator=( const tree& t ) 
{
	if (this != &t) {

		if ( --(pntr->refcnt)==0)
			delete pntr;

		pntr = t.pntr;
		++(pntr->refcnt); 
	}
}

tree::~tree( )
{
	if ( --(pntr->refcnt) == 0) {
		delete pntr;
	}
}

const string&
tree::functor( ) const
{
	return(pntr->f);
}

//string&
//tree::functor( )
//{
//	ensure_not_shared();
//	return(pntr->f);
//}

const tree&
tree::operator [ ] ( size_t i ) const
{
	return (pntr->subtrees.at(i));
}

//tree&
//tree::operator [ ] ( size_t i )
//{
//	ensure_not_shared();
//	return pntr->subtrees.at(i);
//}

size_t
tree::nrsubtrees( ) const 
{
	return(pntr->subtrees.size());
}

void
tree::ensure_not_shared() 
{
	if (pntr->refcnt != 1) {
		trnode *buff = new trnode(pntr->f, pntr->subtrees, 1);
		--pntr->refcnt;
		pntr = buff;
	}
}

size_t
tree::getaddress() const
{
	return reinterpret_cast<size_t>(pntr);
}

// replaces i-th subtree
void
tree::replacesubtree(size_t i, const tree& t)
{
	if (this->pntr->subtrees.at(i).pntr != t.pntr) {
		ensure_not_shared();
		pntr->subtrees.at(i) = t;
	}
}

// replaces the functor
void
tree::replacefunctor(const string& s)
{
	ensure_not_shared();
	pntr->f = s;
}

//tree
//subst(const tree& t, const string& var, const tree& val)
//{
	//if (t.nrsubtrees() == 0 && t.functor() == var) {
		//return val;
	//}
	//else {
		//auto result = t;
		//for (size_t i = 0; i<result.nrsubtrees(); ++i) {
			//result[i] = subst(result[i], var, val);
		//}
		//return result;
	//}
//}

tree
subst(const tree& t, const string& var, const tree& val)
{
    if (t.nrsubtrees() == 0) {
        if (t.functor() == var)
            return val;
        else
            return t;
    }
    else {
        auto result = t;
        for (size_t i = 0; i<t.nrsubtrees(); ++i)
            result.replacesubtree(i, subst(t[i], var, val));
        return result;
    }
}

std::ostream&
operator<<(std::ostream& stream, const tree& t)
{
	stream << "(" << t.functor() << ")->{"; 
	for (size_t i = 0; i<t.nrsubtrees(); ++i) 
		stream << " " << i << "." << t[i];

	return(stream << " }");
}
