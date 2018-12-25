#ifndef CODE_READER
    #define CODE_READER

#include <string>
#include <list>
#include <map>
#include <queue>
#include <vector>
#include "Lexer.h"
#include "SymbolTable.h"

using namespace std;
/**
 * this class will handle to get the parameters to the commands if needed.
 */
class CodeReader {
private:
    /* the index of current token  */
    int index;
    /* tokens of the given code */
    vector<string> codeTokens;
    /* table used to store information about variables in code.  */
    SymbolTable* symbolTable;
    /* list of block ends tokens used to mark the blocks in code. */
    queue<int> blockEnds;
public:
    /**
    * the constructor gets the code tokens and symbols table.
    * and creates CodeReader object that manage code tokens
    * @param st store information about variables in code
    * @param codeTokens list of code tokens
    */
    CodeReader(vector<string> codeTokens, SymbolTable* st);
    /**
    * the constructor gets the code tokens, index and symbols table.
    * and creates CodeReader object which manage the code tokens
    * @param index number of current line
    * @param codeTokens list of code tokens
    * @param st store information about variables in code
    */
    CodeReader(int index, vector<string> codeTokens, SymbolTable* st);
    /**
     * the constructor gets lexer of the code and symbols table.
     * and creates CodeReader object which manage the code tokens
     * @param lexer object used to generate the code tokens from code.
     * @param st store information about variables in code
     */
    CodeReader(Lexer lexer, SymbolTable* st);
    /**
    * the constructor gets lexer of the code.
    * and creates CodeReader object which manage the code tokens
    * (with empty symbol table)
    * @param lexer object used to generate the code tokens from code.
    */
    CodeReader(Lexer lexer);
    /**
     * incrementIndex method advance into the next token in code.
     */
    void incrementIndex();
    /**
     * setIndex method enables to jump into certain token in code.
     * @param tokenIndex index of the token
     */
    void setIndex(int tokenIndex);
    /**
     * getIndex method returns the index of current token
     * @return returns current token
     */
    int getIndex() const;
    /**
     * getLength method returns number of token in code
     * @return returns number of token in code
     */
    int getLength() const;
    /**
     * getRemainingTokens method returns the number of remaining tokens in code.
     * @return returns the number of remaining token in code.
     */
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

    virtual ~CodeReader();
};


#endif //MILESTONE1_CODEREADER_H