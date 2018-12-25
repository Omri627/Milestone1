#ifndef CONNECT_COMMAND
    #define CONNECT_COMMAND

#include "ClientServer.h"
#include "Expression.h"
#include "Command.h"
#include "ThreadManager.h"

class ConnectCommand : public Command {
private:
    /* client server object */
    ClientServer * server;
    /* thread manager object */
    ThreadManager* threadManager;
public:
    /**
     * creates Connect Command object with initialized with given server and thread_ manager object
     * @param server client server object
     * @param threadManager thread manager object
     */
    ConnectCommand(ClientServer* server, ThreadManager * threadManager);
    /**
     * creates Connect Command object initialized with thread_ manager object and server
     * the constructor received server properties and creates and new server.
     * @param st symbol table object
     * @param port port represent as expression
     * @param address address of server
     * @param threadManager thread manager object
     */
    ConnectCommand(SymbolTable* st, Expression* port, string address, ThreadManager * threadManager);
    /**
     * creates Connect Command object initialized with thread_ manager object and server
     * the constructor received server properties and creates and new server.
     * @param st symbol table object
     * @param port port number
     * @param address address of server
     * @param threadManager thread manager object
     */
    ConnectCommand(SymbolTable* st, int port, string address, ThreadManager * threadManager);
    /**
     * setPort sets the port number with given port
     * @param port port number
     */
    void setPort(int port);
    /**
     * setPort sets the port number with given expression.
     * @param port port numner represent as expression
     */
    void setPort(Expression* port);
    /**
     * setAddress sets the ip address of the server with given address
     * @param address address of server
     */
    void setAddress(string address);
    /**
     * getter method of port field
     * @return returns the number of port.
     */
    int getPort();
    /**
     * getter method of address field
     * @return return the ip-address of this server
     */
    string getAddress();
    /**
     * connect to the given server
     * @return return 1 if this operation succeeed.
     * at any other case return 0
     */
    virtual int execute();

    virtual ~ConnectCommand();
};


#endif