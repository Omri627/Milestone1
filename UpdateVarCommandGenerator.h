//
// Created by ranraboh on 16/12/18.
//

#ifndef PROJECT_DEFINEVARCOMMANDCREATOR_H
#define PROJECT_DEFINEVARCOMMANDCREATOR_H


#include "CommandGenerator.h"
#include "Var.h"
class UpdateVarCommandGenerator : public CommandGenerator {
public:
    Command *create(CodeReader &codeReader);

};


#endif //PROJECT_DEFINEVARCOMMANDCREATOR_H
