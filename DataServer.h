#ifndef DATA_SERVER
    #define DATA_SERVER

#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include "Command.h"
#include "SymbolUpdater.h"
#include "Utils.h"
#include "ThreadManager.h"
#include "Server.h"


class DataServer : public Server {
private:
    int speed;
    /* socket structures */
    SymbolUpdater varsUpdater;
public:
    DataServer(SymbolTable * symbolTable, int port, int speed, ThreadManager* threadManager);

    int getSpeed() const;

    void setSpeed(int speed);

    void* openDataServer();

    void closeDataServer();

    void readSingleLine();

    void readData();

    /**
    * help to pass openDataServer to pthread
    * @param context the context fo the function to be send
    * @return
    */
    static void* openDataServerHelper(void *context);

    static void* readLineHelper(void *context);

};


#endif
