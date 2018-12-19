#ifndef CODE_READER
    #define CODE_READER

#include <string>
#include <list>
#include <map>
#include <vector>
#include "Lexer.h"
#include "SymbolTable.h"

using namespace std;
/**
 * this class will handle to get the parameters to the commands if needed.
 */
class CodeReader {
private:
    int index;
    vector<string> codeTokens;
    SymbolTable* symbolTable;
    stack<int> blockEnds;
public:
    CodeReader(vector<string> codeLines, SymbolTable* st);
    /**
     * constructor
     * @param index number of current line
     * @param codeLines list of code lines
     */
    CodeReader(int index, vector<string> codeLines, SymbolTable* st);

    CodeReader(Lexer lexer, SymbolTable* st);

    CodeReader(Lexer lexer);

    void incrementIndex();

    void setIndex(int index);

    int getIndex() const;

    int getLength() const;

    int getRemainingTokens() const;

    bool isEndPoint();

    bool isRemainingToken(int tokens) const ;

    string peekNextToken();

    string getNextToken();
    /**
     * get the strings between brackets
     * @param startIndex of the current reading
     * @return string array that is inside the brackets
     */
    vector<string> getEntireBlock();/**
     * get the list of command from array
     * @param commands: the command array of the object that is kind of CommandParser
     * @param arr of string commands
     * @param length the length of the array
     * @return the number of cells it read, so the execute will be able to tell the parser
     */
    //int getCommandsFromArry(list<Command*> &commands, string *arr, int length);
    SymbolTable *getSymbolTable() const;

    void setVariable(string variable, double value);

    string getPreviousToken();          // not decrement index

    void markEndBlocks();

    bool isBlockEnd();
};


#endif //MILESTONE1_CODEREADER_H