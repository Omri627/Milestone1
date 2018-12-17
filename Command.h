
#ifndef MILESTONE1_COMMAND_H
#define MILESTONE1_COMMAND_H

#include <string>
#include "CodeReader.h"

using namespace std;
// Command Interface
class Command {

public:
    virtual int execute() = 0;

};

#endif //MILESTONE1_COMMAND_H