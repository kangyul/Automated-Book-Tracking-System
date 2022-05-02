#ifndef RETURN_H_
#define RETURN_H_
#include "command.h"

class Patron;

class Media;

class Return : public Command {
public:
    virtual bool execute(ifstream&, MediaContainer&, PatronList&, int&);
    virtual Command* create() const;
    virtual void display() const;

private:
    Media* rMedia;
    string name = "Return";
};
#endif