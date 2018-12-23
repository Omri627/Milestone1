#ifndef DEFINE_VAR_BIND_COMMAND
#define DEFINE_VAR_BIND_COMMAND


#include "Command.h"

class DefineVarBindCommand : public Command {
private:
    string var;
    string path;
    SymbolTable* symbolTable;
public:
    DefineVarBindCommand(string var, string path, SymbolTable* symbolTable);

    virtual int execute();
};


#endif