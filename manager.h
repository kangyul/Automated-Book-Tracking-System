//----------------------------------------------------------------------------
// class Manager
// Implementation and assumptions:
//     -- Assume format of data file are correct
//     -- Handles the initialization of all books/media of the library
//     -- Handles the initialization of all patrons
//     -- Handles the initialziation of all book transactions
//     -- Allows to check out books for a patron
//     -- Allows to return books for a patron
//     -- Allows to display patron's transaction history
//     -- Allows to display entire library collection, sorted in categories
//----------------------------------------------------------------------------

#ifndef MANAGER_H_
#define MANAGER_H_

#include "mediaContainer.h"
#include "mediaFactory.h"
#include "patronList.h"
#include "commandFactory.h"
#include "command.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Manager {
public:
    Manager();                               // default constructor
    ~Manager();

    // checks out media for a patron
    // bool checkOutMedia(Patron&, Media&);

    // // returns a media for a patron
    // bool returnMedia(Patron&, Media&);

    // // prints the history of a patron's transaction history
    // bool displayPatronHistory(Patron&) const;

    void inputMediaFile(string file);       // initializes books of library
    void inputPatronFile(string file);     // initializes patrons
    void inputCommandFile(string file);    // initializes book transactions

private:
    MediaFactory mediaFactory;
    MediaContainer mediaContainer;
    PatronList patronList;
    CommandFactory commandFactory;
};
#endif
