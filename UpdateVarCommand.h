#ifndef PROJECT_DEFINEVARCOMMAND_H
#define PROJECT_DEFINEVARCOMMAND_H

#include "Var.h"
#include "Command.h"

class UpdateVarCommand : public Command {
private:
    string var;
    Expression* phrase;
    SymbolTable* symbolTable;

public:
    /**
    * constructor
    * @param var: the name of the var to update
    * @param phrase: the expression to update the var
    * @param symbolTable: pointer to symbolTable to update the var
    */
    UpdateVarCommand(string var, Expression *phrase, SymbolTable* symbolTable);

    /**
    * execute the command
    * @return 1 if successful
    */
    virtual int execute();
};


#endif //PROJECT_DEFINEVARCOMMAND_H
