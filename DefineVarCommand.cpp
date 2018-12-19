#include <iostream>
#include "DefineVarCommand.h"

DefineVarCommand::DefineVarCommand(string var, string path, SymbolTable* symbolTable) {
    this->var = var;
    this->path = path;
    this->symbolTable = symbolTable;
}

int DefineVarCommand::execute() {
    // todo connect to network
    this->symbolTable->addVariable(this->var, 1);

}
