#ifndef MEDIA_H_
#define MEDIA_H_
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

// ---------------------------------------------------------------------------
// Media: The Media class is a base class for media items that would be stored
//		  in a library's system. Media could be types of books, media, etc.
//		  Every media that is stored in the library will have a number of 
//		  copies, a year of publishing, and a title.
// 
// Implementation and assumptions:
//	 -- It is assumed that ever media will have a title and year of publishing
//	 -- This class can be used as a base class for any new media types that 
//		the library would like to hold.
//	 -- When a patron checks out some form of media, they will recieve a copy 
//		of the media object.

const int kMaxNumBooksLength = 7;
const int kMaxAuthorLength = 24;
const int kMaxTitleLength = 37;
const int kMaxYearLength = 10;
const int kMaxMonthLength = 10;

class Media {
public:

	Media() { };
	virtual ~Media() { };

	/*overwritten by all media subclassesand will return a pointer to
	a new media subclass object that is created*/
	virtual void setData(ifstream&) = 0; 
	virtual void setCmdData(ifstream&) = 0;
	virtual void display() const = 0;
	virtual void cmdDisplay() const = 0;
	
	virtual Media* create() const = 0;
	virtual bool checkOut() = 0;
	virtual bool returnMedia() = 0;

	virtual bool operator>(const Media&) const = 0;
	virtual bool operator<(const Media&) const = 0;
	virtual bool operator==(const Media&) const = 0;
};

#endif
