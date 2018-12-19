#ifndef COMMAND
    #define COMMAND

#include <string>
#include "CodeReader.h"

using namespace std;
// Command Interface
class Command {

public:
    virtual int execute() = 0;
};

#endif