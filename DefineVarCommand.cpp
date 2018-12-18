//
// Created by ranraboh on 16/12/18.
//

#include "DefineVarCommand.h"

DefineVarCommand::DefineVarCommand(string var, string path, SymbolTable* symbolTable) {
    this->var = var;
    this->path = path;
    this->symbolTable = symbolTable;
}

int DefineVarCommand::execute() {
    // todo connect to network and update symbol table
    return 1;
}
