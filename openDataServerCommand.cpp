#include "openDataServerCommand.h"

openDataServerCommand::openDataServerCommand(DataServer*  dataServer) {
    this->server = dataServer;
}
openDataServerCommand::openDataServerCommand(SymbolTable * symbolTable,int port, int speed) {
    this->server = new DataServer(symbolTable, port, speed);
}
void openDataServerCommand::setPort(int port) {
    this->server->setPort(port);
}
void openDataServerCommand::setSpeed(int speed) {
    this->server->setSpeed(speed);
}
int openDataServerCommand::getPort() const {
    return this->server->getPort();
}
int openDataServerCommand::getSpeed() const {
    return this->server->getSpeed();
}
int openDataServerCommand::execute() {
    pthread_t serverThread;
    int i;
    //void* (*serverMethod) = this->server->openDataServer();
    pthread_create(&serverThread, 0, this->serverMethod, );


}
void* serverThread(DataServer* dataServer) {

}