#include "OpenServerCommandGenerator.h"
#include "OpenDataServerCommand.h"
#include "ExpressionParser.h"

OpenServerCommandGenerator::OpenServerCommandGenerator(ThreadManager *threadManager) {
    this->threadManager = threadManager;
}
Command *OpenServerCommandGenerator::create(CodeReader &codeReader) {
    string port = codeReader.getNextToken();
    string speed = codeReader.getNextToken();
    //todo throw error if there is no 2 parameter
    ExpressionParser expressionParser(codeReader.getSymbolTable());
    return new OpenDataServerCommand(this->threadManager, codeReader.getSymbolTable(),
            expressionParser.parseExpression(port),
            expressionParser.parseExpression(speed));
}
