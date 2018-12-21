#include "SymbolTable.h"
#include "Var.h"
void SymbolTable::addVariable(string varName, double value, bool isBind) {
    this->variables[varName] = new Var(varName, value, isBind);
}

void SymbolTable::addVariable(string var, double value) {
    //add variable with isbine is false
    this->variables[var] = new Var(var, value, false);
}

double SymbolTable::getVariable(string var) {
    return this->variables[var]->getValue();
}

bool SymbolTable::isVariableExist(string var) {
    map< string, Var* >::iterator iterator;
    iterator = this->variables.find(var);           // find given variable in the map
    if (iterator != this->variables.end())          // if variable reach end before iterator reaches end
        return true;                                // then return true
    return false;
}
void SymbolTable::setValue(string var, double value) {
    if (isVariableExist(var))
        this->variables[var]->setValue(value);
}
unsigned long SymbolTable::removeVariable(string var) {
    return this->variables.erase(var);
}
bool SymbolTable::isVariableEquels(string var, double value) {
    /* if variable doesnt exist return false */
    if (!this->isVariableExist(var))
        return false;
    /* check whether the variable's value equals to the given value */
    if (this->variables[var]->getValue() == value)
        return true;
    return false;
}
void SymbolTable::updateVariable(Var &var) {
    double value = this->getVariable(var.getVariableName());
    var.setValue(value);
}

Var* SymbolTable::getVar(string var) {
    return this->variables[var];
}

void SymbolTable::setValueAndBind(string varName, double value, bool isBind) {
    if(isVariableExist(varName)) {
        Var* var = getVar(varName);
        var->setValue(value);
        var->setIsBind(isBind);
    }
}

void SymbolTable::setIsBind(string varName, bool isBind) {
    if(isVariableExist(varName)) {
        Var* var = getVar(varName);
        var->setIsBind(isBind);
    }
}

bool SymbolTable::isPathExist(string path) {
    //check if the map contains the path key
    return paths.find(path) != paths.end();
}

void SymbolTable::addPath(string path, string varName) {
        this->paths[path] = varName;
}

string SymbolTable::getVarNameByPath(string path) {
    if (isPathExist(path)) {
        return paths[path];
    }
}

Var* SymbolTable::getVarByPath(string path) {
    if (isPathExist(path)) {
        string varName = paths[path];
        if (isVariableExist(varName))
            return getVar(varName);
        return nullptr;
    }
    return nullptr;


}



