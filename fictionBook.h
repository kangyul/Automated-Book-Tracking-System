#ifndef FICTION_BOOK_H_
#define FICTION_BOOK_H_
#include <iostream>
#include "media.h"

// ---------------------------------------------------------------------------
// FictionBook: The FictionBook class is a subclass of the media class.
//		Fiction books have a title, year, and number of copies from the 
//		parent media class. Fiction book's also contains a author
//		for sorting the date within the library system.
// 
// 
// Implementation and assumptions:
//	 -- It is assumed that ever Fiction book will have an author
//	 -- It is assumed that the library will only hold 5 copies 
//		of each Fiction book
// 
// 
//For now all fiction books in the library will have five copies
const int F_NUMBOOKS = 5;

class FictionBook : public Media {

public:
	/*Overiden create function which creates a new ChildrensBook and 
	returns it as a pointer */
	virtual void setData(ifstream&);
	virtual void setCmdData(ifstream&);
	virtual void display() const;
	virtual void cmdDisplay() const;
	
	virtual Media* create() const;
	virtual bool checkOut();
	virtual bool returnMedia();

	virtual bool operator>(const Media&) const;
	virtual bool operator<(const Media&) const;
	virtual bool operator==(const Media&) const;

private:
	string author;
	string title;
	int year;
	int copies;
};

#endif
