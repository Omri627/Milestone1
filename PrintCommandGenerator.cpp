#include "PrintCommandGenerator.h"
#include "Var.h"

/**
* create PrintCommand
* @param codeReader: codeReader so create can get his params
* @return new Command
 */
Command* PrintCommandGenerator::create(CodeReader &codeReader) {
    string str = codeReader.getNextToken();
    if (str.find("\"") == string::npos) {
        //the string to print is var
        return new PrintCommand(codeReader.getSymbolTable(), str);
    } else {
        str = str.substr(1, str.size() - 2);
        return new PrintCommand(str);
    }
}