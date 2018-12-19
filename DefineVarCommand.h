#ifndef PROJECT_DEFINEVARCOMMAND_H
#define PROJECT_DEFINEVARCOMMAND_H
#include "Command.h"

class DefineVarCommand : public Command {
private:
    string var;
    double value;
    SymbolTable* symbolTable;
public:
    DefineVarCommand(string var, double value, SymbolTable * symbolTable);

    virtual int execute();
};


#endif //PROJECT_DEFINEVARCOMMAND_H
