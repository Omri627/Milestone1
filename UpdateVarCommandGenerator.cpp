#include "UpdateVarCommandGenerator.h"
#include "ExpressionParser.h"
#include "UpdateVarCommand.h"
/**
 * the constructor creates generator object which used to create update-var commands
 * @param server simulator server
 */
UpdateVarCommandGenerator::UpdateVarCommandGenerator(ClientServer *server) {
    this->server = server;
}
/**
 * create method creates new command object of updateVar type.
 * this commands used to update variables value.
 * if simulator server is connected and the variable is bound.
 * then the method updates the simulator.
 * @param codeReader code tokens
 * @return returns update var command object.
 */
Command *UpdateVarCommandGenerator::create(CodeReader &codeReader) {
    ExpressionParser expressionParser(codeReader.getSymbolTable());
    string var =  codeReader.getPreviousToken();             // get name of variable which we skipped
    if (codeReader.getNextToken() != "=")
        throw "syntax error: missing operator '='";
    string expression = codeReader.getNextToken();           // get expression
    UpdateVarCommand* command =  new UpdateVarCommand(var, expressionParser.parseExpression(expression), codeReader.getSymbolTable());
    command->setServer(this->server);
    return command;
}
/**
 * destructor, free memory
 */
UpdateVarCommandGenerator::~UpdateVarCommandGenerator() {
    this->server = nullptr;
}