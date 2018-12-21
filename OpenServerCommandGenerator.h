

#ifndef PROJECT_OPENSERVERCOMMANDGENERATOR_H
#define PROJECT_OPENSERVERCOMMANDGENERATOR_H


#include "CommandGenerator.h"
#include "ThreadManager.h"

class OpenServerCommandGenerator  : public CommandGenerator{
private:
    ThreadManager * threadManager;
public:
    OpenServerCommandGenerator(ThreadManager* threadManager);

    virtual Command *create(CodeReader &codeReader);
};


#endif //PROJECT_OPENSERVERCOMMANDGENERATOR_H
