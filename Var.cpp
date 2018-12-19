#include "Var.h"
Var::Var(string name) {
    this->name = name;
}
Var::Var(string name, double value) {
    this->name = name;
    this->value = value;
    this->isBind = false;
}

Var::Var(string name, double value, bool isBind) {
    this->name = name;
    this->value = value;
    this->isBind = isBind;
}
Var::Var(string name, SymbolTable* st) {
    this->name = name;
    this->value = st->getVariable(name);
}
void Var::setValue(SymbolTable st) {
    if (!st.isVariableExist(this->name))
        throw "variable doesnt exist";
    this->value = st.getVariable(this->name);
}

void Var::setValue(double value) {
    this->value = value;
}

void Var::setVariableName(string name) {
    this->name = name;
}

string Var::getVariableName() const {
    return this->name;
}
double Var::calculate() const {
    return this->value;
}

bool Var::getIsBind() const {
    return isBind;
}

void Var::setIsBind(bool isBind) {
    Var::isBind = isBind;
}

double Var::getValue() const {
    return value;
}

