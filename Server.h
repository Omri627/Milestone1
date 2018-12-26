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
#include "Utils.h"


using namespace std;
class Server {
private:
    /* ip address of server */
    string address;
    /* port of the connection */
    int port;
    /* thread manager */
    ThreadManager * threadManager;
    /* symbol table object */
    SymbolTable * symbolTable;
    /* file descriptor of socket */
    int socketFd;

public:
    /**
     * creates Server object with initialized with given fields:
     * ip address, port, thread manager and symbol table
     * @param address ip address of server
     * @param port port of the connection
     * @param threadManager thread manager object
     * @param symbolTable symbol table object
     */
    Server(string address, int port, ThreadManager* threadManager, SymbolTable * symbolTable);
    /**
     * creates Server object with initialized with given fields:
     * ip address, port, thread manager and symbol table
     * @param address ip address of server
     * @param port port of the connection
     * @param threadManager thread manager object
     * @param symbolTable symbol table object
     */
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
    /**
     * getter method of thread manager field
     * @return returns thread manager object
     */
    ThreadManager *getThreadManager() const;
    /**
     * getter method of socket file descriptor
     * @return return the file descriptor id of socket connection to the server.
     */
    int getSocketFd() const ;
    /**
    * getter method of symbol table field
    * @return returns symbol table object
    */
    SymbolTable *getSymbolTable() const;
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
    /**
     * setThreadManager method sets the thread manager fields with given thread manager object
     * @param threadManager thread manager object
     */
    void setThreadManager(ThreadManager* threadManager);
    /**
     * setSocketFd method sets the socket file descriptor.
     * @param socketFd newly socket file descriptor
     */
    void setSocketFd(int socketFd);
    /**
     * sendData method sends a data or message to the server.
     * used for change variable's values in server.
     * @param message
     */
    virtual void sendData(string message);
    /**
     * readData method reads data from server
     */
    virtual void readData() = 0;
    /**
     * destructor, free memory
     */
    virtual ~Server();
};

#endif
