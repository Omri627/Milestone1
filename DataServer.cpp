#include <iostream>
#include "DataServer.h"
pthread_mutex_t global_mutex;

/**
 * creates Data Server object with initialized with given fields:
 * speed, port, thread manager and symbol table
 * @param symbolTable symbol table object
 * @param port port of connection
 * @param speed speed of read frequency from server
 * @param threadManager thread manager object
 */
DataServer::DataServer(SymbolTable *symbolTable, int port, int speed, ThreadManager* threadManager)
: Server("127.0.0.1", port, threadManager, symbolTable),varsUpdater(symbolTable) {
    this->speed = speed;
};
/**
 * sets the speed of reading frequency from server
 * @param speed newly speed
 */
void DataServer::setSpeed(int speed) {
    this->speed = speed;
}
/**
 * getter method of speed field
 * @return  the speed of reading frequency from server
 */
int DataServer::getSpeed() const {
    return this->speed;
}
/**
 * open data server localhost.
 * so the simulator can connect and transmit data with program.
 * @return nullptr
 */
void* DataServer::openDataServer() {
    int socketFd, connectFd;                            // socket file descriptor
    struct sockaddr_in server_address, client_address;       // socket structure
    int clientSizeStructure;
    // AF-INET = address family ipv4
    // SOCK_STREAM = protocol tcp provides reliable, ordered, and error-checked delivery of bytes.
    // protocol = 0  default protocol for the given combination of family and type
    // socket method opens socket by insert socket resource into resources table of operating system
    // and returns integer which uniquely identifies a resouce in operating system.
    socketFd = socket(AF_INET, SOCK_STREAM, 0);
    // send message in case there is an error in opening socket
    if (socketFd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }
    //* Initialize socket structure *//*
    bzero((char *) &server_address, sizeof(server_address));  // used to set all the socket structures with null values.
    server_address.sin_family = AF_INET;                      // setting address family (=ipv4)
    server_address.sin_addr.s_addr = INADDR_ANY;              // internal ip address
    server_address.sin_port = htons(this->getPort());              // setting server port
    //* bind function assigns a local protocol address to a socket. *//*
    if (bind(socketFd, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }
    cout << "server opened listen for client request" << endl;
    // start listening for the clients,
    // the process be in sleep mode and will wait for the incoming connection
    listen(socketFd, 5);
    //* Accept actual connection from the client *//*
    clientSizeStructure = sizeof(client_address);
    connectFd = accept(socketFd, (struct sockaddr *) &client_address, (socklen_t *) &clientSizeStructure);
    if (connectFd < 0) {
        perror("ERROR on accept");
        exit(1);
    }
    this->setSocketFd(connectFd);
    cout << "request accepted"  << endl;
    return nullptr;
}
/**
 * close data server.
 */
void DataServer::closeDataServer() {
    //@ todo close data server
}
/**
 * read single line from the server
 */
void DataServer::readSingleLine() {
    pthread_mutex_lock(&global_mutex);
    const int bufferSize = 512;
    int bytesReaded;
    char buffer[bufferSize];
    bzero(buffer,bufferSize);                      // set buffer with null values
    bytesReaded = read(this->getSocketFd(), buffer, bufferSize-1);
    if (bytesReaded < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }
    pthread_mutex_unlock(&global_mutex);
    varsUpdater.update(buffer);
}
/**
 * reads data from server continuously with predetermined frequency
 */
void DataServer::readData() {
    //@todo use speed
    while (true){
        this->readSingleLine();
    }
}
/**
* help to pass openDataServer to pthread
* @param context the context fo the function to be send
* @return nullptr
*/
void* DataServer::openDataServerHelper(void *context) {
    return ((DataServer*) context)->openDataServer();
}
/**
 * helper method to enables us to open pthread that his target is the read lines from server.
 * @param context the context for the function to be send
 * @return nullptr
 */
void* DataServer::readLineHelper(void *context) {
    ((DataServer*) context)->readData();
    return nullptr;
}