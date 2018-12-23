#ifndef SLEEP_COMMAND
    #define SLEEP_COMMAND

#include "Command.h"
#include <unistd.h>

class SleepCommand : public Command {
private:
    /* number of seconds to sleep */
    int seconds;
public:
    /**
     * the constructor creates Sleep-Command object with the given seconds as parameter.
     * @param seconds number of seconds to sleep
     */
    SleepCommand(int seconds);
    /**
     * execute sleep command operation
     * and sleep for given number of seconds.
     * @return returns 1 if the operation succeed
     * at any other case return 0
     */
    virtual int execute();

};


#endif //PROJECT_SLEEPCOMMAND_H
