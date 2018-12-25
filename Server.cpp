#include "Server.h"
#include <string.h>
/**
 * creates Server object with initialized with given fields:
 * ip address, port, thread manager and symbol table
 * @param address ip address of server
 * @param port port of the connection
 * @param threadManager thread manager object
 * @param symbolTable symbol table object
 */
Server::Server(string address, int port, ThreadManager *threadManager, SymbolTable *symbolTable)  {
    this->address = address;
    this->port = port;
    this->symbolTable = symbolTable;
    this->threadManager = threadManager;
    this->socketFd = 0;
}
/**
 * creates Server object with initialized with given fields:
 * ip address, port, thread manager and symbol table
 * @param address ip address of server
 * @param port port of the connection
 * @param threadManager thread manager object
 * @param symbolTable symbol table object
 */
Server::Server(string address, Expression *port, ThreadManager *threadManager, SymbolTable *symbolTable)
: Server(address, port->calculate(), threadManager, symbolTable) {
}
/**
 * getPort method is getter method of port connection.
 * @return returns the port of connection between client and server.
 */
int Server::getPort() const {
    return this->port;
}
/**
* getAddress method is getter method of server's ip address.
* @return returns the ip address of server
*/
string Server::getAddress() const {
    return this->address;
}
/**
 * getter method of socket file descriptor
 * @return return the file descriptor id of socket connection to the server.
 */
int Server::getSocketFd() const {
    return this->socketFd;
}
/**
 * setPort method sets the port attribute with the given port number.
 * @param port newly port number
 */
void Server::setPort(int port) {
    this->port = port;
}
/**
 * setPort method sets the port attribute.
 * @param portExpression port value represented as expression.
 */
void Server::setPort(Expression *expression) {
    this->port = (int)expression->calculate();
}
/**
 * setAddress method sets the ip address attribute with given address
 * @param address newly ip address
 */
void Server::setAddress(string address) {
    this->address = address;
}
/**
 * setThreadManager method sets the thread manager fields with given thread manager object
 * @param threadManager thread manager object
 */
void Server::setThreadManager(ThreadManager *threadManager) {
    this->threadManager = threadManager;
}
/**
 * setSocketFd method sets the socket file descriptor.
 * @param socketFd newly socket file descriptor
 */
void Server::setSocketFd(int socketFd) {
    this->socketFd = socketFd;
}
/**
* getter method of symbol table field
* @return returns symbol table object
*/
SymbolTable *Server::getSymbolTable() const {
    return this->symbolTable;
}
/**
 * getter method of thread manager field
 * @return returns thread manager object
 */
ThreadManager *Server::getThreadManager() const {
    return this->threadManager;
}
/**
 * sendData method sends a data or message to the server.
 * used for change variable's values in server.
 * @param message
 */
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
/**
 * destructor, free memory
 */
Server::~Server() {

}
