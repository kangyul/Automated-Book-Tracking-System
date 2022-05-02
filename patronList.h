#ifndef PATRON_LIST_H_
#define PATRON_LIST_H_

#include <iostream>
#include <map>
#include "patron.h"

using namespace std;

class PatronList {
public:
    PatronList();
    ~PatronList();

    void display() const;

    void insert(int, Patron);

    bool findPatron(int);

    bool retrieve(int, Patron*&);

private:
    map<int, Patron> pList;
};

#endif