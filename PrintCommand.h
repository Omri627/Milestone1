#ifndef PRINT_COMMAND
#define PRINT_COMMAND
#include "CodeReader.h"
#include "Command.h"

class PrintCommand : public Command {
private:
    string str;
    SymbolTable * symbolTable;
public:

    /**
    * constructor: creates print command object initialized with given string.
    * the created command will print out the string on screen
    * @param str the string to print
    */
    PrintCommand(string str);

    /**
    * constructor: creates print command object initialized with given variable name and symbol table object.
    * the created command will print out the value of given variable on screen
    * @param symbolTable symbolTable
    * @param var the var to print his value
    */
    PrintCommand(SymbolTable * symbolTable, string var);
    /**
    * prints out string on screen
    * prints out variable value on screen
    * @return 1 if the operation succeed.
     * at any other case return 0
    */
    int execute();

    virtual ~PrintCommand();
};


#endif