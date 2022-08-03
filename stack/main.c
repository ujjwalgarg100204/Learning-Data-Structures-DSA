#include <stdio.h>
#include <stdlib.h>

//#include "implementation/static_stack.h"
//#include "implementation/dynamic_stack.h"
#include "application/expression_parser.h"

#define MAX_LENGTH 100

int main(void) {
    String infix = calloc(MAX_LENGTH, sizeof(char));
    scanf("%s", infix);

    String postfix = infixToPostfix(infix);
//    String prefix = infixToPrefix(infix);
    double result = evaluatePostfix(postfix);
//    double result = evaluatePrefix(prefix);
    printf("Result: %f\n", result);

    free(infix);
//    free(prefix);
    free(postfix);
    return 0;
}
