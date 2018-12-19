#ifndef DEFINE_VAR_COMMAND
    #define DEFINE_VAR_COMMAND
#include "Command.h"
#include "Expression.h"

class DefineVarCommand : public Command {
private:
    string var;
    double value;
    SymbolTable* symbolTable;
public:
    DefineVarCommand(string var, double value, SymbolTable * symbolTable);

    DefineVarCommand(string var, Expression* expression, SymbolTable * symbolTable);

    virtual int execute();
};


#endif //PROJECT_DEFINEVARCOMMAND_H
