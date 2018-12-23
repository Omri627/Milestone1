//
// Created by ranraboh on 16/12/18.
//

#include "UpdateVarCommandGenerator.h"
#include "ExpressionParser.h"
#include "UpdateVarCommand.h"
UpdateVarCommandGenerator::UpdateVarCommandGenerator(ClientServer *server) {
    this->server = server;
}
Command *UpdateVarCommandGenerator::create(CodeReader &codeReader) {
    ExpressionParser expressionParser(codeReader.getSymbolTable());
    string var =  codeReader.getPreviousToken();             // get name of variable which we skipped
    if (codeReader.getNextToken() != "=")
        throw "syntax error: missing operator '='";
    string expression = codeReader.getNextToken();           // get expression
    UpdateVarCommand* command =  new UpdateVarCommand(var, expressionParser.parseExpression(expression), codeReader.getSymbolTable());
    if (!this->server)
        cout << "command->setServer()" << endl;
        command->setServer(this->server);
    return command;
}
