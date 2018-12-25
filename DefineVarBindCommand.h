#ifndef DEFINE_VAR_BIND_COMMAND
#define DEFINE_VAR_BIND_COMMAND


#include "Command.h"

class DefineVarBindCommand : public Command {
private:
    /* variable name */
    string var;
    /* path of variable in simulator */
    string path;
    /* symbol table object */
    SymbolTable* symbolTable;
public:
    /**
     * constructor creates define var bind object initialized
     * with given var, path and symbol table
     * @param var variable name
     * @param path  path of given variable
     * @param symbolTable symbol object object
     */
    DefineVarBindCommand(string var, string path, SymbolTable* symbolTable);
    /**
     * command creates new variable and
     * got the variable value from simulator server.
     * @return return 1 if this operation succeed.
     * at any other case return 0
     */
    virtual int execute();

    virtual ~DefineVarBindCommand();
};


#endif