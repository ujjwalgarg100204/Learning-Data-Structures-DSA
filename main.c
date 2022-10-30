#include <stdio.h>
#include "data_structures/stack/static_array_implementation.h"
#include "data_structures/stack/dynamic_array_implementation.h"

void printArr(long long int *arr, int len);

int main(void) {
    ll arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(arr) / sizeof(arr[0]);

    Stack_StArr *stack1 = newStack_StArr(size);
    for (int i = 0; i < size; i++)
        push_StArr(stack1, arr[i]);


    Stack_DyArr *stack2 = newStack_DyArr();
    for (int i = 0; i < size; i++)
        push_DyArr(stack2, arr[i]);

    while (!isEmpty_StArr(stack1))
        printf("%lld ", pop_StArr(stack1));

    printf("\n* Done with static Stack *\n");
    while (!isEmpty_DyArr(stack2)) {
        printf("%lld ", pop_DyArr(stack2));
    }
    printf("\n* Done with dynamic Stack *\n");

    freeStack_StArr(stack1);
    freeStack_DyArr(stack2);

    return 0;
}

void printArr(long long int *arr, int len) {
    for (int i = 0; i < len; i++) {
        printf("%lld ", arr[i]);
    }
}
