#include <algorithm>
#include "ExpressionParser.h"
#include "Expression.h"
#include "Var.h"
#include "Utils.h"

ExpressionParser::ExpressionParser() {
    this->precedence['+'] = 1;
    this->precedence['-'] = 1;
    this->precedence['*'] = 2;
    this->precedence['/'] = 2;
}
ExpressionParser::ExpressionParser(SymbolTable *st) : ExpressionParser() {
    this->symbolTable = st;
}
Expression* ExpressionParser::parseExpression(string expression) {
    stack <char > operators;
    queue < Expression * > operands;
    string prefix = this->shuntingYardAlgorithm(expression);
    Expression * firstOperand;
    Expression * secondOperand;
    string variableName = "";
    int num = 0;
    char_type charType;
    bool numberAddition = false, variableAddition = false;
    char currentChar;
    for (int i = prefix.size() -  1; i >= 0; i--) {
        currentChar = prefix[i];
        charType = getCharType(currentChar);
        if (charType == NUMBER) {
            num = num * 10 + (currentChar - '0');
            numberAddition = true;
        } else {
            if (numberAddition)
                operands.push(new Number(num));
            numberAddition = false;
            num = 0;
        }
        if (charType == VARIABLE) {
            variableName = variableName + currentChar;
            variableAddition = true;
        } else {
            if (variableAddition == true)
                operands.push(this->symbolTable->getVar(Utils::reverseStr(variableName)));
            variableAddition = false;
            variableName.clear();
        }
        if (charType == OPERATOR)
            operators.push(currentChar);
    }
    if (numberAddition)
        operands.push(new Number(num));
    if (variableAddition)
        operands.push(this->symbolTable->getVar(Utils::reverseStr(variableName)));
    while (!operators.empty()) {
        if (operands.size() < 2)
            throw "expression invalid";
        currentChar = operators.top();
        operators.pop();
        firstOperand = operands.front();
        operands.pop();
        secondOperand = operands.front();
        operands.pop();
        operands.push(this->makeExpression(firstOperand, secondOperand, currentChar));
    }
    return operands.front();
}
ExpressionParser::char_type ExpressionParser::getCharType(char ch) const {
    string allowedOperator = "+-*/";
    if (ch >= '0' && ch <= '9')
        return NUMBER;
    else if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')
        || ch == '_' || ch == '-')
        return VARIABLE;
    else if (allowedOperator.find(ch) != string::npos)
        return OPERATOR;
    else if (ch == ')')
        return CLOSE_BRACKET;
    else if (ch == '(')
        return OPEN_BRACKET;
    return OTHER;
}

Expression* ExpressionParser::makeExpression(Expression * firstOperand, Expression * secondOperand, char op)  {
    switch (op) {
        case '+': return new Plus(firstOperand, secondOperand);
        case '-': return new Minus(firstOperand, secondOperand);
        case '*': return new Mul(firstOperand, secondOperand);
        case '/': return new Div(firstOperand, secondOperand);
    }
}
string ExpressionParser::shuntingYardAlgorithm(string expression) {
    deque < char > postfix;
    stack< char > operators;
    for (int i = 0; i < expression.size(); i++) {
        switch (getCharType(expression[i])) {
            case NUMBER:
                postfix.push_back(expression[i]);
                break;
            case VARIABLE:
                postfix.push_back(expression[i]);
                break;
            case OPEN_BRACKET:
                operators.push('(');
                break;
            case OPERATOR:
                postfix.push_back(' ');
                while (!operators.empty() && operators.top() != '('
                    && precedence[operators.top()] > precedence[expression[i]]) {
                    postfix.push_back(operators.top());
                    operators.pop();
                }
                operators.push(expression[i]);
                break;
            case CLOSE_BRACKET:
                while (operators.top() != '(') {
                    postfix.push_back(operators.top());
                    operators.pop();
                }
                operators.pop();     // remove corresponding open bracket
            case OTHER:
                break;
        }
    }
    while (!operators.empty()) {
        postfix.push_back(operators.top());
        operators.pop();
    }
    string postfixString(postfix.begin(), postfix.end());
    postfix.clear();
    return postfixString;
}
bool ExpressionParser::isValidExpression(string expression) {
    int openBrackets = 0;                   // number  of remaining open brackets
    char_type prevChar;
    /* expression is invalid if it starts or ends with operator */
    //if (getCharType(expression.front()) == OPERATOR || getCharType(expression.back()) == OPERATOR)
      //  return false;
    for (int i = 0; i < expression.size(); i++) {
        switch (getCharType(expression[i])) {
            case NUMBER:
                prevChar = NUMBER;
                break;
            case OPEN_BRACKET:
                openBrackets++;
                prevChar = OPEN_BRACKET;
                break;
            case OPERATOR:
                if (prevChar == OPERATOR)
                    return false;
                prevChar = OPERATOR;
                break;
            case CLOSE_BRACKET:
                openBrackets--;
                if (openBrackets < 0)
                    return false;
                prevChar = CLOSE_BRACKET;
                break;
        }
    }
    if (openBrackets > 0)
        return false;
    return true;
}
void ExpressionParser::setSymbolTable(SymbolTable *st) {
    this->symbolTable = st;
}