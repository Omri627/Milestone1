#include "OpenDataServerCommand.h"
#include <pthread.h>

OpenDataServerCommand::OpenDataServerCommand(DataServer*  dataServer) {
    this->server = dataServer;
}
OpenDataServerCommand::OpenDataServerCommand(SymbolTable * symbolTable,int port, int speed) {
    this->server = new DataServer(symbolTable, port, speed);
    this->port = port;
    this->speed = speed;
}

OpenDataServerCommand::OpenDataServerCommand(SymbolTable *symbolTable, Expression *port, Expression *speed) {
    this->port = port->calculate();
    this->speed = speed->calculate();
    this->server = new DataServer(symbolTable, this->port, this->speed);
}
void OpenDataServerCommand::setPort(int port) {
    this->server->setPort(port);
}
void OpenDataServerCommand::setSpeed(int speed) {
    this->server->setSpeed(speed);
}
int OpenDataServerCommand::getPort() const {
    return this->server->getPort();
}
int OpenDataServerCommand::getSpeed() const {
    return this->server->getSpeed();
}
int OpenDataServerCommand::execute() {

    //DataServer server(this->symbolTable, this->port, this->speed);
    pthread_t serverThread;
    pthread_create(&serverThread, nullptr, &DataServer::openDataServerHelper, this->server);
    pthread_detach(serverThread);
}

void* serverThread(DataServer* dataServer) {

}