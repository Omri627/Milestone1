#ifndef CONNECT_COMMAND_GENERATOR
    #define CONNECT_COMMAND_GENERATOR


#include "CommandGenerator.h"
#include "ConnectCommand.h"
#include "CodeParser.h"

class ConnectCommandGenerator : public CommandGenerator {
private:
    CodeParser* codeParser;
    ThreadManager * threadManager;
public:
    ConnectCommandGenerator(CodeParser* codeParser, ThreadManager * threadManager);

    virtual Command *create(CodeReader &codeReader);
};


#endif
