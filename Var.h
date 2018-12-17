#ifndef VAR
    #define VAR

#include "string"
#include "SymbolTable.h"
#include "Expression.h"

using namespace std;
class Var : public Expression {
private:
    string name;
    double value;
public:
    Var(string name);

    Var(string name, double value);

    Var(string name, SymbolTable st);

    string getVariableName() const;

    void setVariableName(string name);

    void setValue(SymbolTable symbolTable);

    void setValue(double value);

    virtual double calculate() const ;




};

#endif
