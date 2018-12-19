#include "DefineVarCommand.h"

DefineVarCommand::DefineVarCommand(string var, double value, SymbolTable *symbolTable) {
    this->var = var;
    this->value = value;
    this->symbolTable = symbolTable;
}
int DefineVarCommand::execute() {
    this->symbolTable->addVariable(this->var, this->value, false);
}
