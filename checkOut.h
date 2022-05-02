#ifndef CHECK_OUT_H_
#define CHECK_OUT_H_
#include "command.h"

class Patron;

class Media;

class CheckOut : public Command {
public:

    virtual bool execute(ifstream&, MediaContainer&, PatronList&, int&);

    virtual Command* create() const;

    virtual void display() const;

    void setMedia(Media*);

private:
    Media* checkOutMedia;
    string name = "Check Out";
};
#endif