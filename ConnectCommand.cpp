#include "ConnectCommand.h"
#include "ExpressionParser.h"
#include "DataServer.h"

ConnectCommand::ConnectCommand(ClientServer *server, ThreadManager * threadManager) {
    this->server = server;
    this->server->setThreadManager(threadManager);
    this->threadManager = threadManager;
}
ConnectCommand::ConnectCommand(SymbolTable *st, int port, string address, ThreadManager * threadManager) {
    this->server = new ClientServer(address, port, st);
    this->server->setThreadManager(threadManager);
    this->threadManager = threadManager;
}
ConnectCommand::ConnectCommand(SymbolTable *st, Expression *port, string address, ThreadManager * threadManager) {
    this->server = new ClientServer(address, port->calculate(), st);
    this->threadManager = threadManager;
}
int ConnectCommand::getPort() {
    return this->server->getPort();
}
string ConnectCommand::getAddress() {
    return this->server->getAddress();
}
void ConnectCommand::setAddress(string address) {
    this->server->setAddress(address);
}
void ConnectCommand::setPort(int port) {
    this->server->setPort(port);
}
void ConnectCommand::setPort(Expression *port) {
    this->server->setPort(port);
}
int ConnectCommand::execute() {
    pthread_t serverThread;                     // define new thread
    if (!threadManager->isThreadExist(ThreadManager::ServerThread))
        return 0;
    pthread_create(&serverThread, nullptr, &ClientServer::connectServerHelper, this->server);
    this->threadManager->addThread(serverThread);
    this->threadManager->runThread(serverThread);
    //this->threadManager->addThread(serverThread, ThreadManager::ConnectThread);
    return 1;
}