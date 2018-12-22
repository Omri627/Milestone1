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
    bool isBind;
public:
    Var(string name);

    Var(string name, double value);

    Var(string name, double value, bool isBind);

    Var(string name, SymbolTable* st);

    string getVariableName() const;

    void setVariableName(string name);

    void setValue(SymbolTable symbolTable);

    void setValue(double value);

    virtual double calculate() const ;

    bool getIsBind() const;

    void setIsBind(bool isBind);

    double getValue() const;

    void printExpression() const override;
};

#endif
