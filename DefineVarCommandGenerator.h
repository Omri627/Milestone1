//
// Created by ranraboh on 16/12/18.
//

#ifndef PROJECT_DEFINEVARCOMMANDGENERATOR_H
#define PROJECT_DEFINEVARCOMMANDGENERATOR_H


#include "CommandGenerator.h"

class DefineVarCommandGenerator  : public CommandGenerator{
public:
    Command *create(CodeReader &codeReader);
};


#endif //PROJECT_DEFINEVARCOMMANDGENERATOR_H
