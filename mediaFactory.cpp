#include "mediaFactory.h"
#include "childrensBook.h"
#include "fictionBook.h"
#include "periodicalBook.h"
#include "media.h"

MediaFactory::MediaFactory() {
    for(int i = 0; i < 26; i++) {
        mediaFactory[i] = nullptr;
    }
    mediaFactory[hash('C')] = new ChildrensBook;
    mediaFactory[hash('F')] = new FictionBook;
    mediaFactory[hash('P')] = new PeriodicalBook;
}

MediaFactory::~MediaFactory() {
    for(int i = 0; i < 26; i++) {
        delete mediaFactory[i];
        mediaFactory[i] = nullptr;
    }
}

bool MediaFactory::createMedia(char code, Media*& media) {

    if(hash(code) < 0 || hash(code) > 25) return false;

    if(mediaFactory[hash(code)] == nullptr) return false;

    media = mediaFactory[hash(code)]->create();

    return true;
}
