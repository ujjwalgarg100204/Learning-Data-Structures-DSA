#include <stdio.h>
#include <stdlib.h>

//#include "implementation/static_stack.h"
//#include "implementation/dynamic_stack.h"
#include "implementation/linked_stack.h"
//#include "application/expression_parser.h"
#include "application/small_applications_stack.h"


#define MAX_LENGTH 100

int main(void) {
    int dec = 5;
    char *bin = decimalToBinary(dec);

    printf("bin: %s\n", bin);
    printf("%d\n", isPalindrome(bin));
    free(bin);

    /* Stack *stack = newStack();
     for (int i = 0; i < 10; i++) {
         push(stack, i);
     }

     for (int i = 0; i < 10; i++) {
         printf("%d\n", peek(stack));
         pop(stack);
     }

     printf("%d\n", isEmpty(stack));
     freeStack(stack);*/
//    String infix = calloc(MAX_LENGTH, sizeof(char));
//    scanf("%s", infix);
//
//    String postfix = infixToPostfix(infix);
//    String prefix = infixToPrefix(infix);
//    double result = evaluatePostfix(postfix);
//    double result = evaluatePrefix(prefix);
//    printf("Result: %f\n", result);
//
//    free(infix);
//    free(prefix);
//    free(postfix);
    return 0;
}
