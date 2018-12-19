#include "CodeReader.h"
#include "Lexer.h"

CodeReader::CodeReader(Lexer lexer, SymbolTable* st) {
    this->codeTokens = lexer.getSplitFromFile("script.txt");
    this->index = 0;
    this->symbolTable = st;
    this->markEndBlocks();
}
CodeReader::CodeReader(vector<string> codeLines, SymbolTable* st) {
    this->codeTokens = codeLines;
    this->index = 0;
    this->symbolTable = st;
    this->markEndBlocks();
}
CodeReader::CodeReader(int index, vector<string> codeLines, SymbolTable* st)
: symbolTable(st) {
    this->codeTokens = codeLines;
    this->index = index;
    this->markEndBlocks();
}
CodeReader::CodeReader(Lexer lexer) {
    this->codeTokens = lexer.getSplitFromFile("script.txt");
    SymbolTable* st = new SymbolTable;
    this->symbolTable = st;
    this->markEndBlocks();
}
void CodeReader::incrementIndex() {
    this->index++;
}
void CodeReader::setIndex(int index) {
    this->index = index;
}

int CodeReader::getIndex() const {
    return index;
}

string CodeReader::getNextToken() {
    this->index++;
    return this->codeTokens[this->index-1];
}

int CodeReader::getLength() const {
    return this->codeTokens.size();
}
int CodeReader::getRemainingTokens() const {
    return this->getLength() - this->index;
}
bool CodeReader::isRemainingToken(int tokens) const {
    if (this->getRemainingTokens() >= tokens)
        return true;
    return false;
}
bool CodeReader::isEndPoint() {
    if (this->getRemainingTokens() <= 0)
        return true;
    return false;
}
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
void CodeReader::setVariable(string name, double value) {
    this->symbolTable->setValue(name, value);
}

SymbolTable *CodeReader::getSymbolTable() const {
    return this->symbolTable;
}
string CodeReader::getPreviousToken() {
    if (this->index <= 0)
        throw "syntax error, parameter not defined";
    return this->codeTokens[this->index - 1];
}
bool CodeReader::isBlockEnd() {
    if (this->index == this->blockEnds.top())
        return true;
    return false;
}
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