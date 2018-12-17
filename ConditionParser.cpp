#include "ConditionParser.h"
#include "Expression.h"
ConditionParser::ConditionParser(list<Command *> commands, Expression *rightExpression, Expression *leftExpression,
                                 Expression::Relation relation) {
        this->rightExpression = rightExpression;
        this->leftExpression = leftExpression;
        this->commands = commands;
        this->relation = relation;
}
void ConditionParser::setCondition(Expression * left, Expression * right, Expression::Relation relation) {
    this->leftExpression = leftExpression;
    this->rightExpression = rightExpression;
    this->relation = relation;
}

bool ConditionParser::checkCondition() {
    if (!this->rightExpression || !this->leftExpression)
        throw "condition did not defined";
    switch (this->relation) {
        case Expression::G:
            return this->leftExpression > this->rightExpression;
        case Expression::GE:
            return this->leftExpression >= this->rightExpression;
        case Expression::LE:
            return this->leftExpression <= this->rightExpression;
        case Expression::L:
            return this->leftExpression < this->rightExpression;
        case Expression::E:
            return this->leftExpression == this->rightExpression;
    }
}

const list<Command *> &ConditionParser::getCommands() const {
    return this->commands;
}
