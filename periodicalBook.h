#ifndef PERIODICAL_BOOK_H_
#define PERIODICAL_BOOK_H_
#include <iostream>
#include "media.h"
// ---------------------------------------------------------------------------
// PeriodicalBook: The PeriodicalBook class is a subclass of the media class.
//		Periodical books have a title, year, and number of copies from the 
//		parent media class. The Periodical class also contains a month
//		for sorting the date within the library system.
// 
// Implementation and assumptions:
//	 -- It is assumed that ever Fiction book will have an author
//	 -- It is assumed that the library will only hold 5 copies 
//		of each Fiction book
// 
//For now all periodical books in the library will only have one copies
const int P_NUMBOOKS = 1;

class PeriodicalBook : public Media {
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
	string title;
	int month;
	int year;
	int copies;
};

#endif
