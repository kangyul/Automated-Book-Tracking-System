#ifndef COMMAND_H_
#define COMMAND_H_
#include <iostream>
#include <string>
#include <map>
#include "mediaFactory.h"

using namespace std;

class MediaContainer;

class PatronList;

class Command {
public:
    Command() { };
    virtual ~Command() { };

    virtual bool execute(ifstream&, MediaContainer&, PatronList&, int&) = 0;
    virtual Command* create() const = 0;
    virtual void display() const = 0;
};

#endif
