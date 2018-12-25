#include "SleepCommand.h"
/**
 * the constructor creates Sleep-Command object with the given seconds as parameter.
 * @param seconds number of seconds to sleep
 */
SleepCommand::SleepCommand(double seconds) {
    //@todo: i think we have a mistake here, we shoudnt divide it by 1000.
    //@todo: since we used usleep.
    this->miliseconds = seconds / 1000;
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
