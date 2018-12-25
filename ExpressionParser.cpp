#include <iostream>
#include "ExpressionParser.h"
#include "Expression.h"
#include "Var.h"
#include "Utils.h"
#include "Neg.h"

/**
 * the constructor creates ExpressionParser object which has the abilities
 * to parse expression (convert string into expression object), split expression into tokens
 * convert infix expression into postfix representation and so on.
 * the constructor initializes precedence table of operators
 */
ExpressionParser::ExpressionParser() {
    this->precedence['+'] = 1;
    this->precedence['-'] = 1;
    this->precedence['*'] = 2;
    this->precedence['/'] = 2;
}
/**
 * the constructor get symbol-table and creates ExpressionParser object which has the abilities
 * to parse expression (convert string into expression object), split expression into tokens
 * convert inorder expression into postfix representation and so on.
 * the constructor initializes precedence table of operators and symbol-table.
 */
ExpressionParser::ExpressionParser(SymbolTable *st) : ExpressionParser() {
    this->symbolTable = st;
}
/**
 * setSymbolTable method sets symbol-table object (list of variables and their value)
 * @param st symbol table object
 */
void ExpressionParser::setSymbolTable(SymbolTable *st) {
    this->symbolTable = st;
}
/**
 * isGreaterPrecedence method gets two operation and determines which of the two actions has higher priority.
 * @param firstOperation first operation
 * @param secondOperation second operation
 * @return returns true if first operation has higher or equel precedence then second operation
 * at any other case returns false
 */
bool ExpressionParser::isGreaterPrecedence(string firstOperation, string secondOperation) {
    if (this->precedence[firstOperation[0]] >= this->precedence[secondOperation[0]])
        return true;
    return false;
}
/**
 * getExpressionTokens method gets expression string and split the expression into tokens.
 * this action facilitates the process of analyze and computing the mathematical expression
 * @param expression mathematical expression as string
 * @return returns vector filled with expression tokens.
 */
vector< ExpressionParser::token > ExpressionParser::getExpressionTokens(string expression) {
    vector< token > tokens;                      // list of expression tokens
    string operand = "";                         // operand builder
    string operation;                            // operation builder
    token_type pervType = OTHER, curType;                // token types of current and pervious char in expression
    /* run through expression chars, and creating tokens */
     for (int i = 0; i < expression.size(); i++) {
        pervType = curType;
        curType = getTokenType(expression[i]);
        if (pervType == VARIABLE && curType == NUMBER) {
            curType = pervType;
        } else if (operand != "" && pervType != curType) {
            tokens.push_back(make_pair(operand, pervType));
            operand.clear();
        }
        switch (getTokenType(expression[i])) {
            // build a number of digits that appear one after the other in the given expression
            case NUMBER:
                operand = operand + expression[i];
                break;
                // build a number of digits that appear one after the other in the given expression
            case VARIABLE:
                operand = operand + expression[i];
                break;
            case OPEN_BRACKET:
            case CLOSE_BRACKET:
                operation = expression[i];                          // get current operation
                tokens.push_back(make_pair(operation, curType));    // insert operation into tokens list
                break;
            case OPERATOR:
                if (pervType != NUMBER && pervType != VARIABLE && pervType != CLOSE_BRACKET) {
                    // that means this operation is unary.
                    curType = UNARY;
                }
                operation = expression[i];                          // get current operation
                tokens.push_back(make_pair(operation, curType));    // insert operation into tokens list
                break;
            case OTHER: // ignore redundant chars such as space
            curType = pervType;
                break;
        }
    }
    if (operand != "")
        tokens.push_back(make_pair(operand, curType));
    return tokens;
}
/**
 * shuntingYardAlgorithm method is method for parsing mathematical expressions specified in infix notation.
 * this method/algorithm produce a postfix notation for given expression
 * @param expression mathematical expression as string
 * @return queue of expression tokens ordered in postfix noation.
 */
deque < ExpressionParser::token  > ExpressionParser::shuntingYardAlgorithm(string expression) {
    deque < token > postfix;                             // postfix output: tokens ordered in postfix representation
    stack< token > operators;                            // stack storing the operators in given expression
    vector < token > expressionTokens = this->getExpressionTokens(expression);
    /* run through expression tokens */
    for (token token : expressionTokens) {
        switch (token.second) {
            /* the token is operand number or variable, then: push it to the output queue */
            case UNARY:
            case NUMBER:
            case VARIABLE:
                postfix.push_back(token);
                break;
            case OPERATOR:
                /* there is an operator at the top of the operator stack with greater or equal precedence)
                   and the operator at the top of the operator stack is not a left bracket
                   pop operators from the operator stack onto the output queue. */
                while (!operators.empty() && !operators.top().second != OPEN_BRACKET &&
                    isGreaterPrecedence(operators.top().first, token.first)) {
                    postfix.push_back(operators.top());
                    operators.pop();
                }
                operators.push(token);
                break;
            case OPEN_BRACKET:
                /* if the token is a open bracket (i.e. "("), then: push it onto the operator stack. */
                operators.push(token);
                break;
            case CLOSE_BRACKET:
                /* pop operators from the operator stack onto the output queue till the operator
                 * at the top of operator stack is open bracket*/
                while (!operators.empty() && operators.top().second != OPEN_BRACKET) {
                    postfix.push_back(operators.top());
                    operators.pop();
                }
                operators.pop();          // get rid of open bracket
        }
    }
    while (!operators.empty()) {
        postfix.push_back(operators.top());
        operators.pop();
    }
    return postfix;
}

Expression* ExpressionParser::parseExpression(string expression) {
    stack < Expression * > operands;        // queue storing the operands in expression
    Expression * firstOperand;              // first operand
    Expression * secondOperand;             // second operand
    deque < token > postfixTokens;          // queue of expression tokens ordered in postfix noation.
    double number;                             // temporary storage for numbers
    postfixTokens = this->shuntingYardAlgorithm(expression);    // shunting yard algorithm
    bool negative = false;
    /* run through tokens in postfix notation of given expression */
    while (!postfixTokens.empty()) {
        token token = postfixTokens.front();
        switch (token.second) {
            case OPERATOR:
                if (operands.size() < 2)
                    throw "expression invalid";
                /* creates expression */
                secondOperand = operands.top();
                operands.pop();
                firstOperand = operands.top();
                operands.pop();
                operands.push(this->makeExpression(firstOperand, secondOperand, token.first));
                break;
            case UNARY:
                if (token.first == "-")
                    negative = true;
                break;
            case NUMBER:
                // convert number token string into Number object
                number = atof(token.first.c_str());
                if (negative == true)
                    number = (-1) * number;
                negative = false;
                operands.push(new Number(number));
                break;
            case VARIABLE:
                // convert variable token string into Variable object
                Expression * var = this->symbolTable->getVar(token.first);
                if (negative == true)
                    var = new Neg(var);
                negative = false;
                operands.push(var);
                break;
        }
        postfixTokens.pop_front();
    }
    if (operands.size() > 1)
        throw "expression is invalid";
    return operands.top();
}

bool ExpressionParser::isValidExpression(string expression) {
    int openBrackets = 0;                   // number  of remaining open brackets
    /* run through expression characters */
    for (int i = 0; i < expression.size(); i++) {
        if (this->getTokenType(expression[i]) == OPEN_BRACKET)
            openBrackets++;
        if (this->getTokenType(expression[i]) == CLOSE_BRACKET)
            if (--openBrackets < 0)
                return false;
    }
    /* number of open and close brackets does not fit */
    if (openBrackets != 0)
        return false;
    /* expression cannot ends with operator. */
    if (this->getTokenType(expression.back()) == OPERATOR)
        return false;
    return true;
}
ExpressionParser::token_type ExpressionParser::getTokenType(char ch) const {
    string allowedOperator = "+-*/";
    string allowedVariable = "_@#";
    if (ch >= '0' && ch <= '9' || ch == '.')
        return NUMBER;
    else if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')
             || allowedVariable.find(ch) != string::npos)
        return VARIABLE;
    else if (allowedOperator.find(ch) != string::npos)
        return OPERATOR;
    else if (ch == ')')
        return CLOSE_BRACKET;
    else if (ch == '(')
        return OPEN_BRACKET;
    return OTHER;
}
Expression* ExpressionParser::makeExpression(Expression * firstOperand, Expression * secondOperand, string op)  {
    switch (op[0]) {
        case '+': return new Plus(firstOperand, secondOperand);
        case '-': return new Minus(firstOperand, secondOperand);
        case '*': return new Mul(firstOperand, secondOperand);
        case '/': return new Div(firstOperand, secondOperand);
    }
    throw  "invalid operation";
}
void ExpressionParser::printPostfixNotation(string expression) {
    deque < token  > tokensPostfix = this->shuntingYardAlgorithm(expression);
    while (!tokensPostfix.empty()) {
        cout << tokensPostfix.front().first << " ";
        tokensPostfix.pop_front();
    }
    cout << endl;
}
ExpressionParser::~ExpressionParser() {
    this->precedence.clear();
}
