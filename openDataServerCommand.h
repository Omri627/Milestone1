#ifndef OPEN_DATA_SERVER_COMMAND
    #define OPEN_DATA_SERVER_COMMAND

#include "pthread.h"
#include "DataServer.h"
class openDataServerCommand : public Command {
private:
    DataServer * server;
public:
    openDataServerCommand(DataServer* dataServer);

    openDataServerCommand(SymbolTable * symbolTable,int port, int speed);

    int getPort() const ;

    int getSpeed() const;

    void setPort(int port);

    void setSpeed(int speed);

    int execute() override;

    static void* serverMethod(DataServer* dataServer);
    };


#endif
