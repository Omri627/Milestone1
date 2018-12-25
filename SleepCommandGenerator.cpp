#include "SleepCommandGenerator.h"
/**
 * reads the parameter from the code script
 * and creates a sleep command with the given parameter
 * @param codeReader holds the code tokens
 * @return returns sleep command object
 */
Command *SleepCommandGenerator::create(CodeReader &codeReader) {
    string time = codeReader.getNextToken();
    return new SleepCommand(atoi(time.c_str()));
}

SleepCommandGenerator::~SleepCommandGenerator() {

}
