#include <iostream>
#include "DefineVarBindCommand.h"
/**
 * constructor creates define var bind object initialized
 * with given var, path and symbol table
 * @param var variable name
 * @param path  path of given variable
 * @param symbolTable symbol object object
 */
DefineVarBindCommand::DefineVarBindCommand(string var, string path, SymbolTable* symbolTable) {
    this->var = var;
    this->path = path.substr(1, path.length() -2); // cut the apostrophes
    this->symbolTable = symbolTable;
}
/**
 * command creates new variable and
 * got the variable value from simulator server.
 * @return return 1 if this operation succeed.
 * at any other case return 0
 */
int DefineVarBindCommand::execute() {
    this->symbolTable->addVariable(this->var, 0, true);
    //add path make sure the server will update it
    this->symbolTable->addPath(this->path, this->var);
}

DefineVarBindCommand::~DefineVarBindCommand() {

}
