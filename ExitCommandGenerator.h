#ifndef EXIT_COMMAND_GENERATOR
    #define EXIT_COMMAND_GENERATOR


#include "CommandGenerator.h"
#include "CodeParser.h"

class ExitCommandGenerator : public CommandGenerator {
private:
    CodeParser *codeParser;
    ThreadManager* threadManager;
    ClientServer* clientServer;
public:
    ExitCommandGenerator(CodeParser *codeParser, ThreadManager * threadManager, ClientServer * clientServer);

    virtual Command *create(CodeReader &codeReader);

    virtual ~ExitCommandGenerator();
};

#endif //PROJECT_EXITCOMMANDGENERATOR_H
