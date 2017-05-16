#ifndef TREE_INCLUDED
#define TREE_INCLUDED  1

#include <iostream>
#include <vector>
#include "string.h" 

class tree;

// struct trnode should be invisible to the user of tree. This can be 
// obtained by making it a private number of tree. 
// In this exercise, we leave it like this, because it is simpler.
// In real code, trnode should be defined inside tree.


struct trnode {
   string f;
   std::vector< tree > subtrees;
   
   size_t refcnt;  // how many times I am refere to :)?
      // The reference counter: Counts how often this trnode is referred to.

   trnode( const string& f, const std::vector< tree > & subtrees, 
           size_t refcnt )
      : f{f},
        subtrees{ subtrees },
        refcnt{ refcnt }
   { }

   trnode( const string& f, std::vector< tree > && subtrees,
           size_t refcnt )
      : f{f},
        subtrees{ std::move( subtrees )}, 
        refcnt{ refcnt }
   { }

};


class tree {
   trnode* pntr;

public: 
   tree( const string& f ) 
      : pntr( new trnode( f, { }, 1 ))
   { }

   tree( const string& f, const std::vector< tree > & subtrees )   
      : pntr( new trnode( f, subtrees, 1 ))
   { } 
 
   tree( const string& f, std::vector< tree > && subtrees )
      : pntr( new trnode( f, std::move( subtrees ), 1 ))
   { }

   tree( const tree& t );
      // There is no need to write tree( tree&& t ),
      // because we cannot improve. 

   void operator = ( tree&& t );
   void operator = ( const tree& t );
 
   const string& functor( ) const;
   string& functor( );

   const tree& operator [ ] ( size_t i ) const;
   tree& operator [ ] ( size_t i );
   size_t nrsubtrees( ) const; 
   size_t getaddress() const;

   // replaces i-th subtree
   void replacesubtree(size_t i, const tree& t);
   // replaces the functor
   void replacefunctor(const string& s);

   ~tree( );

private: 
//public: 
   // Delete public, when the thing is tested:

   void ensure_not_shared( ); 

};

tree subst(tree& t, const string& var, const tree& val);

std::ostream& operator << ( std::ostream& stream, const tree& t );
   // Doesn't need to be friend, because it uses only functor( ),
   // nrsubtrees( ) and [ ].

#endif  // TREE_INCLUDED

