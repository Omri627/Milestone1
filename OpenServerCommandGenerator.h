

#ifndef PROJECT_OPENSERVERCOMMANDGENERATOR_H
#define PROJECT_OPENSERVERCOMMANDGENERATOR_H


#include "CommandGenerator.h"

class OpenServerCommandGenerator  : public CommandGenerator{
public:
    virtual Command *create(CodeReader &codeReader);
};


#endif //PROJECT_OPENSERVERCOMMANDGENERATOR_H
