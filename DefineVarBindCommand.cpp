#include <iostream>
#include "DefineVarBindCommand.h"

DefineVarBindCommand::DefineVarBindCommand(string var, string path, SymbolTable* symbolTable) {
    this->var = var;
    this->path = path;
    this->symbolTable = symbolTable;
}

int DefineVarBindCommand::execute() {
    this->symbolTable->addVariable(this->var, 1, true);
    //add path make sure the server will update it
    this->symbolTable->addPath(this->path, this->var);


}
