//
// Created by ranraboh on 16/12/18.
//

#ifndef PROJECT_DEFINEVARCOMMANDGENERATOR_H
#define PROJECT_DEFINEVARCOMMANDGENERATOR_H

#include "CommandGenerator.h"

class DefineVarCommand;
class DefineVarCommandGenerator  : public CommandGenerator{
public:
    virtual Command *create(CodeReader &codeReader);
};


#endif
