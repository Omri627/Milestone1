#include <iostream>
#include "DefineVarBindCommand.h"

DefineVarBindCommand::DefineVarBindCommand(string var, string path, SymbolTable* symbolTable) {
    this->var = var;
    this->path = path;
    this->symbolTable = symbolTable;
}

int DefineVarBindCommand::execute() {
    // todo connect to network
    this->symbolTable->addVariable(this->var, 1, true);

}
