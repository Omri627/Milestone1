#ifndef CLIENT_SERVER
    #define CLIENT_SERVER

#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <iostream>
#include "SymbolTable.h"
#include "Expression.h"
#include "ThreadManager.h"
#include <string.h>
using namespace std;
class ClientServer {
private:
    string address;
    int port;
    SymbolTable * symbolTable;
    ThreadManager * threadManager;
    int socketFd;
    pthread_mutex_t mutex;
public:
    /**
     * the constructor gets connection details: ip address, port and the symbols table
     * and creates new ClientServer object which manage the the connection between the client and server.
     * enables us to connect, write messages to server and updates his variables.
     * @param address ip- address of server
     * @param port port number
     * @param st
     */
    ClientServer(string address, int port, SymbolTable * st);
    /**
     * the constructor gets connection details: ip address, port and the symbols table
     * and creates new ClientServer object which manage the the connection between the client and server.
     * enables us to connect, write messages to server and updates his variables.
     * @param address ip- address of server
     * @param portExpression port value represented as expression
     * @param st
     */
    ClientServer(string address, Expression* portExpression, SymbolTable * st);
    /**
     * getAddress method is getter method of server's ip address.
     * @return returns the ip address of server
     */
    string getAddress();
    /**
     * getPort method is getter method of port connection.
     * @return returns the port of connection between client and server.
     */
    int getPort();
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

    void connectToServer();

    static void *connectServerHelper(void *context);

    void writeIntoServer(string message);

    void updateSymbolTableValues();

    void setVariableValue(Var& var);

};


#endif //PROJECT_CLIENTSERVER_H
