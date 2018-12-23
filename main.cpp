#include <iostream>
#include <string>
#include <thread>
#include "ExpressionParser.h"
#include "Lexer.h"
#include "CodeParser.h"
#include "Utils.h"
#include "pthread.h"

using namespace std;
int main() {
    const int mainThread = 0;
    ThreadManager* threadManager = new ThreadManager;
    Lexer lexer;
    CodeParser *codeParser = new CodeParser(lexer, threadManager);
    codeParser->runCode();
    threadManager->closeMainThread();
    return 0;
    /*ExpressionParser expressionParser;
    SymbolTable* symbolTable = new SymbolTable;
    expressionParser.setSymbolTable(symbolTable);
    symbolTable->addVariable("x", 3);
    symbolTable->addVariable("y", 5);
    symbolTable->addVariable("ran", 10);
    string expression = "5 + 0.5 * x ";
    Expression *expObject = expressionParser.parseExpression(expression);
    double value = expObject->calculate();
    cout <<  "before: " << expression << endl << endl;
    cout <<  "after: ";
    expressionParser.printPostfixNotation(expression);
    expObject->printExpression();
    cout << value << endl;
    */
}