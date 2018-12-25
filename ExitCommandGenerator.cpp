#include "ExitCommandGenerator.h"
#include "ExitCommand.h"

ExitCommandGenerator::ExitCommandGenerator(CodeParser *codeParser, ThreadManager * threadManager, ClientServer * clientServer) {
    this->codeParser = codeParser;
    this->threadManager = threadManager;
    this->clientServer = clientServer;
}
Command *ExitCommandGenerator::create(CodeReader &codeReader) {
    return new ExitCommand(this->codeParser, this->threadManager, this->clientServer);
}

ExitCommandGenerator::~ExitCommandGenerator() {

}
