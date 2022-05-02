#ifndef PATRON_H_
#define PATRON_H_

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Command;

class Patron {
    friend ostream & operator<<(ostream &, const Patron&);
public:
    Patron();
    Patron(int, string, string);
    ~Patron();

    void setData(int id, string fName, string lName);

    void checkOut(Command*);
    void displayHistory() const;

private:
    string fName;
    string lName;
    int Id;
    vector<Command*> history;
};
#endif