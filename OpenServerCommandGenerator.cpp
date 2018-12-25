#include "OpenServerCommandGenerator.h"
#include "OpenDataServerCommand.h"
#include "ExpressionParser.h"

OpenServerCommandGenerator::OpenServerCommandGenerator(ThreadManager *threadManager) {
    this->threadManager = threadManager;
}
Command *OpenServerCommandGenerator::create(CodeReader &codeReader) {
    const int commandParameters = 2;
    if (!codeReader.isRemainingToken(commandParameters))
        throw "invalid open server command: no enough parameters transmitted";
    string port = codeReader.getNextToken();
    string speed = codeReader.getNextToken();
    ExpressionParser expressionParser(codeReader.getSymbolTable());
    return new OpenDataServerCommand(this->threadManager, codeReader.getSymbolTable(),
            expressionParser.parseExpression(port),
            expressionParser.parseExpression(speed));
}
OpenServerCommandGenerator::~OpenServerCommandGenerator() {
    this->threadManager = nullptr;
}
