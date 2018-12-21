//
// Created by ranraboh on 18/12/18.
//

#include "Command.h"

#ifndef PRINT_COMMAND_GENERATOR
#define PRINT_COMMAND_GENERATOR
using namespace std;
#include "CommandGenerator.h"
#include "PrintCommand.h"
class PrintCommandGenerator : public CommandGenerator {
public:
    Command * create(CodeReader& codeReader);

};
#endif