#ifndef OPEN_DATA_SERVER_COMMAND
    #define OPEN_DATA_SERVER_COMMAND

#include "pthread.h"
#include "DataServer.h"
#include "Expression.h"
class OpenDataServerCommand : public Command {
private:
    DataServer * server;
    SymbolTable *symbolTable;
    int port;
    int speed;
public:
    OpenDataServerCommand(DataServer* dataServer);

    OpenDataServerCommand(SymbolTable * symbolTable ,int port, int speed);

    OpenDataServerCommand(SymbolTable * symbolTable, Expression* port, Expression* speed);

    int getPort() const ;

    int getSpeed() const;

    void setPort(int port);

    void setSpeed(int speed);

    int execute() override;

};


#endif
