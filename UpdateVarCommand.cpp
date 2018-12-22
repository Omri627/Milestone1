#include "UpdateVarCommand.h"
/**
 * constructor
 * @param var: the name of the var to update
 * @param phrase: the expression to update the var
 * @param symbolTable: pointer to symbolTable to update the var
 */
UpdateVarCommand::UpdateVarCommand(string var, Expression *phrase, SymbolTable* symbolTable) {
    this->var = var;
    this->phrase = phrase;
    this->symbolTable = symbolTable;
}
/**
 * execute the command
 * @return 1 if successful
 */
int UpdateVarCommand::execute() {
    symbolTable->setValue(var, phrase->calculate());
    return 1;
}
