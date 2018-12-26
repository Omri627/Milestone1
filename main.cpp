#include <iostream>
#include <string>
#include <thread>
#include "ExpressionParser.h"
#include "Lexer.h"
#include "CodeParser.h"
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

}