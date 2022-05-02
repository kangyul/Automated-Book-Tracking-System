#ifndef HISTORY_H_
#define HISTORY_H_
#include "command.h"

class Patron;

class Media;

class History : public Command {
public:

    virtual bool execute(ifstream&, MediaContainer&, PatronList&, int&);
    virtual Command* create() const;
    virtual void display() const;
};
#endif