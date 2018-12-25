#include "ClientServer.h"
/**
 * the constructor gets connection details: ip address, port and the symbols table
 * and creates new ClientServer object which manage the the connection between the client and server.
 * enables us to connect, write messages to server and updates his variables.
 * @param address ip address of server
 * @param port port of the connection
 * @param threadManager thread manager object
 * @param symbolTable symbol table object
 */
ClientServer::ClientServer(string address, int port,ThreadManager*threadManager ,SymbolTable *st)
: Server(address, port, threadManager, st) {
}
/**
 * creates Server object with initialized with given fields:
 * ip address, port, thread manager and symbol table
 * @param address ip address of server
 * @param port port of the connection represented as expression
 * @param threadManager thread manager object
 * @param symbolTable symbol table object
 */
ClientServer::ClientServer(string address, Expression* portExpression, ThreadManager*threadManager, SymbolTable *st)
: Server(address, portExpression, threadManager, st) {

}
/**
* updateServer method sends a message to server
* to update a single variable
* @param variable variable name
 */
void ClientServer::updateServer(string variable) {
    //cout << "entered updateServer" << endl;
    char commandMessage[512];
    if (this->getSocketFd() == 0)
        return;
    string path = this->getSymbolTable()->getPathByVar(variable);
    double value = this->getSymbolTable()->getVariable(variable);
    sprintf(commandMessage, "set %s %.3f", path.c_str(), value);
    strcat(commandMessage, "\r\n");
    this->sendData(commandMessage);
}
/**
 * connect to this server via sockets
 */
void ClientServer::connectToServer() {
    int socketFd;                           // socket file descriptor
    struct sockaddr_in serverAddress;       // server address
    struct hostent *server;                 // store information about hostt
    cout << "wating for open data server" << endl;
    if (this->getThreadManager() != nullptr)
        this->getThreadManager()->waitForThread(ThreadManager::SERVER_THREAD);
    cout << "now trying to connect..." << endl;
    const char * address = this->getAddress().c_str();
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
    serverAddress.sin_port = htons(this->getPort());         // setting server port

    /* connect to the server */
     if (connect(socketFd, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) < 0) {
         perror("ERROR connecting");
         cout << "ERROR connecting"<< endl;
         exit(1);
     }
     this->setSocketFd(socketFd);
    cout << "connected successfully" << endl;
}
/**
 * helper static method to run thread that connect to this server
 * @param context client server param.
 * @return nullptr
 */
void *ClientServer::connectServerHelper(void *context) {
    ((ClientServer*)context)->connectToServer();
    return nullptr;
}
/**
 * readData method reads data from server
 */
void ClientServer::readData() {
    const int bufferSize = 512;
    int byteReaded;
    char buffer[bufferSize];
    bzero(buffer,bufferSize);
    byteReaded = read(this->getSocketFd(), buffer, bufferSize-1);
    if (byteReaded < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }
}