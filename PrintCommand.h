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
    * constructor
    * @param str the string to print
    */
    PrintCommand(string str);

    /**
    * constructor
    * @param symbolTable symbolTable
    * @param var the var to print his value
    */
    PrintCommand(SymbolTable * symbolTable, string var);
    /**
    * preform print command
    * @return int
    */
    int execute();
};


#endif