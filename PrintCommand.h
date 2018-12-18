#ifndef PRINT_COMMAND
    #define PRINT_COMMAND
#include "CodeReader.h"
#include "Command.h"

class PrintCommand : public Command {
private:
    string str;
public:
    PrintCommand(string str);

    int execute();
};


#endif
