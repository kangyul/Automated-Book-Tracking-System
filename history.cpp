#include "history.h"
#include "mediaContainer.h"
#include "patronList.h"
#include "patron.h"

bool History::execute(ifstream& infile, 
MediaContainer& mContainer, PatronList& patronList, int& patId) {

    int id;
    infile >> id;

    // if patron doesn't exist, return
    if(!patronList.findPatron(id)) {
        cout << "Patron with ID: " << id << endl;
        return false;
    }

    Patron* pat;

    patronList.retrieve(id, pat);

    pat->displayHistory();

    return false;
}

Command* History::create() const {
    return new History;
}

void History::display() const {
    
}