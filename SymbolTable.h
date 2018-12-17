#ifndef SYMBOL_TABLE
    #define SYMBOL_TABLE

#include <string>
#include <map>
class Var;
using namespace std;
class SymbolTable {
private:
    map < string, double > variables;
public:
    void addVariable(string var, double value);

    unsigned long removeVariable(string var);

    void setValue(string var, double value);

    void updateVariable(Var& var);

    double getVariable(string var) ;

    bool isVariableEquels(string var, double value);

    bool isVariableExist(string var) ;

    Var * getVariableObject(string var);
};


#endif
