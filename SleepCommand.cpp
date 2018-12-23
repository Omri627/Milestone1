#include "SleepCommand.h"
/**
 * the constructor creates Sleep-Command object with the given seconds as parameter.
 * @param seconds number of seconds to sleep
 */
SleepCommand::SleepCommand(int seconds) {
    this->seconds = seconds;
}
/**
 * execute sleep command operation
 * and sleep for given number of seconds.
 * @return returns 1 if the operation succeed
 * at any other case return 0
 */
int SleepCommand::execute() {
    //@todo check if sleep unit is in seconds
    sleep(this->seconds);
}
