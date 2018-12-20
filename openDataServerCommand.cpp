#include "openDataServerCommand.h"

openDataServerCommand::openDataServerCommand(int port, int speed) {
    this->port = port;
    this->speed = speed;
}
void openDataServerCommand::setPort(int port) {
    this->port = port;
}
void openDataServerCommand::setSpeed(int speed) {
    this->speed = speed;
}
int openDataServerCommand::getPort() const {
    return this->port;
}
int openDataServerCommand::getSpeed() const {
    return this->speed;
}
int openDataServerCommand::execute() {



}