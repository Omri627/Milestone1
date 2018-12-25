#ifndef CONNECT_COMMAND_GENERATOR
    #define CONNECT_COMMAND_GENERATOR


#include "CommandGenerator.h"
#include "ConnectCommand.h"
#include "CodeParser.h"

class ConnectCommandGenerator : public CommandGenerator {
private:
    /* code parser object */
    CodeParser* codeParser;
    /* thread manager object */
    ThreadManager * threadManager;
public:
    /**
     * constructor creates connect command generator.
     * used to create connect objects.
     * @param codeParser code parser
     * @param threadManager thread manager object
     */
    ConnectCommandGenerator(CodeParser* codeParser, ThreadManager * threadManager);
    /**
     * create method creates new connect command
     * the parameters address and port received from code tokens
     * @param codeReader code tokens
     * @return command object
     */
    virtual Command *create(CodeReader &codeReader);

    virtual ~ConnectCommandGenerator();
};


#endif
