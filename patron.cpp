#include "patron.h"
#include "command.h"

Patron::Patron() {

}

Patron::Patron(int Id, string fName, string lName) {
    this->Id = Id;
    this->fName = fName;
    this->lName = lName;
}

Patron::~Patron() {

}

void Patron::setData(int Id, string fName, string lName) {
    this->Id = Id;
    this->fName = fName;
    this->lName = lName;
} 

void Patron::checkOut(Command* cmd) {
    history.push_back(cmd);
}

void Patron::displayHistory() const {
    cout << Id << ' ' << fName << ' ' <<lName << endl;
    for(int i = 0; i < history.size(); i++) {
        history[i]->display();
    }
}

ostream& operator<<(ostream& output, const Patron& pat) {
    output << pat.Id << ' ' << pat.fName << ' ' << pat.lName;
    return output;
}