#include "displayMedia.h"
#include "mediaContainer.h"
#include "patronList.h"

bool DisPlayMedia::execute(ifstream& infile, 
MediaContainer& mContainer, PatronList& pList, int& patId) {

    mContainer.display();

    return false;
}

Command* DisPlayMedia::create() const {
    return new DisPlayMedia;
}

void DisPlayMedia::display() const {
    
}