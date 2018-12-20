#ifndef OPEN_DATA_SERVER_COMMAND
    #define OPEN_DATA_SERVER_COMMAND
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include "Command.h"
#include "DataServer.h"

class openDataServerCommand : public Command {
private:
    /* port number */
    int port;
    /* speed rate of reading */
    int speed;

public:
    openDataServerCommand(DataServer* dataServer);

    int getPort() const ;

    int getSpeed() const;

    void setPort(int port);

    void setSpeed(int speed);

    int execute() override;

};


#endif
