#include "SymbolTable.h"
#include "Var.h"
void SymbolTable::addVariable(string var, double value) {
    this->variables[var] = value;
}
double SymbolTable::getVariable(string var) {
    return this->variables[var];
}
bool SymbolTable::isVariableExist(string var) {
    map< string, double >::iterator iterator;
    iterator = this->variables.find(var);           // find given variable in the map
    if (iterator != this->variables.end())          // if variable reach end before iterator reaches end
        return true;                                // then return true
    return false;
}
void SymbolTable::setValue(string var, double value) {
    if (isVariableExist(var))
        this->variables[var] = value;
}
unsigned long SymbolTable::removeVariable(string var) {
    return this->variables.erase(var);
}
bool SymbolTable::isVariableEquels(string var, double value) {
    /* if variable doesnt exist return false */
    if (!this->isVariableExist(var))
        return false;
    /* check whether the variable's value equals to the given value */
    if (this->variables[var] == value)
        return true;
    return false;
}
void SymbolTable::updateVariable(Var &var) {
    double value = this->getVariable(var.getVariableName());
    var.setValue(value);
}
Var * SymbolTable::getVariableObject(string var) {
    double value = this->getVariable(var);
    return new Var(var);
}