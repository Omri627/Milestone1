#ifndef OPEN_DATA_SERVER_COMMAND
    #define OPEN_DATA_SERVER_COMMAND

#include "pthread.h"
#include "DataServer.h"
#include "Expression.h"
#include "ThreadManager.h"

class OpenDataServerCommand : public Command {
private:
    DataServer * server;
    SymbolTable *symbolTable;
    int port;
    int speed;
    ThreadManager * threadManager;
public:
    OpenDataServerCommand(ThreadManager * threadManager, DataServer* dataServer);

    OpenDataServerCommand(ThreadManager * threadManager, SymbolTable * symbolTable ,int port, int speed);

    OpenDataServerCommand(ThreadManager * threadManager, SymbolTable * symbolTable, Expression* port, Expression* speed);

    int getPort() const ;

    int getSpeed() const;

    void setPort(int port);

    void setSpeed(int speed);

    virtual int execute();

    virtual ~OpenDataServerCommand();

};


#endif
