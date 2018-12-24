#include "ClientServer.h"
ClientServer::ClientServer(string address, int port, SymbolTable *st) {
    this->address = address;
    this->port = port;
    this->symbolTable = st;
    this->socketFd = 0;
}
ClientServer::ClientServer(string address, Expression* portExpression, SymbolTable *st) {
    this->address = address;
    this->port = portExpression->calculate();
    this->symbolTable = st;
    this->socketFd = 0;
}
int ClientServer::getPort() {
    return this->port;
}
string ClientServer::getAddress() {
    return this->address;
}
void ClientServer::setPort(int port) {
    this->port = port;
}
void ClientServer::setPort(Expression *expression) {
    this->port = expression->calculate();
}
void ClientServer::setAddress(string address) {
    this->address = address;
}
void ClientServer::setThreadManager(ThreadManager *threadManager) {
    this->threadManager = threadManager;
}
void ClientServer::updateServer(string variable) {
    //cout << "entered updateServer" << endl;
    char commandMessage[512];
    if (socketFd == 0)
        return;
    string path = this->symbolTable->getPathByVar(variable);
    double value = this->symbolTable->getVariable(variable);
    sprintf(commandMessage, "set %s %.3f", path.c_str(), value);
    strcat(commandMessage, "\r\n");
    //cout << "sending update of " << variable << endl;
    //cout << commandMessage << endl;
    this->writeIntoServer(commandMessage);
}
void ClientServer::connectToServer() {
    int socketFd;                           // socket file descriptor
    struct sockaddr_in serverAddress;       // server address
    struct hostent *server;                 // store information about hostt
    cout << "wating for open data server" << endl;
    if (this->threadManager != nullptr)
        threadManager->waitForThread(ThreadManager::SERVER_THREAD);
    cout << "now trying to connect..." << endl;
    const char * address = this->address.c_str();
    // AF-INET = address family ipv4
    // SOCK_STREAM = protocol tcp provides reliable, ordered, and error-checked delivery of bytes.
    // protocol = 0  default protocol for the given combination of family and type
    // socket method opens socket by insert socket resource into resources table of operating system
    // and returns integer which uniquely identifies a resouce in operating system.
    socketFd = socket(AF_INET, SOCK_STREAM, 0);
    // send message in case there is an error in opening socket
    if (socketFd < 0) {
        perror("ERROR opening socket");
        cout << "ERROR opening socket"<< endl;
        exit(1);
    }
    server = gethostbyname(address);

    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }
    // Initialize socket structure
    bzero((char *) &serverAddress, sizeof(serverAddress));  // used to set all the socket structures with null values
    serverAddress.sin_family = AF_INET;                     // setting address family (=ipv4)
    bcopy((char *)server->h_addr, (char *)&serverAddress.sin_addr.s_addr, server->h_length);
    serverAddress.sin_port = htons(this->port);         // setting server port

    /* connect to the server */
     if (connect(socketFd, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) < 0) {
         perror("ERROR connecting");
         cout << "ERROR connecting"<< endl;
         exit(1);
     }
     this->socketFd = socketFd;
    cout << "connected successfully" << endl;
     //this->threadManager->removeThread(pthread_self()); todo:: check if keep on comment
     //cout << "connection worked" << endl;


    /*int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[256];
    portno = this->port;

    cout << "connect: going to sleep" << endl;
    //sleep(70); todo::if the simulator is already on, no sleep needed
    cout << "woke up" << endl;

    /* Create a socket point */
    /*sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }
    const char * address = this->address.c_str();
    server = gethostbyname(address);

    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    /* Now connect to the server */
    /*if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    /* Now ask for a message from the user, this message
       * will be read by server
    */

    /*printf("Please enter the message: ");
    bzero(buffer,256);
    //fgets(buffer,255,stdin);
    strcpy(buffer, "set controls/flight/rudder 1\r\n");

    /* Send message to the server */
    //n = write(sockfd, buffer, strlen(buffer));

    /*if (n < 0) {
        perror("ERROR writing to socket");
        cout << "ERROR writing to socket" << endl;
        exit(1);
    }
    cout << buffer << endl;
    /* Now read server response */
    /*if (n < 0) {
        perror("ERROR reading from socket");
        cout<< "ERROR reading from socket" << endl;
        exit(1);
    }
r
    pintf("%s\n",buffer); */
}
void ClientServer::writeIntoServer(string message) {
    pthread_mutex_lock(&g__mutex);
    const int bufferSize = 512;
    int byteTransmitted, byteReaded;
    char buffer[bufferSize];
    //pthread_mutex_t mutex;
    const char * msgToTransmit = message.c_str();
    //cout << "msgTotransmit " << msgToTransmit << endl;
    /* Send message to the server */
    //pthread_mutex_lock(&mutex);
    bzero(buffer,bufferSize);
    byteTransmitted = write(this->socketFd, msgToTransmit, strlen(msgToTransmit));

    pthread_mutex_unlock(&g__mutex);
    fflush(stdin);
    fflush(stdout);
    if (byteTransmitted <= 0) {
        perror("ERROR writing to socket");
        exit(1);
    }
    //cout << "clientserver: wrote into server" << endl;
    bzero(buffer,bufferSize);
    byteReaded = read(this->socketFd, buffer, bufferSize-1);
    cout << buffer << endl;
    //fflush(stdin);

    if (byteReaded < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }
    //cout << "read response from server" << endl;
    //cout << buffer << endl;
    //cout << "clientserver: finish write into server" << endl;


}
void *ClientServer::connectServerHelper(void *context) {
    ((ClientServer*)context)->connectToServer();
    return nullptr;
}