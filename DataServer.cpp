#include <iostream>
#include "DataServer.h"

DataServer::DataServer(SymbolTable *symbolTable, int port, int speed, ThreadManager* threadManager) : varsUpdater(symbolTable) {
    this->symbolTable = symbolTable;
    this->port = port;
    this->speed = speed;
    this->threadManager = threadManager;
};
void DataServer::setPort(int port) {
    this->port = port;
}
void DataServer::setSpeed(int speed) {
    this->speed = speed;
}
int DataServer::getPort() const {
    return this->port;
}
int DataServer::getSpeed() const {
    return this->speed;
}
void* DataServer::openDataServer() {
    int socketFd, establishedFd;                            // socket file descriptor
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
    server_address.sin_port = htons(this->port);              // setting server port
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
    this->fileDescriptor = accept(socketFd, (struct sockaddr *) &client_address, (socklen_t *) &clientSizeStructure);
    if (establishedFd < 0) {
        perror("ERROR on accept");
        exit(1);
    }
    cout << "request accepted"  << endl;
    return nullptr;
}
void DataServer::closeDataServer() {
    //@ todo close data server
}
void DataServer::readSingleLine() {
    pthread_mutex_lock(&threadManager->g__mutex);
    const int bufferSize = 512;
    int bytesReaded;
    char buffer[bufferSize];
    bzero(buffer,bufferSize);                      // set buffer with null values
    //pthread_mutex_t mutex;
    //pthread_mutex_lock(&mutex);
    bytesReaded = read(this->fileDescriptor, buffer, bufferSize-1);
    //pthread_mutex_unlock(&mutex);
    if (bytesReaded < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }
    varsUpdater.update(buffer);
    pthread_mutex_unlock(&threadManager->g__mutex);
}
void DataServer::readData() {

    while (true){
        this->readSingleLine();
    }
}
void* DataServer::openDataServerHelper(void *context) {
    return ((DataServer*) context)->openDataServer();
}
void* DataServer::readLineHelper(void *context) {
    ((DataServer*) context)->readData();
    return nullptr;
}