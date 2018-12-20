#ifndef DATA_SERVER
    #define DATA_SERVER

#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include "Command.h"
class DataServer {
private:
    int port;
    int speed;
    /* socket structures */
    struct sockaddr_in server_address, client_address;       // socket structur
    int fileDescriptor;
    SymbolTable * symbolTable;
public:
    DataServer(SymbolTable * symbolTable, int port, int speed);

    void* openDataServer();
    /**
     * help to pass openDataServer to pthread
     * @param context the context fo the function to be send
     * @return
     */
    static void *openDataServerHelper(void *context);

    void closeDataServer();

    void readData();

    int getPort() const ;

    int getSpeed() const;

    void setPort(int port);

    void setSpeed(int speed);

    void writeData();

    void updateBindVariables();



};


#endif
