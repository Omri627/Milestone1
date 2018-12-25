

#ifndef OPEN_SERVER_COMMAND_GENERATOR
    #define OPEN_SERVER_COMMAND_GENERATOR
#include "CommandGenerator.h"
#include "ThreadManager.h"

class OpenServerCommandGenerator  : public CommandGenerator{
private:
    ThreadManager * threadManager;
public:
    OpenServerCommandGenerator(ThreadManager* threadManager);

    virtual Command *create(CodeReader &codeReader);

    virtual ~OpenServerCommandGenerator();
};


#endif //PROJECT_OPENSERVERCOMMANDGENERATOR_H
