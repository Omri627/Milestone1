#ifndef SERVER_H
    #define SERVER_H

#include <string>
#include "ThreadManager.h"
#include "SymbolTable.h"
#include "Expression.h"
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <iostream>
using namespace std;
class Server {
private:
    string address;
    int port;
    ThreadManager * threadManager;
    SymbolTable * symbolTable;
    int socketFd;

public:
    Server(string address, int port, ThreadManager* threadManager, SymbolTable * symbolTable);

    Server(string address, Expression * port, ThreadManager* threadManager, SymbolTable * symbolTable);

    /**
 * getAddress method is getter method of server's ip address.
 * @return returns the ip address of server
 */
    string getAddress() const;
    /**
     * getPort method is getter method of port connection.
     * @return returns the port of connection between client and server.
     */
    int getPort() const;

    ThreadManager *getThreadManager() const;

    int getSocketFd() const ;
    /**
     * setPort method sets the port attribute.
     * @param portExpression port value represented as expression.
     */
    void setPort(Expression * portExpression);
    /**
     * setPort method sets the port attribute with the given port number.
     * @param port newly port number
     */
    void setPort(int port);
    /**
     * setAddress method sets the ip address attribute with given address
     * @param address newly ip address
     */
    void setAddress(string address);

    void setThreadManager(ThreadManager* threadManager);

    void setSocketFd(int socketFd);

    virtual void sendData(string message);

    virtual void readData() = 0;

    SymbolTable *getSymbolTable() const;
};

#endif //PROJECT_SERVER_H
