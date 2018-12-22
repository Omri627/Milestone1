#ifndef PRINT_COMMAND
#define PRINT_COMMAND
#include "CodeReader.h"
#include "Command.h"

class PrintCommand : public Command {
private:
    string str;
    SymbolTable * symbolTable;
public:
    PrintCommand(string str);

    PrintCommand(SymbolTable * symbolTable, string var);

    int execute();
};


#endif