#include "PrintCommandGenerator.h"
#include "Var.h"

/**
* create PrintCommand
* @param codeReader: codeReader so create can get his params
* @return new Command
 */
Command* PrintCommandGenerator::create(CodeReader &codeReader) {
    const int commandParameters = 1;
    string str;
    /* throw exception in case no enough parameters was given */
    if (!codeReader.isRemainingToken(commandParameters))
        throw "invalid open server command: no enough parameters transmitted";
    str = codeReader.getNextToken();
    if (str[0] != '\"') {
        //the string to print is var
        return new PrintCommand(codeReader.getSymbolTable(), str);
    } else {
        if (str != "") { //just in case, making sure str not equal ""
            str = str.substr(1, str.size() - 2);
            return new PrintCommand(str);
        }

    }
}
/**
 * destructor, free memory
 */
PrintCommandGenerator::~PrintCommandGenerator() {

}
