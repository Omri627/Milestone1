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
    /* speed of read frequency from server */
    int speed;
    /* socket structures */
    SymbolUpdater varsUpdater;
public:
    /**
     * creates Data Server object with initialized with given fields:
     * speed, port, thread manager and symbol table
     * @param symbolTable symbol table object
     * @param port port of connection
     * @param speed speed of read frequency from server
     * @param threadManager thread manager object
     */
    DataServer(SymbolTable * symbolTable, int port, int speed, ThreadManager* threadManager);
    /**
     * getter method of speed field
     * @return  the speed of reading frequency from server
     */
    int getSpeed() const;
    /**
     * sets the speed of reading frequency from server
     * @param speed newly speed
     */
    void setSpeed(int speed);
    /**
     * open data server localhost.
     * so the simulator can connect and transmit data with program.
     * @return nullptr
     */
    void* openDataServer();
    /**
     * close data server.
     */
    void closeDataServer();
    /**
     * read single line from the server
     */
    void readSingleLine();
    /**
     * reads data from server continuously with predetermined frequency
     */
    void readData();
    /**
    * help to pass openDataServer to pthread
    * @param context the context fo the function to be send
    * @return nullptr
    */
    static void* openDataServerHelper(void *context);
    /**
     * helper method to enables us to open pthread that his target is the read lines from server.
     * @param context the context for the function to be send
     * @return nullptr
     */
    static void* readLineHelper(void *context);

};


#endif
