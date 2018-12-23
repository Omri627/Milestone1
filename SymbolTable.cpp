#include "SymbolTable.h"
#include "Var.h"
#include "ClientServer.h"

/**
  * add variable to the variables map
  * @param var: name of the var
  * @param value: the value to set to the var
  * @param isBind indicate if the var is bind to the server
  */

void SymbolTable::addVariable(string varName, double value, bool isBind) {
    this->variables[varName] = new Var(varName, value, isBind);
}
/**
* add variable to the variables map, with isBind is false
* @param var: name of the
* @param value: the value to set to the var
*/
void SymbolTable::addVariable(string var, double value) {
    //add variable with isbine is false
    this->variables[var] = new Var(var, value, false);
}
/**
* get variable value
* @param var: name of the var
* @return the value of the var
*/
double SymbolTable::getVariable(string var) {
    return this->variables[var]->getValue();
}

/**
* check if the variable exist inside the variables map
* @param var: var name
* @return true if exist, else false
*/
bool SymbolTable::isVariableExist(string var) {
    map< string, Var* >::iterator iterator;
    iterator = this->variables.find(var);           // find given variable in the map
    if (iterator != this->variables.end())          // if variable reach end before iterator reaches end
        return true;                                // then return true
    return false;
}

/**
* swt the value of var inside the variables map
* @param var: name of the var
* @param value: the value to set to the var
*/
void SymbolTable::setValue(string var, double value) {
    if (isVariableExist(var))
        this->variables[var]->setValue(value);
}

/**
* remove variable from the variables map
* @param var: name of the var
* @return the number of element erase
*/
unsigned long SymbolTable::removeVariable(string var) {
    return this->variables.erase(var);
}

/**
* check whether the variable's value equals to the given value
* @param var: var's name
* @param value: var's value
* @return true if equals, else false
*/
bool SymbolTable::isVariableEquels(string var, double value) {
    /* if variable doesnt exist return false */
    if (!this->isVariableExist(var))
        return false;
    /* check whether the variable's value equals to the given value */
    if (this->variables[var]->getValue() == value)
        return true;
    return false;
}
/**
 * isVariableBind method gets variable name and returns
 * whether the variable is bind or not.
 * @param varName variable name
 * @return returns true if given variable is bind
 * at any other case returns false
 **/
bool SymbolTable::isVariableBind(string varName) {
    if (!this->isVariableExist(varName))
        return false;
    if (this->variables[varName]->getIsBind())
        return true;
    return false;
}
/**
* update existing var inside the variables map
* @param var Var by reference
*/
void SymbolTable::updateVariable(Var &var) {
    double value = this->getVariable(var.getVariableName());
    var.setValue(value);
}

/**
* get the var's pointer by name
* @param var: string name
* @return Var*
*/
Var* SymbolTable::getVar(string var) {
    return this->variables[var];
}
/**
* set value and isBind to var
* @param varName: the var name
* @param value: the value to be set
* @param isBind: true if the var isBind, else false
*/
void SymbolTable::setValueAndBind(string varName, double value, bool isBind) {
    if(isVariableExist(varName)) {
        Var* var = getVar(varName);
        var->setValue(value);
        var->setIsBind(isBind);
    }
}
/**
* set IsBind
* @param varName: name of the var
* @param isBind: boolean
*/
void SymbolTable::setIsBind(string varName, bool isBind) {
    if(isVariableExist(varName)) {
        Var* var = getVar(varName);
        var->setIsBind(isBind);
    }
}
/**
* check if path is exist in paths map
* @param path: the path to check
* @return true if path exist, else false
*/
bool SymbolTable::isPathExist(string path) {
    //check if the map contains the path key
    map<string, string>::const_iterator it = paths.find(path);
    return it != paths.end();
}
/**
* add path to paths map
* @param path: string path
* @param varName: var's name
*/
void SymbolTable::addPath(string path, string varName) {
    this->paths[path] = varName;
}

/**
* get var's name by path
* @param path: string path to be checked
* @return the name of the var
*/
string SymbolTable::getVarNameByPath(string path) {
    if (isPathExist(path)) {
        return paths[path];
    }
}
/**
* get var by path
* @param path: string path
* @return Var*
*/
Var* SymbolTable::getVarByPath(string path) {
    if (isPathExist(path)) {
        string varName = paths[path];
        if (isVariableExist(varName))
            return getVar(varName);
        return nullptr;
    }
    return nullptr;
}
/**
 * getPathByVar method gets variable name and return assosciated path.
 * @param varName variable name
 * @return returns path associated with given variable.
 */
string SymbolTable::getPathByVar(string varName) {
    map <string, string >::iterator iterator;
    while (iterator != this->paths.end()) {
        if (iterator->second == varName)
            return iterator->first;
        iterator++;
    }
    throw "error: variable name not found";
}
void SymbolTable::updateServer(string variable, ClientServer *server) {
    char commandMessage[512];
    if (server == nullptr)
        return;
    string path = this->getPathByVar(variable);
    double value = this->getVariable(variable);
    sprintf(commandMessage, "set %s %f \r\n", path.c_str(), value);
    server->writeIntoServer(commandMessage);
}
/**
* destructor, free memory
*/
SymbolTable::~SymbolTable() {
    for (pair<string, Var*> p : variables) {
        delete p.second;
    }
}