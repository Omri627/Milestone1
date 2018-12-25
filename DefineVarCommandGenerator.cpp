#include "DefineVarCommandGenerator.h"
#include "DefineVarCommand.h"
#include "DefineVarBindCommand.h"
#include "ExpressionParser.h"
/**
 * create method creates new define var command object
 * with paramters received by code.
 * @param codeReader code tokens
 * @return new define var command
 */
Command *DefineVarCommandGenerator::create(CodeReader &codeReader) {
    const int commandParameters = 2;            // number of parameters should be transmitted to command
    string var;                                 // variable name
    string expression;                          // expression represent the new value of variable
    bool isBind = false;                        // indicate whether this var bound to server
    /* throw exception in case no enough parameters was given */
    if (!codeReader.isRemainingToken(commandParameters))
        throw "invalid open server command: no enough parameters transmitted";
    var = codeReader.getNextToken();           // get parameter variable name
    ExpressionParser expressionParser(codeReader.getSymbolTable());
    if (codeReader.getNextToken() != "=")
        throw "syntax error: missing operator '='";
    /* define new variable bound to server */
    if (codeReader.peekNextToken() == "bind") {
        isBind = true;
        codeReader.getNextToken();
        string path = codeReader.getNextToken();
        return new DefineVarBindCommand(var, path, codeReader.getSymbolTable());
    }
    /* define variables that doesnt bound to server */
    expression = codeReader.getNextToken();
    return new DefineVarCommand(var, expressionParser.parseExpression(expression)->calculate(), codeReader.getSymbolTable());
}

DefineVarCommandGenerator::~DefineVarCommandGenerator() {
}
