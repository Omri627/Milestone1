//
// Created by ranraboh on 16/12/18.
//

#include "UpdateVarCommand.h"
UpdateVarCommand::UpdateVarCommand(string var, Expression *phrase, SymbolTable& symbolTable)
: symbolTable(symbolTable) {
    this->var = var;
    this->phrase = phrase;
}

int UpdateVarCommand::execute() {
    symbolTable.setValue(var, phrase->calculate());
    return 1;
}
