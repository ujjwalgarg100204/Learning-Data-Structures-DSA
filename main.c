#include <stdio.h>
#include "data_structures/linked_list/circular_doubly/doubly_circular_ll.h"

void printArr(long long int *arr, int len);

int main(void) {
    LinkedList_D *list = newLinkedList_DC();
    ll arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    addAllList_DC(list, arr, sizeof(arr) / sizeof(arr[0]));
//    addFirstList_DC(list, 10);
//    addFirstList_DC(list, 20);
//    addFirstList_DC(list, 30);
//    addLastList_DC(list, 40);

    addAtList_DC(list, 4, 1000);
    addAtList_DC(list, 7, 1000);
    addAtList_DC(list, 9, 1000);
    addAtList_DC(list, 0, 1000);

    printList_DC(list);
    printf("\n");

    removeLastOccurList_DC(list, 1000);

    printList_DC(list);
    printf("\n");

    printArr(toArrayList_DC(list), sizeList_DC(list));

    freeLinkedList_DC(list);
}

void printArr(long long int *arr, int len) {
    for (int i = 0; i < len; i++) {
        printf("%lld ", arr[i]);
    }
}
