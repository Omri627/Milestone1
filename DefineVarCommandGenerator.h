
#ifndef PROJECT_DEFINEVARCOMMANDGENERATOR_H
#define PROJECT_DEFINEVARCOMMANDGENERATOR_H

#include "CommandGenerator.h"

class DefineVarCommand;
class DefineVarCommandGenerator  : public CommandGenerator{
public:
    /**
    * create method creates new define var command object
    * with paramters received by code.
    * @param codeReader code tokens
    * @return new define var command
    */
    virtual Command *create(CodeReader &codeReader);

    virtual ~DefineVarCommandGenerator();
};


#endif