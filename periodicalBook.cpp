#include "periodicalBook.h"

void PeriodicalBook::setData(ifstream& infile) {
    infile.get(); // get (and ignore) blank before author

    getline(infile, title, ','); // input author, looks for comma terminator

    infile.get(); // get (and ignore) blank before author
    infile >> month; // input title

    infile >> year;

    copies = P_NUMBOOKS;
}	

void PeriodicalBook::setCmdData(ifstream& infile) {
    infile.get();

    char copy;
    infile >> copy;

    if(copy != 'H') {
        cout << "The book is not a hardcopy." << endl;
        return;
    }

    infile.get();
    infile >> year;

    infile.get();
    infile >> month;

    infile.get();
    getline(infile, title, ',');
}

void PeriodicalBook::display() const {
    cout << left << setw(kMaxNumBooksLength+2) << copies;
    cout << setw(kMaxTitleLength) << title.substr(0, kMaxTitleLength)
    << right << setw(kMaxYearLength) << year 
    << setw(kMaxMonthLength) << month << endl;
}

void PeriodicalBook::cmdDisplay() const {
    cout << setw(kMaxTitleLength) << title.substr(0, kMaxTitleLength)
    << right << setw(kMaxYearLength) << year 
    << setw(kMaxMonthLength) << month << endl;
}

Media* PeriodicalBook::create() const {
    return new PeriodicalBook;
}

bool PeriodicalBook::checkOut() {
    if(copies >= 1) {
        copies--;
        return true;
    }
    return false;
}

bool PeriodicalBook::returnMedia() {
    if(copies >= 1) return false;
    copies++;
    return true;
}

bool PeriodicalBook::operator>(const Media& media) const {
    const PeriodicalBook &rhs = static_cast<const PeriodicalBook&>(media);

    bool isYear = (year == rhs.year);
    bool isMonth = (month == rhs.month);

    return year > rhs.year
        || (isYear && month > rhs.month)
        || (isMonth && isMonth && title > rhs.title);
}

bool PeriodicalBook::operator<(const Media& media) const {
    const PeriodicalBook &rhs = static_cast<const PeriodicalBook&>(media);

    bool isYear = (year == rhs.year);
    bool isMonth = (month == rhs.month);

    return year < rhs.year
        || (isYear && month < rhs.month)
        || (isMonth && isMonth && title < rhs.title);
}

bool PeriodicalBook::operator==(const Media& media) const {
    const PeriodicalBook &rhs = static_cast<const PeriodicalBook&>(media);

    return (title == rhs.title && month == rhs.month && year == rhs.year);
}