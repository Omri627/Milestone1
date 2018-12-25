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
    /**
     * isEndPoint method checks if there is no tokens left to read
     * @return boolean variable indicate whether code tokens read in its entirety
     */
    bool isEndPoint();
    /**
     * isRemainingToken method check whether there are given times of tokens left to read
     * @param tokens number of tokens
     * @return returns true if there are given amount of times of tokens left to read.
     * at any other case return false.
     */
    bool isRemainingToken(int tokens) const ;
    /**
     * read the next token without progress of index.
     * @return next token of code
     */
    string peekNextToken();
    /**
     * read the next token and advance into the next token.
     * @return next token of code.
     */
    string getNextToken();
    /**
     * get the strings between brackets
     * @param startIndex of the current reading
     * @return string array that is inside the brackets
     */
    vector<string> getEntireBlock();
    /**
     * getter method of symbol table field
     * @return returns symbol table object
     */
    SymbolTable *getSymbolTable() const;
    /**
     * setVariable method get variable and value.
     * and set the value of variable to given value
     * @param variable variable name
     * @param value value to change
     */
    void setVariable(string variable, double value);
    /**
     * read pervious token
     * @return pervious token in code.
     */
    string getPreviousToken();
    /**
     * markEndBlocks method marked the blocks in code
     * in practise, he inserts end of blocks tokens into queue structure.
     */
    void markEndBlocks();
    /**
     * isBlockEnd method checks if current block end and
     * all the commands in block read.
     * @return true if current block ends
     * ay any other case returns false
     */
    bool isBlockEnd();
    /**
    * destructor, free memory
    */
    virtual ~CodeReader();
};


#endif //MILESTONE1_CODEREADER_H