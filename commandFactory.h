#ifndef COMMAND_FACTORY_H_
#define COMMAND_FACTORY_H_

class Command;

class CommandFactory {
public:
    CommandFactory();
    ~CommandFactory();

    bool createCommand(char code, Command*&);

private:
    Command* commandFactory[26];

    int hash(char ch) const { return ch - 'A'; }
};

#endif