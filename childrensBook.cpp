#include "childrensBook.h"

void ChildrensBook::setData(ifstream& infile) {	
    infile.get(); // get (and ignore) blank before author

    getline(infile, author, ','); // input author, looks for comma terminator

    infile.get(); // get (and ignore) blank before author
    getline(infile, title, ','); // input title

    infile >> year;

    copies = C_NUMBOOKS;
}

void ChildrensBook::setCmdData(ifstream& infile) {
    infile.get();

    char copy;
    infile >> copy;

    if(copy != 'H') {
        cout << "The book is not a hardcopy." << endl;
        return;
    }

    infile.get();
    getline(infile, title, ',');

    infile.get();
    getline(infile, author, ',');
}

void ChildrensBook::display() const {
    cout << left << setw(kMaxNumBooksLength+2) << copies;
    cout << setw(kMaxAuthorLength) << author.substr(0, kMaxAuthorLength)
    << setw(kMaxTitleLength) << title.substr(0, kMaxTitleLength)
    << right << setw(kMaxYearLength) << year << endl;
}

void ChildrensBook::cmdDisplay() const {
    cout << setw(kMaxTitleLength) << title.substr(0, kMaxTitleLength)
    << setw(kMaxAuthorLength) << author.substr(0, kMaxAuthorLength)
    << right << setw(kMaxYearLength) << year << endl;
}

bool ChildrensBook::checkOut() {
    if(copies >= 1) {
        copies--;
        return true;
    }
    return false;
}

bool ChildrensBook::returnMedia() {
    if(copies >= 5) return false;
    copies++;
    return true;
}

bool ChildrensBook::operator>(const Media& media) const {

    const ChildrensBook &rhs = static_cast<const ChildrensBook&>(media);

    bool isTitle = (title == rhs.title);
    bool isAuthor = (author == rhs.author);

    return title > rhs.title
        || (isTitle && author > rhs.author)
        || (isTitle && isAuthor && year > rhs.year); 
}

Media* ChildrensBook::create() const {
    return new ChildrensBook;
}

bool ChildrensBook::operator<(const Media& media) const {
    const ChildrensBook &rhs = static_cast<const ChildrensBook&>(media);

    bool isTitle = (title == rhs.title);
    bool isAuthor = (author == rhs.author);

    return title < rhs.title
        || (isTitle && author < rhs.author)
        || (isTitle && isAuthor && year < rhs.year); 
}

bool ChildrensBook::operator==(const Media& media) const {
    const ChildrensBook &rhs = static_cast<const ChildrensBook&>(media);

    return (author == rhs.author && title == rhs.title);
}