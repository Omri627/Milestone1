#include "WhileCommandGenerator.h"
#include "ConditionParserGenerator.h"

WhileCommandGenerator::WhileCommandGenerator() {
}
WhileCommandGenerator::WhileCommandGenerator(list<Command *> commands) : ConditionParserGenerator(commands) {
}
Command* WhileCommandGenerator::create(CodeReader &codeReader) {
    ExpressionParser expressionParser(codeReader.getSymbolTable());
    string leftExpression = codeReader.getNextToken();
    string relation = codeReader.getNextToken();
    string rightExpression = codeReader.getNextToken();
    if (codeReader.getNextToken() != "{")
        throw "invalid expression";
    WhileCommand* ifCommand = new WhileCommand(expressionParser.parseExpression(rightExpression),
                                         expressionParser.parseExpression(leftExpression), relation);
    return  ifCommand;
}
