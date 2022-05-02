#include "manager.h"

Manager::Manager() {

}

Manager::~Manager() {
    
}

void Manager::inputMediaFile(string file) {

    ifstream infile(file);

    for(;;) {
        
        char code;
        infile >> code;

        if(infile.eof()) break;

        Media* media = nullptr;

        bool checker = mediaFactory.createMedia(code, media);

        string trash = "";

        if(!checker) {
            getline(infile, trash);
        } else {
            media->setData(infile);
            
            mediaContainer.insert(code, media);
        }
    }
}

void Manager::inputPatronFile(string file) {

    ifstream infile(file);

    for(;;) {
        string tempId;
        int Id;
        string firstName;
        string lastName;

        getline(infile, tempId, ' ');
        getline(infile, firstName, ' ');
        getline(infile, lastName);

        if(infile.eof()) break;

        Id = stoi(tempId);

        Patron inputPatron(Id, firstName, lastName);

        patronList.insert(Id, inputPatron);
    }
}

void Manager::inputCommandFile(string file) {

    ifstream infile(file);

    for(;;) {

        char code;
        infile >> code;

        if(infile.eof()) break;

        Command* command = nullptr;

        bool checker = commandFactory.createCommand(code, command);

        string trash = "";

        if(!checker) {
            getline(infile, trash);
        } else {
            int patId;
            bool cmdCheck = command->execute(infile, mediaContainer, patronList, patId);

            if(cmdCheck) {
                Patron* pat;

                patronList.retrieve(patId, pat);

                pat->checkOut(command);
            } else {
                getline(infile, trash);
            }
        }

    } 

}