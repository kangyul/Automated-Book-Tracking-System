#ifndef DISPLAY_MEDIA_H_
#define DISPLAY_MEDIA_H_
#include "command.h"

class DisPlayMedia : public Command {
public:

    virtual bool execute(ifstream&, MediaContainer&, PatronList&, int&);

    virtual Command* create() const;

    virtual void display() const;
};
#endif