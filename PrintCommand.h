#ifndef PRINT_COMMAND
    #define PRINT_COMMAND
#include "CodeReader.h"
#include "Command.h"

class PrintCommand : public Command {
public:
    PrintCommand();

    int execute(CodeReader& codeReader);
};


#endif
