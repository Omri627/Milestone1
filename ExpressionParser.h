#ifndef EXPRESSION_PARSER
    #define EXPRESSION_PARSER

#include "SymbolTable.h"
#include <stack>
#include <queue>
#include "Number.h"
#include "Plus.h"
#include "Mul.h"
#include "Minus.h"
#include "Div.h"

class ExpressionParser {
private:
    SymbolTable * symbolTable;
    map<char, int> precedence;
public:
    enum char_type {
        NUMBER, OPERATOR, OPEN_BRACKET, CLOSE_BRACKET, VARIABLE, OTHER
    };
    ExpressionParser();

    ExpressionParser(SymbolTable* st);

    void setSymbolTable(SymbolTable* st);

    Expression *parseExpression(string expression);

    string shuntingYardAlgorithm(string expression);

    bool isValidExpression(string expression);

private:
    char_type getCharType(char ch) const;

    Expression *makeExpression(Expression *firstOperand, Expression *secondOperand, char op);
};


#endif
