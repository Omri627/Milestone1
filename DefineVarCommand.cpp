#include "DefineVarCommand.h"
/**
 * the constructor creates define var command initialized with given
 * var, value and symbol table object.
 * @param var variable name
 * @param value value of variable
 * @param symbolTable symbol table object
 */
DefineVarCommand::DefineVarCommand(string var, double value, SymbolTable *symbolTable) {
    this->var = var;
    this->value = value;
    this->symbolTable = symbolTable;
}
/**
 * command set the value of given variable.
 * @return return 1 this operation succeed.
 */
DefineVarCommand::DefineVarCommand(string var, Expression *expression, SymbolTable *symbolTable) {
    this->var = var;
    this->value = expression->calculate();
    this->symbolTable = symbolTable;
}
/**
 * command set the value of given variable.
 * @return return 1 this operation succeed.
 */
int DefineVarCommand::execute() {
    this->symbolTable->addVariable(this->var, this->value, false);
}

DefineVarCommand::~DefineVarCommand() {

}

