//
// Created by ujjwalgarg on 3/8/22.
//

#ifndef DSA1_EXPRESSION_PARSER_H
#define DSA1_EXPRESSION_PARSER_H

#include "../implementation/dynamic_stack.h"

typedef char *String;

bool hasBalancedParenthesis(String expression);

String infixToPrefix(String infix);

String infixToPostfix(String infix);

double evaluatePrefix(String prefix);

double evaluatePostfix(String postfix);

#endif //DSA1_EXPRESSION_PARSER_H
