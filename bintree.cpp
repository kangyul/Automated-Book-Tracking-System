#include "bintree.h"

BinTree::BinTree() {
    root = nullptr;
}

BinTree::~BinTree() {
    // makeEmpty();
}

// // ---------------------------------------------------------------------------
// // makeEmpty
// // Deletes all the memory of BinTree
// // Uses makeEmptyHelper function
// void BinTree::makeEmpty() {
//     makeEmptyHelper(root);
// }

// // ---------------------------------------------------------------------------
// // makeEmptyHelper
// // Helper function of makeEmpty
// void BinTree::makeEmptyHelper(Node*& curr) {
//     if(curr == nullptr) return;
//     else {
//         makeEmptyHelper(curr->left);   // recursion to left
//         makeEmptyHelper(curr->right);  // recursion to right

//         if(curr->data != nullptr) {
//             delete curr->data;         // deletes the memory 
//             curr->data = nullptr;    
//         }

//         delete curr;  
//         curr = nullptr;                // set curr pointer to nullptr
//     }
// }

// ---------------------------------------------------------------------------
// insert
// Inserts a new node into a BinTree object
// Uses insertHelper function
bool BinTree::insert(Media* dataptr) {
    return insertHelper(root, dataptr);
}

// ---------------------------------------------------------------------------
// insertHelper
// Helper function of insert
// true is a NodeData is inserted, false if the node already exists
bool BinTree::insertHelper(Node*& curr, Media* dataptr) {

    if(curr == nullptr) {
        curr = new Node;   // creates a new node
        curr->data = dataptr; // 
        curr->left = curr->right = nullptr; // right and left child to nullptr
    } else if(*dataptr < *curr->data) {
        insertHelper(curr->left, dataptr);   // recursion to left
    } else if(*dataptr > *curr->data) {
        insertHelper(curr->right, dataptr);  // recursion to right
    } else {
        return false; // the node already exists so return false;
    }

    return true; // node is inserted to the BinTree object
}

bool BinTree::retrieve(const Media& target, Media*& dataptr) const {
    Node *temp = new Node;   // create temp Node to traverse BinTree
    temp = root;
    while(temp != nullptr) {
        if(*temp->data == target) {   // if NodeData found, return true
            dataptr = temp->data;  // copy values to dataptr
            return true;
        } else if(*temp->data < target) {  // traverse right if key is bigger
            temp = temp->right;
        } else {
            temp = temp->left;   // traverse left if key is smaller
        }
    }
    delete temp;
    return false;   // return false if it's not found 
}

// ---------------------------------------------------------------------------
// operator<<
// Displays an inorder traversal 
// The Media class is responsible for displaying its data.   
// Display one blank after the object is displayed. 
// After the traversal, do one endl. 
ostream& operator<<(ostream& stream, const BinTree& binTree) {
    binTree.inorderHelper(stream, binTree.root);
    stream << endl;
    return stream;
}

// ---------------------------------------------------------------------------
// inorderHelper
// Helper function of operator<<
void BinTree::inorderHelper(ostream& stream, Node* p) const {
    if(p != nullptr) {
        inorderHelper(stream, p->left);   // left
        (*p->data).display();      // data
        inorderHelper(stream, p->right);  // right
    }
}