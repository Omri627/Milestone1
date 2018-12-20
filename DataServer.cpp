//
// Created by ranraboh on 20/12/18.
//

#include <iostream>
#include "DataServer.h"

DataServer::DataServer(SymbolTable *symbolTable, int port, int speed) {
    this->symbolTable = symbolTable;
    this->port = port;
    this->speed = speed;
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
    int sockfd, newsockfd, portno, clilen;
    portno = 5400;
    char buffer[512];
    struct sockaddr_in serv_addr, cli_addr;
    int  n;

    /* First call to socket() function */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    /* Initialize socket structure */
    bzero((char *) &serv_addr, sizeof(serv_addr));


    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    /* Now bind the host address using bind() call.*/
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    /* Now start listening for the clients, here process will
       * go in sleep mode and will wait for the incoming connection
    */

    listen(sockfd,5);
    clilen = sizeof(cli_addr);

    /* Accept actual connection from the client */
    newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, (socklen_t*)&clilen);

    if (newsockfd < 0) {
        perror("ERROR on accept");
        exit(1);
    }

    while(1) {
        bzero(buffer,512);
        n = read( newsockfd,buffer,512 );

        if (n < 0) {
            perror("ERROR reading from socket");
            exit(1);
        }

        //printf("Here is the message: %s\n",buffer);

        /* Write a response to the client */
        //n = write(newsockfd,"I got your message",18);
        cout << buffer << endl;

        if (n < 0) {
            perror("ERROR writing to socket");
            exit(1);
        }

    }
    /* If connection is established then start communicating */



    return 0;
   /* int socketFd, establishedFd;                            // socket file descriptor
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
    *//* Initialize socket structure *//*
    bzero((char *) &server_address, sizeof(server_address));  // used to set all the socket structures with null values.
    server_address.sin_family = AF_INET;                      // setting address family (=ipv4)
    server_address.sin_port = htons(this->port);              // setting server port
    server_address.sin_addr.s_addr = INADDR_ANY;              // internal ip address
    *//* bind function assigns a local protocol address to a socket. *//*
    if (bind(socketFd, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }
    // start listening for the clients,
    // the process be in sleep mode and will wait for the incoming connection
    listen(socketFd, this->port);
    *//* Accept actual connection from the client *//*
    clientSizeStructure = sizeof(client_address);
    establishedFd = accept(socketFd, (struct sockaddr *) &client_address, (socklen_t *) &clientSizeStructure);
    if (establishedFd < 0) {
        perror("ERROR on accept");
        exit(1);
    }
    while (1){
        readData();
    }*/
}
void DataServer::closeDataServer() {

}

void DataServer::readData() {
    const int bufferSize = 512;
    int bytesReaded;
    char buffer[bufferSize];
    bzero(buffer,bufferSize);                      // set buffer with null values
    bytesReaded = read(this->fileDescriptor, buffer, bufferSize-1);
    if (bytesReaded < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }
    cout << buffer << endl;
}

void* DataServer::openDataServerHelper(void *context) {
    return ((DataServer*) context)->openDataServer();
}
