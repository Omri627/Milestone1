
#include "IfCommandGenerator.h"
IfCommandGenerator::IfCommandGenerator() {

}
Command* IfCommandGenerator::create(CodeReader &codeReader) {
    ExpressionParser expressionParser(codeReader.getSymbolTable());
    string leftExpression = codeReader.getNextToken();
    string relation = codeReader.getNextToken();
    string rightExpression = codeReader.getNextToken();
    if (codeReader.getNextToken() != "{")
        throw "invalid expression";
    this->generateBlockCommands();
    IfCommand* ifCommand = new IfCommand(this->getBlockCommands(), expressionParser.parseExpression(rightExpression),
                                         expressionParser.parseExpression(leftExpression), relation);
    return ifCommand;
}
