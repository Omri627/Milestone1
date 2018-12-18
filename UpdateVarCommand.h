//
// Created by ranraboh on 16/12/18.
//

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
    UpdateVarCommand(string var, Expression *phrase, SymbolTable* symbolTable);

    virtual int execute();
};


#endif //PROJECT_DEFINEVARCOMMAND_H
