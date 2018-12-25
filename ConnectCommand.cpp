#include "ConnectCommand.h"
#include "ExpressionParser.h"
#include "DataServer.h"
/**
 * creates Connect Command object with initialized with given server and thread_ manager object
 * @param server client server object
 * @param threadManager thread manager object
 */
ConnectCommand::ConnectCommand(ClientServer *server, ThreadManager * threadManager) {
    this->server = server;
    this->server->setThreadManager(threadManager);
    this->threadManager = threadManager;
}
/**
 * creates Connect Command object initialized with thread_ manager object and server
 * the constructor received server properties and creates and new server.
 * @param st symbol table object
 * @param port port represent as expression
 * @param address address of server
 * @param threadManager thread manager object
 */
ConnectCommand::ConnectCommand(SymbolTable *st, int port, string address, ThreadManager * threadManager) {
    this->server = new ClientServer(address, port, threadManager, st);
    this->threadManager = threadManager;
}
/**
 * creates Connect Command object initialized with thread_ manager object and server
 * the constructor received server properties and creates and new server.
 * @param st symbol table object
 * @param port port number
 * @param address address of server
 * @param threadManager thread manager object
 */
ConnectCommand::ConnectCommand(SymbolTable *st, Expression *port, string address, ThreadManager * threadManager) {
    this->server = new ClientServer(address, port->calculate(), threadManager , st);
    this->threadManager = threadManager;
}
/**
 * getter method of port field
 * @return returns the number of port.
 */
int ConnectCommand::getPort() {
    return this->server->getPort();
}
/**
 * getter method of address field
 * @return return the ip-address of this server
 */
string ConnectCommand::getAddress() {
    return this->server->getAddress();
}
/**
 * setAddress sets the ip address of the server with given address
 * @param address address of server
 */
void ConnectCommand::setAddress(string address) {
    this->server->setAddress(address);
}
/**
 * setPort sets the port number with given port
 * @param port port number
 */
void ConnectCommand::setPort(int port) {
    this->server->setPort(port);
}
/**
 * setPort sets the port number with given expression.
 * @param port port numner represent as expression
 */
void ConnectCommand::setPort(Expression *port) {
    this->server->setPort(port);
}
/**
 * connect to the given server
 * @return return 1 if this operation succeeed.
 * at any other case return 0
 */
int ConnectCommand::execute() {
    pthread_t serverThread;                     // define new thread
    if (!threadManager->isThreadExist(ThreadManager::SERVER_THREAD))
        return 0;
    pthread_create(&serverThread, nullptr, &ClientServer::connectServerHelper, this->server);
    this->threadManager->addThread(serverThread);
    //this->threadManager->runThread(serverThread);
    pthread_join(serverThread, nullptr);
    //this->threadManager->addThread(serverThread, ThreadManager::ConnectThread);
    return 1;
}

ConnectCommand::~ConnectCommand() {

}
