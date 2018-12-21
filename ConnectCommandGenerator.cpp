#include "ConnectCommandGenerator.h"
#include "ExpressionParser.h"

ConnectCommandGenerator::ConnectCommandGenerator(CodeParser *codeParser, ThreadManager * threadManager) {
    this->codeParser = codeParser;
    this->threadManager = threadManager;
}
Command *ConnectCommandGenerator::create(CodeReader &codeReader) {
    ExpressionParser expressionParser(codeReader.getSymbolTable());
    string address = codeReader.getNextToken();
    string port = codeReader.getNextToken();
    Expression * portExpression = expressionParser.parseExpression(port);
    ClientServer * server = new ClientServer(address, portExpression, codeReader.getSymbolTable());
    codeParser->setClientServer(server);
    ConnectCommand * connectCommand = new ConnectCommand(server, threadManager);
    return connectCommand;
}
