#include "fictionBook.h"

void FictionBook::setData(ifstream& infile) {
    infile.get(); // get (and ignore) blank before author

    getline(infile, author, ','); // input author, looks for comma terminator

    infile.get(); // get (and ignore) blank before author
    getline(infile, title, ','); // input title

    infile >> year;

    copies = F_NUMBOOKS;
}

void FictionBook::setCmdData(ifstream& infile) {
    infile.get();

    char copy;
    infile >> copy;

    if(copy != 'H') {
        cout << "The book is not a hardcopy." << endl;
        return;
    }

    infile.get();
    getline(infile, author, ',');

    infile.get();
    getline(infile, title, ',');
}

void FictionBook::display() const {
    cout << left << setw(kMaxNumBooksLength+2) << copies;
    cout << setw(kMaxAuthorLength) << author.substr(0, kMaxAuthorLength)
    << setw(kMaxTitleLength) << title.substr(0, kMaxTitleLength)
    << right << setw(kMaxYearLength) << year << endl;
}

void FictionBook::cmdDisplay() const {
    cout << setw(kMaxAuthorLength) << author.substr(0, kMaxAuthorLength)
    << setw(kMaxTitleLength) << title.substr(0, kMaxTitleLength)
    << right << setw(kMaxYearLength) << year << endl;
}

Media* FictionBook::create() const {
    return new FictionBook;
}

bool FictionBook::checkOut() {
    if(copies >= 1) {
        copies--;
        return true;
    }
    return false;
}

bool FictionBook::returnMedia() {
    if(copies >= 5) return false;
    copies++;
    return true;
}

bool FictionBook::operator>(const Media& media) const {
    const FictionBook &rhs = static_cast<const FictionBook&>(media);
    
    bool isAuthor = (author == rhs.author);
    bool isTitle = (title == rhs.title);

    return author > rhs.author
        || (isAuthor && title > rhs.title)
        || (isAuthor && isTitle && year > rhs.year);
}

bool FictionBook::operator<(const Media& media) const {
    const FictionBook &rhs = static_cast<const FictionBook&>(media);
    
    bool isAuthor = (author == rhs.author);
    bool isTitle = (title == rhs.title);

    return author < rhs.author
        || (isAuthor && title < rhs.title)
        || (isAuthor && isTitle && year < rhs.year);
}

bool FictionBook::operator==(const Media& media) const {
    const FictionBook &rhs = static_cast<const FictionBook&>(media);

    return (author == rhs.author && title == rhs.title);
}
