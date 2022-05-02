#ifndef MEDIA_CONTAINER_H_
#define MEDIA_CONTAINER_H_

#include <iostream>
#include "bintree.h"
// ---------------------------------------------------------------------------
// Media: The MediaContainer class is a container for media that allows for
//		  inserting, removing, and retrieving media from the container. All
//		  The media in the container can be displayed with the display method.
// 
// Implementation and assumptions:
//	 -- When creating a MediaContainer you must give two strings which
//		represent the two methods that will be used to sort the media in the 
//		container. For example if you want to sort by author then title
//		it would look like ("Author", "Title")
//	 -- It is assumed that the search method for different types of media will
//		not change. This means that if you currently are searching for 
//		fiction books by title then author, this can't be changed.

class Media;

class MediaContainer {
public:
	//will initialize the BSTree with the sorting methods that will be used.
	MediaContainer();

	//Calls destructor for the Binary Search Tree
	~MediaContainer();

	//displays the contents of the container, including all media in it.
	void display() const;
	
	/*inserts the pointer to the media object in the search tree which will
	sort based on the sorting methods that were given in the constructor.*/
	bool insert(char code, Media*);

	/*Retrieves and updates a pointer to the media in the container*/
	bool retrieve(char, Media*, Media*&) const;
private:
	/* Binary search tree that would sort by two methods passed 
	to it from the constructor, for example the tree could sort by author 
	and then if two media objects have the same author, then it would sort
	based on the title of the book.*/

	BinTree container[26];

	int hash(char ch) const { return ch - 'A'; }
};
#endif
