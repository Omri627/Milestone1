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

/**
 * this class handle the creation of the server
 */
class DataServer {
private:
    int port;
    int speed;
    /* socket structures */
    struct sockaddr_in server_address, client_address;
    int fileDescriptor;
    SymbolTable * symbolTable;
    SymbolUpdater updater;
public:
    /**
    * constructor
    * @param symbolTable symbolTable
    * @param port
    * @param speed
    */
    DataServer(SymbolTable * symbolTable, int port, int speed);

    /**
    * open our dataReaderServer, that reads parameters that the simulator is sending us
    * @return
    */
    void* openDataServer();
    /**
     * help to pass openDataServer to pthread
     * @param context the context fo the function to be send
     * @return
     */
    static void *openDataServerHelper(void *context);

    void closeDataServer();

    /**
    * read the parameters that the server send
    */
    void readData();

    /**
    * getter for port
    * @return int port
    */
    int getPort() const ;

    /**
    * getter for speed of reading
    * @return speed
    */
    int getSpeed() const;

    /**
    * setter for port
    * @param port: port's number
    */
    void setPort(int port);

    /**
    * setter for speed of reading
    * @param speed int
    */
    void setSpeed(int speed);
    //todo: delete these function if we're not using them
    void writeData();

    void updateBindVariables();

};


#endif
