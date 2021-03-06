#ifndef SLEEP_COMMAND
    #define SLEEP_COMMAND

#include "Command.h"
#include <unistd.h>

class SleepCommand : public Command {
private:
    /* number of seconds to sleep */
    double miliseconds;
public:
    /**
     * the constructor creates Sleep-Command object with the given seconds as parameter.
     * @param miliSeconds number of seconds to sleep
     */
    SleepCommand(double miliSeconds);
    /**
     * execute sleep command operation
     * and sleep for given number of miliseconds.
     * @return returns 1 if the operation succeed
     * at any other case return 0
     */
    virtual int execute();

    virtual ~SleepCommand();
};


#endif //PROJECT_SLEEPCOMMAND_H
