//
// Created by ranraboh on 16/12/18.
//

#ifndef PROJECT_DEFINEVARCOMMAND_H
#define PROJECT_DEFINEVARCOMMAND_H


#include "Var.h"
#include "Command.h"
#include "ClientServer.h"

class UpdateVarCommand : public Command {
private:
    string var;
    Expression* phrase;
    SymbolTable* symbolTable;
    ClientServer * server;
public:
    UpdateVarCommand(string var, Expression *phrase, SymbolTable* symbolTable);

    string getVar();

    Expression* getPhrase();

    void setServer(ClientServer* server);

    void setVar(string variable);

    void setPhrase(Expression * expression);

    virtual int execute();
};


#endif //PROJECT_DEFINEVARCOMMAND_H
