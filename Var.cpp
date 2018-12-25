#include <iostream>
#include "Var.h"
/**
 * the constructor creates Var object initialized with the given name and value.
 * @param name variable name
 */
Var::Var(string name) {
    this->name = name;
}
/**
 * the constructor creates Var object initialized with the given name and value.
 * @param name name of variable
 * @param value value of variable
 */
Var::Var(string name, double value) {
    this->name = name;
    this->value = value;
    this->isBind = false;
}
/**
* the constructor creates Var object initialized with the given name, value and isbind.
* @param name name of variable
* @param value value of variable
* @param isBind boolean variable indicates whether this variable is bound with server or not
*/
Var::Var(string name, double value, bool isBind) {
    this->name = name;
    this->value = value;
    this->isBind = isBind;
}
/**
 * the constructor gets name and symbol table object
 * and creates var object initialized with the given name and value
 * the value obtained from the symbol-table
 * @param name variable name
 * @param st symbol table object
 */
Var::Var(string name, SymbolTable* st) {
    this->name = name;
    this->value = st->getVariable(name);
}
/**
 * setValue method sets the variable value which obtained from given symbol-table
 * @param symbolTable symbol table object
 */
void Var::setValue(SymbolTable st) {
    if (!st.isVariableExist(this->name))
        throw "variable doesnt exist";
    this->value = st.getVariable(this->name);
}
/**
 * setValue method sets the variable value with given value
 * @param value newly value
 */
void Var::setValue(double value) {
    this->value = value;
}
/**
 * setVariableName sets the variable name with given newly name.
 * @param name name of variable
 */
void Var::setVariableName(string name) {
    this->name = name;
}
/**
 * getter method of variable name field
 * @return returns the variable name/notation of this var
 */
string Var::getVariableName() const {
    return this->name;
}
/**
 * calculate method computes this mathematical expression
 * and returns the result as real number.
 * @return result of this mathematical expression
 */
double Var::calculate() const {
    return this->value;
}
/**
 * getter method of isbind field
 * @return returns boolean variable indicating whether this variable is bound with server or not.
 */
bool Var::getIsBind() const {
    return isBind;
}
/**
 * setIsBind method sets inbind attribute of this variable
 * @param isBind boolean variable indicates whether this variable is bound with server or not
 */
void Var::setIsBind(bool isBind) {
    Var::isBind = isBind;
}
/**
 * getter method of value field
 * @return returns value of variable
 */
double Var::getValue() const {
    return value;
}
/**
 * printExpression method prints out textual representation of this expression
 * infix mode representation
 */
void Var::printExpression() const {
    cout << " " << this->name << " ";

}
/**
 * destructor, free memory
 */
Var::~Var() {
}