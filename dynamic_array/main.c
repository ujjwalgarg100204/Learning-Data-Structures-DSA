#include <stdio.h>

#include "implementation/dynamic_array.h"

void printArr(int *arr, int size);


int main(void) {
    DynamicArrayI *arr = newDynamicArrayI();

    int choice;
    do {
        printf("\nDynamic Array menu\n\t1. Add to arr\n\t2. Add to specific index\n\t3. Delete specific index"
               "\n\t4. Does it contain this value?\n\t5. Get the value at index\n\t6. Set value at index\n\t->-1. Exit\n*Choice:");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int element;
                printf("*Element:");
                scanf("%d", &element);

                addAtLastI(arr, element);
                break;
            }
            case 2: {
                int element, index;
                printf("*Element:");
                scanf("%d", &element);
                printf("*Index:");
                scanf("%d", &index);

                addAtIndexI(arr, index, element);
                break;
            }
            case 3: {
                int ind;
                printf("*Index:");
                scanf("%d", &ind);

                removeAtIndexI(arr, ind);
                break;
            }
            case 4: {
                int val;
                printf("Val:");
                scanf("%d", &val);

                containsI(arr, val) ? printf("*Yes, array contains the value\n") : printf(
                        "Nope, array doesn't contain the value\n");
                break;
            }
            case 5: {
                int index;
                printf("*Index:");
                scanf("%d", &index);

                printf("** arr[%d] = %d\n", index, getI(arr, index));
                break;
            }
            case 6: {
                int index, value;
                printf("*Index");
                scanf("%d", &index);
                printf("*Value:");
                scanf("%d", &value);

                setI(arr, index, value);
            }
            case -1:
                break;
            default:
                printf("*Invalid Choice\n");
        }

        if (choice != -1) {
            printf("Array:\n\t");
            printArr(arr->arr, arr->size);
        }
    } while (choice != -1);
    printf("Exiting\n");
    freeDynamicArrayI(arr);
    return 0;
}

void printArr(int *arr, int size) {
    for (int i = 0; i < size; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

