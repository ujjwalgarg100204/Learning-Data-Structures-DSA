#include <stdio.h>
#include <stdlib.h>

//#include "implementation/static_stack.h"
//#include "implementation/dynamic_stack.h"
#include "application/expression_parser.h"

#define MAX_LENGTH 100

int main(void) {
    String infix = malloc(sizeof(char) * MAX_LENGTH);
    scanf("%s", infix);

    String postfix = infixToPostfix(infix);
    double result = evaluatePostfix(postfix);

    printf("Result: %f\n", result);

    free(infix);
    free(postfix);
    return 0;
}
