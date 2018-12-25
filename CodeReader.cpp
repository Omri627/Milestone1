#include "CodeReader.h"
#include "Lexer.h"
/**
 * the constructor gets lexer of the code and symbols table.
 * and creates CodeReader object which manage the code tokens
 * @param lexer object used to generate the code tokens from code.
 * @param st store information about variables in code
 */
CodeReader::CodeReader(Lexer lexer, SymbolTable* st) {
    this->codeTokens = lexer.getSplitFromFile();
    this->index = 0;
    this->symbolTable = st;
    this->markEndBlocks();
}
/**
* the constructor gets the code tokens and symbols table.
* and creates CodeReader object that manage code tokens
* @param st store information about variables in code
* @param codeTokens list of code tokens
*/
CodeReader::CodeReader(vector<string> codeTokens, SymbolTable* st) {
    this->codeTokens = codeTokens;
    this->index = 0;
    this->symbolTable = st;
    this->markEndBlocks();
}
/**
* the constructor gets the code tokens, index and symbols table.
* and creates CodeReader object which manage the code tokens
* @param index number of current line
* @param codeTokens list of code tokens
* @param st store information about variables in code
*/
CodeReader::CodeReader(int index, vector<string> codeLines, SymbolTable* st)
: symbolTable(st) {
    this->codeTokens = codeLines;
    this->index = index;
    this->markEndBlocks();
}
/**
* the constructor gets lexer of the code.
* and creates CodeReader object which manage the code tokens
* (with empty symbol table)
* @param lexer object used to generate the code tokens from code.
*/
CodeReader::CodeReader(Lexer lexer) {
    this->codeTokens = lexer.getSplitFromFile();
    SymbolTable* st = new SymbolTable;
    this->symbolTable = st;
    this->markEndBlocks();
}
/**
  * incrementIndex method advance into the next token in code.
  */
void CodeReader::incrementIndex() {
    this->index++;
}
/**
 * setIndex method enables to jump into certain token in code.
 * @param tokenIndex index of the token
 */
void CodeReader::setIndex(int index) {
    this->index = index;
}
/**
 * getIndex method returns the index of current token
 * @return returns current token
 */
int CodeReader::getIndex() const {
    return index;
}
/**
 * read the next token without progress of index.
 * @return next token of code
 */
string CodeReader::peekNextToken() {
    return this->codeTokens[this->index];
}
/**
 * read the next token and advance into the next token.
 * @return next token of code.
 */
string CodeReader::getNextToken() {
    this->index++;
    return this->codeTokens[this->index-1];
}
/**
  * getLength method returns number of token in code
  * @return returns number of token in code
  */
int CodeReader::getLength() const {
    return this->codeTokens.size();
}
/**
 * getRemainingTokens method returns the number of remaining tokens in code.
 * @return returns the number of remaining token in code.
 */
int CodeReader::getRemainingTokens() const {
    return this->getLength() - this->index;
}
/**
 * isRemainingToken method check whether there are given times of tokens left to read
 * @param tokens number of tokens
 * @return returns true if there are given amount of times of tokens left to read.
 * at any other case return false.
 */
bool CodeReader::isRemainingToken(int tokens) const {
    if (this->getRemainingTokens() >= tokens)
        return true;
    return false;
}
/**
  * isEndPoint method checks if there is no tokens left to read
  * @return boolean variable indicate whether code tokens read in its entirety
  */
bool CodeReader::isEndPoint() {
    if (this->getRemainingTokens() <= 0)
        return true;
    return false;
}
/**
 * get the strings between brackets
 * @param startIndex of the current reading
 * @return string array that is inside the brackets
 */
vector<string> CodeReader::getEntireBlock() {
    int endblockLine = -1;
    for (int i = this->index; i < this->getLength(); i++) {
        if (this->codeTokens[i] == "}") {
            endblockLine = i;
            break;
        }
    }
    vector<string>::iterator startBlock = this->codeTokens.begin() + index;
    vector<string>::iterator endBlock = this->codeTokens.begin() + endblockLine;
    vector<string> block(startBlock, endBlock);
    this->index += endblockLine;
    return block;
}
/**
 * setVariable method get variable and value.
 * and set the value of variable to given value
 * @param variable variable name
 * @param value value to change
 */
void CodeReader::setVariable(string name, double value) {
    this->symbolTable->setValue(name, value);
}
/**
 * getter method of symbol table field
 * @return returns symbol table object
 */
SymbolTable *CodeReader::getSymbolTable() const {
    return this->symbolTable;
}
/**
 * read pervious token
 * @return pervious token in code.
 */
string CodeReader::getPreviousToken() {
    if (this->index <= 0)
        throw "syntax error, parameter not defined";
    return this->codeTokens[this->index - 1];
}
/**
 * isBlockEnd method checks if current block end and
 * all the commands in block read.
 * @return true if current block ends
 * ay any other case returns false
 */
bool CodeReader::isBlockEnd() {
    if (this->index == this->blockEnds.front()) {
        this->blockEnds.pop();
        return true;
    }
    return false;
}
/**
 * isBlockEnd method checks if current block end and
 * all the commands in block read.
 * @return true if current block ends
 * ay any other case returns false
 */
void CodeReader::markEndBlocks() {
    int blocksAmount = 0;
    for (int i = 0; i < this->codeTokens.size(); i++) {
        if (this->codeTokens[i] == "{")
            blocksAmount++;
        if (this->codeTokens[i] == "}") {
            this->blockEnds.push(i);
            blocksAmount--;
        }
    }
    if (blocksAmount != 0)
        throw "invalid code";
}
/**
 * destructor, free memory
 */
CodeReader::~CodeReader() {
    this->codeTokens.clear();
}
