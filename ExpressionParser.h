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
    enum token_type {
        NUMBER, OPERATOR, UNARY , OPEN_BRACKET, CLOSE_BRACKET, VARIABLE, OTHER
    };
    typedef pair<string, token_type> token;

    ExpressionParser();

    ExpressionParser(SymbolTable* st);

    void setSymbolTable(SymbolTable* st);

    Expression *parseExpression(string expression);

    deque < token > shuntingYardAlgorithm(string expression);

    vector< token > getExpressionTokens(string expression);

    bool isValidExpression(string expression);

    void printPostfixNotation(string expression);

    virtual ~ExpressionParser();

private:
    bool isGreaterPrecedence(string firstOperation, string secondOperation);

    token_type getTokenType(char ch) const;

    Expression *makeExpression(Expression *firstOperand, Expression *secondOperand, string op);
};


#endif
