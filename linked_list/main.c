#include <stdio.h>
#include "implementation/linked_list.h"

int main(void) {
    LinkedList *linkedList = newLinkedList();
    addFirst(linkedList, 1);
    addLast(linkedList, 2);
    printf("Int at %d: %d\n", 1, getIntAt(linkedList, 1));
//    deleteIntAt(linkedList, 1);
    deleteIntAt(linkedList, 0);
    setIntAt(linkedList, 1, 1000);
    printf("%d\n", getIntAt(linkedList, 1));
    contains(linkedList, 0) ? printf("List contains 0\n") : printf("List doesn't contain 0\n");
    isValidIndex(linkedList, 0) ? printf("3 is valid index\n") : printf("3 is invalid index");

    freeLinkedList(linkedList);
    return 0;
}
