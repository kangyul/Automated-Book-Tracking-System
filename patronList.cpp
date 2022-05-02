#include "patronList.h"

PatronList::PatronList() {

}

PatronList::~PatronList() {

}

void PatronList::display() const {

    for (auto const& x : pList) {
        cout << x.second << endl;
    }
}

void PatronList::insert(int Id, Patron pat) {
    pList.insert(pair<int, Patron>(Id, pat));
}

bool PatronList::findPatron(int id) {
    return (pList.find(id) != pList.end());
}

bool PatronList::retrieve(int id, Patron*& pat) {
    if(pList.find(id) != pList.end()) {
        pat = &pList[id];
        return true;
    }
    return false;
}