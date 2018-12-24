#include "UpdateVarCommand.h"
/**
 *
 * @param var variable name
 * @param phrase the value of variable represented in expression
 * @param symbolTable symbol table object
 */
UpdateVarCommand::UpdateVarCommand(string var, Expression *phrase, SymbolTable* symbolTable) {
    this->var = var;
    this->phrase = phrase;
    this->symbolTable = symbolTable;
}
/**
 * setVar method sets the variable name of given variable
 * @param variable variable name.
 */
void UpdateVarCommand::setVar(string variable) {
    this->var = variable;
}
/**
 * setPhrase sets the phrase field with given expression
 * @param expression the value of variable represented in expression
 */
void UpdateVarCommand::setPhrase(Expression *expression) {
    this->phrase = expression;
}
/**
 * setServer method sets the server field with the given server
 * @param server simulator server
 */
void UpdateVarCommand::setServer(ClientServer *server) {
    this->server = server;
}
/**
 * getter method of variable name field.
 * @return returns variable name.
 */
string UpdateVarCommand::getVar() {
    return this->var;
}
/**
 * getter method of phrase field
 * @return return the value of variable represented in expression
 */
Expression* UpdateVarCommand::getPhrase() {
    return this->phrase;
}
/**
 * execute method updates variable value.
 * if simulator server is connected and the variable is bound.
 * then the method updates the simulator as well.
 * @return return 1 if the operation succeed.
 * at any other case return 0
 */
int UpdateVarCommand::execute() {
    /* if variable doesnt exist or is not bind  */
    if (!this->symbolTable->isVariableExist(this->var))
        return 0;
    symbolTable->setValue(var, phrase->calculate());
    /* if variable is bound with server,
     * update server for this modification */
    if (this->symbolTable->isVariableBind(this->var))
        symbolTable->updateServer(var, this->server);
    return 1;
}
