#ifndef CLIENT_SERVER
    #define CLIENT_SERVER

#include "SymbolTable.h"
#include "Expression.h"
#include "ThreadManager.h"
#include "SymbolUpdater.h"
#include <string.h>
#include "Utils.h"
#include "Server.h"

using namespace std;
class ClientServer : public Server {
public:
    /**
     * the constructor gets connection details: ip address, port and the symbols table
     * and creates new ClientServer object which manage the the connection between the client and server.
     * enables us to connect, write messages to server and updates his variables.
     * @param address ip- address of server
     * @param port port number
     * @param st
     */
    ClientServer(string address, int port,ThreadManager*threadManager ,SymbolTable * st);
    /**
     * the constructor gets connection details: ip address, port and the symbols table
     * and creates new ClientServer object which manage the the connection between the client and server.
     * enables us to connect, write messages to server and updates his variables.
     * @param address ip- address of server
     * @param portExpression port value represented as expression
     * @param st
     */
    ClientServer(string address, Expression* portExpression,ThreadManager*threadManager ,SymbolTable * st);

    virtual void connectToServer();

    virtual void readData();
    /**
    * updateServer method sends a message to server
    * for update a single variable
    * @param variable variable name
     */
    void updateServer(string variable);

    static void *connectServerHelper(void *context);

};

#endif
