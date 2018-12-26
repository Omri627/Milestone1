#include "ExitCommand.h"
/**
 * creates Exit Command object initialized with given code parser
 * @param codeParser code parser object
 */
ExitCommand::ExitCommand(CodeParser *codeParser, ThreadManager * threadManager, ClientServer * clientServer) {
    this->codeParser = codeParser;
    this->threadManager = threadManager;
    this->clientServer = clientServer;
}
/**
 * exit the program and release allocated memory
 * @return
 */
int ExitCommand::execute() {
    if (!this->codeParser)
        delete codeParser;
    if (!this->threadManager)
        delete threadManager;
    if (!this->clientServer)
        delete this->clientServer;
    pthread_mutex_destroy(&g__mutex);
    exit(0);

}
/**
 * destrcutor, free memory
 */
ExitCommand::~ExitCommand() {

}
