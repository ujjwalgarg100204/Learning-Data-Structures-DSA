
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "small_applications_stack.h"

bool isPalindrome(char *str) {
    StackC *stack = newStackC();
    for (int i = 0; str[i] != '\0'; i++) {
        pushC(stack, str[i]);
    }

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != peekC(stack)) {
            freeStackC(stack);
            return false;
        }
        popC(stack);
    }

    freeStackC(stack);
    return true;
}

char *decimalToBinary(int dec) {
    StackI *stack = newStackI();
    while (dec != 0) {
        pushI(stack, dec % 2);
        dec /= 2;
    }

    int binarySize = stack->size + 1;
    char *bin = malloc(sizeof(char) * (binarySize));

    for (int i = 0; !isEmptyI(stack); ++i) {
        bin[i] = (char) (peekI(stack) + 48);
        popI(stack);
    }
    bin[binarySize - 1] = '\0';
    return bin;
}


