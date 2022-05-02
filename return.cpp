#include "return.h"
#include "mediaContainer.h"
#include "patronList.h"
#include "mediaFactory.h"
#include "patron.h"

bool Return::execute(ifstream& infile, 
MediaContainer& mContainer, PatronList& patronList, int& patId) {
    int id;
    infile >> id;

    // if patron doesn't exist, return
    if(!patronList.findPatron(id)) {
        cout << "Patron with ID: " << id << " doesn't exist." << endl;
        return false;
    }

    patId = id;

    char code;
    infile >> code;

    Media* media = nullptr;

    MediaFactory mediaFactory;
    
    bool checker = mediaFactory.createMedia(code, media);

    if(!checker) {
        return false;
    } else {
        media->setCmdData(infile);
    }

    // retrieve media from mediaContainer
    bool findBook = mContainer.retrieve(code, media, rMedia);

    if(!findBook) {
        cout << "The returning book doesn't exist" << endl;
        return false;
    }

    // update return
    rMedia->returnMedia();

    return true;
}

void Return::display() const {
    cout << name << ' ';
    rMedia->cmdDisplay();
}

Command* Return::create() const {
    return new Return;
}