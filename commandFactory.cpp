#include "commandFactory.h"
#include "command.h"
#include "checkOut.h"
#include "return.h"
#include "displayMedia.h"
#include "history.h"

CommandFactory::CommandFactory() {
    for(int i = 0; i < 26; i++) {
        commandFactory[i] = nullptr;
    }
    commandFactory[hash('C')] = new CheckOut;
    commandFactory[hash('D')] = new DisPlayMedia;
    commandFactory[hash('H')] = new History;
    commandFactory[hash('R')] = new Return;
}

CommandFactory::~CommandFactory() {
    for(int i = 0; i < 26; i++) {
        delete commandFactory[i];
        commandFactory[i] = nullptr;
    }
}

bool CommandFactory::createCommand(char code, Command*& cmd) {

    if(hash(code) < 0 || hash(code) > 25) return false;

    if(commandFactory[hash(code)] == nullptr) return false;

    cmd = commandFactory[hash(code)]->create();

    return true;
}