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
    /* variable name */
    string var;
    /* the value of variable represented in expression */
    Expression* phrase;
    /* symbol table object */
    SymbolTable* symbolTable;
    /* simulator server */
    ClientServer * server;
public:
    /**
    * the constructor creates UpdateVarCommand with the given
    * variable, phrase and symbol table.
    * @param var variable name
    * @param phrase the value of variable represented in expression
    * @param symbolTable symbol table object
    */
    UpdateVarCommand(string var, Expression *phrase, SymbolTable* symbolTable);
    /**
     * getter method of var field.
     * @return returns variable name
     */
    string getVar();
    /**
     * getter method of phrase field
     * @return return the value of variable represented in expression
     */
    Expression* getPhrase();
    /**
    * setServer method sets the server field with the given server
    * @param server simulator server
    */
    void setServer(ClientServer* server);
    /**
    * setVar method sets the variable name of given variable
    * @param variable variable name.
    */
    void setVar(string variable);
    /**
    * setPhrase sets the phrase field with given expression
    * @param expression the value of variable represented in expression
    */
    void setPhrase(Expression * expression);
    /**
    * execute method updates variable value.
    * if simulator server is connected and the variable is bound.
    * then the method updates the simulator as well.
    * @return return 1 if the operation succeed.
    * at any other case return 0
    */
    virtual int execute();
};


#endif
