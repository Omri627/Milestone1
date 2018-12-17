//
// Created by ranraboh on 16/12/18.
//

#include "DefineVarCommand.h"

DefineVarCommand::DefineVarCommand(string var, string path, SymbolTable& symbolTable)
: symbolTable(symbolTable) {
    this->var = var;
    this->path = path;
}

int DefineVarCommand::execute() {
    // todo connect to network and update symbol table
    return 1;
}
