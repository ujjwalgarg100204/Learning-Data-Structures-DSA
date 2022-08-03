
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include <math.h>
#include "expression_parser.h"

int lengthWithoutParenthesis(String str);

int hasHigherPriority(char operator1, char operator2);

int findIndex(const char arr[], int size, char c);

String strrev(String str);

double charToDouble(char i);

double evaluate(double num1, char operat, double num2);

bool hasBalancedParenthesis(String expression) {
    StackC *stack = newStackC();
    unsigned int length = strlen(expression);

    for (int i = 0; i < length; i++) {
        // if opening bracket, then push to stack
        if (expression[i] == '(') {
            pushC(stack, '(');
        } else if (expression[i] == ')') {
            // if closing bracket found
            if (peekC(stack) != '(') {
                freeStackC(stack);
                return false;
            } else {
                popC(stack);
            }
        }
    }

    // if stack is not empty then brackets not balanced
    if (!isEmptyC(stack)) {
        freeStackC(stack);
        return false;
    }

    freeStackC(stack);
    return true;
}

String infixToPostfix(String infix) {
    StackC *stack = newStackC();
    unsigned int length = strlen(infix);
    String postfix = malloc(sizeof(char) * (lengthWithoutParenthesis(infix) + 1));  // 1 extra for '\0'

    int j = 0;
    for (int i = 0; i < length; i++) {
        // if operand is found put in postfix
        if (isalnum(infix[i])) {
            postfix[j++] = infix[i];
        } else if (isEmptyC(stack) || infix[i] == '(' || peekC(stack) == '(' ||
                   hasHigherPriority(peekC(stack), infix[i]) < 0) {
            // push operator to stack in case stack is empty or top of stack is open bracket
            pushC(stack, infix[i]);
        } else if (infix[i] == ')') {
            while (peekC(stack) != '(') {
                postfix[j++] = peekC(stack);
                popC(stack);
            }

            popC(stack);    // remove '(' from stack
        } else {
            // priority of current operator is equal to less than top of stack
            while (!isEmptyC(stack) && hasHigherPriority(peekC(stack), infix[i]) >= 0) {
                postfix[j++] = peekC(stack);
                popC(stack);
            }

            pushC(stack, infix[i]);
        }
    }

    // empty the stack to postfix
    while (!isEmptyC(stack)) {
        postfix[j++] = peekC(stack);
        popC(stack);
    }
    freeStackC(stack);

    postfix[j] = '\0';
    return postfix;
}

String infixToPrefix(String infix) {
    StackC *stack = newStackC();
    String prefix = malloc(sizeof(char) * (lengthWithoutParenthesis(infix) + 1));

    int length = (int) strlen(infix);

    int j = 0;
    // last char is '\0' which is not counted in strlen method so i = length works
    for (int i = length; i >= 0; --i) {
        if (isalnum(infix[i])) {
            prefix[j++] = infix[i];
        } else if (isEmptyC(stack) || infix[i] == ')' || hasHigherPriority(peekC(stack), infix[i]) <= 0) {
            pushC(stack, infix[i]);
        } else if (infix[i] == '(') {
            // empty stack till ')' is found
            while (peekC(stack) != ')') {
                prefix[j++] = peekC(stack);
                popC(stack);
            }

            popC(stack);    // remove ')'
        } else {
            while (!isEmptyC(stack) && hasHigherPriority(peekC(stack), infix[i]) > 0) {
                prefix[j++] = peekC(stack);
                popC(stack);
            }
            pushC(stack, infix[i]);
        }
    }

    // empty stack in prefix
    while (!isEmptyC(stack)) {
        prefix[j++] = peekC(stack);
        popC(stack);
    }

    prefix[j] = '\0';

    freeStackC(stack);
    return strrev(prefix);

}

double evaluatePrefix(String prefix) {
    StackD *stack = newStackD();
    int length = (int) strlen(prefix);

    for (int i = length; i >= 0; --i) {
        if (isdigit(prefix[i])) {
            pushD(stack, charToDouble(prefix[i]));
        } else {
            double op1 = peekD(stack);
            popD(stack);
            double op2 = peekD(stack);
            popD(stack);

            pushD(stack, evaluate(op1, prefix[i], op2));
        }
    }

    double result = peekD(stack);
    freeStackD(stack);
    return result;
}

double evaluatePostfix(String postfix) {
    StackD *stack = newStackD();
    int length = (int) strlen(postfix);

    for (int i = 0; i < length; i++) {
        if (isdigit(postfix[i])) {
            pushD(stack, charToDouble(postfix[i]));
        } else {
            double op1 = peekD(stack);
            popD(stack);
            double op2 = peekD(stack);
            popD(stack);

            pushD(stack, evaluate(op2, postfix[i], op1));
        }
    }

    double result = peekD(stack);
    freeStackD(stack);
    return result;
}

double evaluate(double num1, char operat, double num2) {
    switch (operat) {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        case '/':
            return num1 / num2;
        case '^':
            return pow(num1, num2);
        default:
            // dummy return statement
            return 0;
    }
}

double charToDouble(char i) {
    String num = malloc(sizeof(char) * 2);
    sprintf(num, "%c", i);
    double val = strtod(num, NULL);
    free(num);
    return val;
}

String strrev(String str) {
    unsigned int length = strlen(str);

    for (int i = 0; i < length / 2; ++i) {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
    return str;
}

int hasHigherPriority(char operator1, char operator2) {
    // special cases
    if ((operator1 == '+' && operator2 == '-') ||
        (operator1 == '-' && operator2 == '+') ||
        (operator1 == '*' && operator2 == '/') ||
        (operator1 == '/' && operator2 == '*')
            )
        return 0;

    const char PRIORITY_OF_OPERATOR[] = {'-', '+', '*', '/', '^'};
    int indexOperator1 = findIndex(PRIORITY_OF_OPERATOR, 5, operator1);
    int indexOperator2 = findIndex(PRIORITY_OF_OPERATOR, 5, operator2);

    if (indexOperator1 > indexOperator2) return 1;
    else if (indexOperator1 == indexOperator2) return 0;
    else return -1;
}

int findIndex(const char arr[], int size, char c) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == c) {
            return i;
        }
    }

    return -1;
}

int lengthWithoutParenthesis(String str) {
    int length = 1;
    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] == '(' || str[i] == ')') {
            continue;
        }
        length++;
    }
    return length;
}
