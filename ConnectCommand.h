#ifndef CONNECT_COMMAND
    #define CONNECT_COMMAND

#include "ClientServer.h"
#include "Expression.h"
#include "Command.h"
#include "ThreadManager.h"

class ConnectCommand : public Command {
private:
    ClientServer * server;
    ThreadManager* threadManager;
public:
    ConnectCommand(ClientServer* server, ThreadManager * threadManager);

    ConnectCommand(SymbolTable* st, Expression* port, string address, ThreadManager * threadManager);

    ConnectCommand(SymbolTable* st, int port, string address, ThreadManager * threadManager);

    void setPort(int port);

    void setPort(Expression* port);

    void setAddress(string address);

    int getPort();

    string getAddress();

    virtual int execute();
};


#endif