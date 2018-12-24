#ifndef VAR
    #define VAR

#include "string"
#include "SymbolTable.h"
#include "Expression.h"

using namespace std;
class Var : public Expression {
private:
    /* variable name-notation */
    string name;
    /* value of variable */
    double value;
    /* boolean variable indicates whether this variable is bound with server or not */
    bool isBind;
public:
    /**
     * the constructor creates Var object initialized with the given name and value.
     * @param name variable name
     */
    Var(string name);
    /**
     * the constructor creates Var object initialized with the given name and value.
     * @param name name of variable
     * @param value value of variable
     */
    Var(string name, double value);
    /**
    * the constructor creates Var object initialized with the given name, value and isbind.
    * @param name name of variable
    * @param value value of variable
    * @param isBind boolean variable indicates whether this variable is bound with server or not
    */
    Var(string name, double value, bool isBind);
    /**
     * the constructor gets name and symbol table object
     * and creates var object initialized with the given name and value
     * the value obtained from the symbol-table
     * @param name variable name
     * @param st symbol table object
     */
    Var(string name, SymbolTable* st);
    /**
     * getter method of variable name field
     * @return returns the variable name/notation of this var
     */
    string getVariableName() const;
    /**
     * setVariableName sets the variable name with given newly name.
     * @param name name of variable
     */
    void setVariableName(string name);
    /**
     * setValue method sets the variable value which obtained from given symbol-table
     * @param symbolTable symbol table object
     */
    void setValue(SymbolTable symbolTable);
    /**
     * setValue method sets the variable value with given value
     * @param value newly value
     */
    void setValue(double value);
    /**
    * calculate method computes this mathematical expression
    * and returns the result as real number.
    * @return result of this mathematical expression
    */
    virtual double calculate() const ;
    /**
     * getter method of isbind field
     * @return returns boolean variable indicating whether this variable is bound with server or not.
     */
    bool getIsBind() const;
    /**
     * setIsBind method sets inbind attribute of this variable
     * @param isBind boolean variable indicates whether this variable is bound with server or not
     */
    void setIsBind(bool isBind);
    /**
     * getter method of value field
     * @return returns value of variable
     */
    double getValue() const;
    /**
     * printExpression method prints out textual representation of this expression
     * infix mode representation
     */
    virtual void printExpression() const;
};

#endif
