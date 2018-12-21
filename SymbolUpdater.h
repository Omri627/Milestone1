#ifndef SYMBOL_TABLE
#define SYMBOL_TABLE

#include <string>
#include <map>
class Var;
using namespace std;
class SymbolTable {
private:
    map < string, Var* > variables; //todo: add free memory to variable
public:
    void addVariable(string var, double value, bool isBind);

    void addVariable(string var, double value);

    unsigned long removeVariable(string var);

    void setValue(string var, double value);

    void updateVariable(Var& var);

    double getVariable(string var) ;

    bool isVariableEquels(string var, double value);

    bool isVariableExist(string var) ;

    Var * getVar(string var);

    void setValueAndBind(string varName, double value, bool isBind);

    void setIsBind(string varName, bool isBind);
};


#endif