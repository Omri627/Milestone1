#include <iostream>
#include "PrintCommand.h"
PrintCommand::PrintCommand() {
}
int PrintCommand::execute(CodeReader& codeReader) {
    string strToPrint = codeReader.getNextToken();
    cout << strToPrint.substr(1, strToPrint.size()-2) << endl;
}