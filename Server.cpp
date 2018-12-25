#include "Server.h"
#include <string.h>
Server::Server(string address, int port, ThreadManager *threadManager, SymbolTable *symbolTable)  {
    this->address = address;
    this->port = port;
    this->symbolTable = symbolTable;
    this->threadManager = threadManager;
    this->socketFd = 0;
}
Server::Server(string address, Expression *port, ThreadManager *threadManager, SymbolTable *symbolTable)
: Server(address, port->calculate(), threadManager, symbolTable) {
}
int Server::getPort() const {
    return this->port;
}
string Server::getAddress() const {
    return this->address;
}
int Server::getSocketFd() const {
    return this->socketFd;
}
void Server::setPort(int port) {
    this->port = port;
}
void Server::setPort(Expression *expression) {
    this->port = (int)expression->calculate();
}
void Server::setAddress(string address) {
    this->address = address;
}
void Server::setThreadManager(ThreadManager *threadManager) {
    this->threadManager = threadManager;
}
void Server::setSocketFd(int socketFd) {
    this->socketFd = socketFd;
}

SymbolTable *Server::getSymbolTable() const {
    return this->symbolTable;
}

ThreadManager *Server::getThreadManager() const {
    return this->threadManager;
}
void Server::sendData(string message) {
    int byteTransmitted;
    const char * msgToTransmit = message.c_str();
    /* Send message to the server */
    pthread_mutex_lock(&g__mutex);
    byteTransmitted = write(this->getSocketFd(), msgToTransmit, strlen(msgToTransmit));
    pthread_mutex_unlock(&g__mutex);
    if (byteTransmitted < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }
    /*  read server simulator response */
    this->readData();
}