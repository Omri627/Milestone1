cmake_minimum_required(VERSION 3.13)
project(Project)

set(CMAKE_CXX_STANDARD 14)

add_executable(Project main.cpp SymbolTable.cpp SymbolTable.h Expression.h UnaryExpression.cpp UnaryExpression.h IfCommand.h Command.h IfCommand.cpp ConditionParser.cpp ConditionParser.h BInaryExpression.cpp BInaryExpression.h Plus.cpp Plus.h Minus.cpp Minus.h Mul.cpp Mul.h Div.cpp Div.h Neg.cpp Neg.h ExpressionParser.cpp ExpressionParser.h Number.cpp Number.h CodeReader.cpp CodeReader.h CodeParser.cpp CodeParser.h PrintCommand.cpp PrintCommand.h Lexer.cpp Lexer.h WhileCommand.cpp WhileCommand.h Expression.cpp Var.cpp Var.h OpenServerCommand.cpp OpenServerCommand.h CommandGenerator.cpp CommandGenerator.h UpdateVarCommandGenerator.cpp UpdateVarCommandGenerator.h UpdateVarCommand.cpp UpdateVarCommand.h DefineVarCommandGenerator.cpp DefineVarCommandGenerator.h DefineVarCommand.cpp DefineVarCommand.h ConditionParserGenerator.cpp ConditionParserGenerator.h)