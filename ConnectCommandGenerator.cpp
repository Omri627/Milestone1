#include "ConnectCommandGenerator.h"
#include "ExpressionParser.h"
/**
 * constructor creates connect command generator.
 * used to create connect objects.
 * @param codeParser code parser
 * @param threadManager thread manager object
 */
ConnectCommandGenerator::ConnectCommandGenerator(CodeParser *codeParser, ThreadManager * threadManager) {
    this->codeParser = codeParser;
    this->threadManager = threadManager;
}
/**
 * create method creates new connect command
 * the parameters address and port received from code tokens
 * @param codeReader code tokens
 * @return command object
 */
Command *ConnectCommandGenerator::create(CodeReader &codeReader) {
    const int commandParameters = 2;
    if (!codeReader.isRemainingToken(commandParameters))
        throw "invalid connect command: no enough parameters transmitted";
    ExpressionParser expressionParser(codeReader.getSymbolTable());
    string address = codeReader.getNextToken();
    string port = codeReader.getNextToken();
    Expression * portExpression = expressionParser.parseExpression(port);
    ClientServer * server = new ClientServer(address, portExpression, this->threadManager , codeReader.getSymbolTable());
    codeParser->setClientServer(server);
    ConnectCommand * connectCommand = new ConnectCommand(server, threadManager);
    return connectCommand;
}

ConnectCommandGenerator::~ConnectCommandGenerator() {


}
