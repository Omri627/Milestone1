#ifndef COMMAND
    #define COMMAND

#include <string>
#include "CodeReader.h"
/**
 * Command is an interface that represent thing that that need to be execute at a later time
 */
using namespace std;
// Command Interface
class Command {

public:
    /**
     * every command is doing action in his execute
     * @return int if successful
     */
    virtual int execute() = 0;
    /**
    * destructor, free memory
    */
    virtual ~Command() {}
};

#endif