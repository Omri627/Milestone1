#include "SleepCommand.h"
/**
 * the constructor creates Sleep-Command object with the given seconds as parameter.
 * @param miliSeconds number of seconds to sleep
 */
SleepCommand::SleepCommand(double miliSeconds) {
    this->miliseconds = miliSeconds;
}
/**
 * execute sleep command operation
 * and sleep for given number of seconds.
 * @return returns 1 if the operation succeed
 * at any other case return 0
 */
int SleepCommand::execute() {
    usleep(this->miliseconds);
}

SleepCommand::~SleepCommand() {

}
