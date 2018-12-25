#ifndef DEFINE_VAR_COMMAND
    #define DEFINE_VAR_COMMAND
#include "Command.h"
#include "Expression.h"

class DefineVarCommand : public Command {
private:
    /* variable name */
    string var;
    /* value of variable */
    double value;
    /* symbol table object */
    SymbolTable* symbolTable;
public:
    /**
     * the constructor creates define var command initialized with given
     * var, value and symbol table object.
     * @param var variable name
     * @param value value of variable
     * @param symbolTable symbol table object
     */
    DefineVarCommand(string var, double value, SymbolTable * symbolTable);
    /**
     * the constructor creates define var command initialized with given
     * var, value and symbol table object.
     * @param var variable name
     * @param expression value of variable represented in mathematical expression
     * @param symbolTable symbol table object
     */
    DefineVarCommand(string var, Expression* expression, SymbolTable * symbolTable);
    /**
     * execute define new variable and set the value of given variable.
     * @return return 1 this operation succeed.
     */
    virtual int execute();

    virtual ~DefineVarCommand();
};


#endif