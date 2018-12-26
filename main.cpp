#include <iostream>
#include <string>
#include <thread>
#include "ExpressionParser.h"
#include "Lexer.h"
#include "CodeParser.h"
#include "Utils.h"
#include "pthread.h"

using namespace std;

int main(int argc, char *argv[]) {

    if (argc >= 2) {
        string fileName = string(argv[1]);
        Lexer lexer(fileName);
        ThreadManager* threadManager = new ThreadManager;
        CodeParser *codeParser = new CodeParser(lexer, threadManager);
        codeParser->runCode();
        threadManager->closeMainThread();
    }
    cout << "No file name given" << endl;
    return 0;
    /*ExpressionParser expressionParser;
    SymbolTable* symbolTable = new SymbolTable;
    expressionParser.setSymbolTable(symbolTable);
    symbolTable->addVariable("x", 3);
    symbolTable->addVariable("h0", 5);
    symbolTable->addVariable("heading", 10);
    string expression = "  (h0 - heading)/20 ";
    Expression *expObject = expressionParser.parseExpression(expression);
    double value = expObject->calculate();
    cout <<  "before: " << expression << endl << endl;
    cout <<  "after: ";
    expressionParser.printPostfixNotation(expression);
    expObject->printExpression();
    cout << endl;
    cout << value << endl;*/
}