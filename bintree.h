
////////////////////////////////  bintree.h file  ////////////////////////////

#ifndef BINTREE_H
#define BINTREE_H
#include <iostream>
#include "media.h"
using namespace std;

//---------------------------------------------------------------------------
// BinTree class:  Creates a binary search tree called BinTree 
//   also includes additional features:
//   -- allows to empty the BinTree object
//   -- allows to check the BinTree object if it's empty or not
//   -- allows assignment and comparison operators
//   -- allows insert and retrieve from the BinTree object
//   -- getSibling and getParent methods 
//   -- bstreeToArray and arrayToBSTree
//
// Implementation and assumptions:
//   -- all data is assumed to be correct
//   -- all of the BinTree objects are assumed to be 100 Nodes or less
//   -- default constructor intialize root node as nullptr
//   -- user must enter valid integers when using >>
//   -- in <<, displays as an inorder traversal 
//---------------------------------------------------------------------------

class BinTree {
    // overloaded operator<<
    friend ostream& operator<<(ostream&, const BinTree&);
public:
    // Constructors and Destructor
    BinTree();                          // default constructor
    ~BinTree();                         // destructor

    void makeEmpty();           // empty the tree

    // Inserts NodeData to a BST
    bool insert(Media*);

    // Searches a BST for a Media parameter
    bool retrieve(const Media&, Media*&) const;

private:
    struct Node { 
        Media* data;                        // pointer to data object  
        Node* left;                            // left subtree pointer  
        Node* right;                           // right subtree pointer  
    }; 
    Node* root;                                // root of the BST

    // Helper function of makeEmpty
    void makeEmptyHelper(Node*&);

    // Helper function of operator<<
    void inorderHelper(ostream&, Node*) const;

    // Helper function of insert
    bool insertHelper(Node*&, Media*);
};
#endif