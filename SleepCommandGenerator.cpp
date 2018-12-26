#include <iostream>
#include "SleepCommandGenerator.h"
/**
 * reads the parameter from the code script
 * and creates a sleep command with the given parameter
 * @param codeReader holds the code tokens
 * @return returns sleep command object
 */
Command *SleepCommandGenerator::create(CodeReader &codeReader) {
    /* throw exception in case no enough parameters was given */
    if (codeReader.isEndPoint())
        throw "invalid while command";
    string time = codeReader.getNextToken();
    try {
        return new SleepCommand(atoi(time.c_str()));
    } catch (...) {
        cout << "invalid sleep command parameter" << endl;
        exit(1);
    }
}

SleepCommandGenerator::~SleepCommandGenerator() {

}
