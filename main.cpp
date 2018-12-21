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
    ThreadManager* threadManager = new ThreadManager;
    Lexer lexer;
    CodeParser *codeParser = new CodeParser(lexer, threadManager);
    codeParser->runCode();
    while (threadManager->isThereSubThread(0))
        sleep(1000);
    return 0;
    /*ExpressionParser expressionParser;
    SymbolTable symbolTable;
    expressionParser.setSymbolTable(symbolTable);
    symbolTable.addVariable("x", 3);
    symbolTable.addVariable("y", 5);
    symbolTable.addVariable("ran", 10);
    string expression = "3 * x + 2 * y";
    Expression * expObject = expressionParser.parseExpression(expression);
    double value = expObject->calculate();
    cout << value << endl;
    return 0; */
    //sleep(100000);

}