#include "mediaContainer.h"

MediaContainer::MediaContainer() {
    
}

MediaContainer::~MediaContainer() {

}

bool MediaContainer::insert(char code, Media* media) {

    if(hash(code) < 0 || hash(code) > 25) return false;
    
    container[hash(code)].insert(media);
    
    return true;
}

bool MediaContainer::retrieve(char code, Media* target, Media*& dataptr) const  {
    return container[hash(code)].retrieve(*target, dataptr);
}

void MediaContainer::display() const {
    cout << "------ Childrens Books -------" << endl;
    cout << container[hash('C')];

    cout << "------ Fiction Books -------" << endl;
    cout << container[hash('F')];

    cout << "------ Periodical Books -------" << endl;
    cout << container[hash('P')];
}