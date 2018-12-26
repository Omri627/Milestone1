#include "OpenDataServerCommand.h"
#include "ThreadManager.h"
#include <pthread.h>

OpenDataServerCommand::OpenDataServerCommand(ThreadManager * threadManager, DataServer*  dataServer) {
    this->server = dataServer;
    this->threadManager = threadManager;
}
OpenDataServerCommand::OpenDataServerCommand(ThreadManager * threadManager, SymbolTable * symbolTable,
        int port, int speed) {
    this->server = new DataServer(symbolTable, port, speed, threadManager);
    this->threadManager = threadManager;
    this->port = port;
    this->speed = speed;
}

OpenDataServerCommand::OpenDataServerCommand(ThreadManager * threadManager, SymbolTable *symbolTable, Expression *port, Expression *speed) {
    this->port = port->calculate();
    this->speed = speed->calculate();
    this->threadManager = threadManager;
    this->server = new DataServer(symbolTable, this->port, this->speed,threadManager);
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
    int threadId;
    pthread_t serverThread, serverListenThread;
    pthread_create(&serverThread, nullptr, &DataServer::openDataServerHelper, this->server);
    this->threadManager->addThread(serverThread, ThreadManager::SERVER_THREAD);
    pthread_join(serverThread, nullptr);
    pthread_create(&serverListenThread, nullptr, &DataServer::readLineHelper, this->server);
    threadId = this->threadManager->addThread(serverThread, ThreadManager::SERVER_LISTEN_THREAD);
    pthread_detach(serverListenThread);
    return threadId;
}

OpenDataServerCommand::~OpenDataServerCommand() {
    delete this->server;
}
