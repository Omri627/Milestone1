//
// Created by ranraboh on 16/12/18.
//

#include "UpdateVarCommand.h"
UpdateVarCommand::UpdateVarCommand(string var, Expression *phrase, SymbolTable* symbolTable) {
    this->var = var;
    this->phrase = phrase;
    this->symbolTable = symbolTable;
}
void UpdateVarCommand::setVar(string variable) {
    this->var = variable;
}
void UpdateVarCommand::setPhrase(Expression *expression) {
    this->phrase = expression;
}
void UpdateVarCommand::setServer(ClientServer *server) {
    this->server = server;
}
string UpdateVarCommand::getVar() {
    return this->var;
}
Expression* UpdateVarCommand::getPhrase() {
    return this->phrase;
}
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
