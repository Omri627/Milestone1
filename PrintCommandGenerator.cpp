#include "PrintCommandGenerator.h"
Command* PrintCommandGenerator::create(CodeReader &codeReader) {
    string strToPrint = codeReader.getNextToken();
    return new PrintCommand(strToPrint);
}