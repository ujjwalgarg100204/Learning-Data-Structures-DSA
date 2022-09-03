#include <stdlib.h>
#include <stdio.h>

#include "linkedlist_c.h"
#include "../node/char/node_singly_c.h"

struct LinkedList {
    Node *head;
};

/*
 * Inserts a new node with passed data after given node
 * Will NOT work if node is NULL
 */
Node *insertAfter(Node *node, char data);

/*
 * Removes a node after the provided node
 * Will NOT work if node provided has next as NULL
 */
void removeNext(Node *node);


/*
 * Frees all memory for all the nodes in the list and sets head of
 * list to NULL
 */
void freeAllNodes(LinkedList *list);

/*
 * Creates a new linked list and returns a ptr to new list
 */
LinkedList *newLinkedList() {
    LinkedList *list = malloc(sizeof(LinkedList));
    list->head = NULL;
    return list;
}

/*
 * Frees the linked list and frees each node in the list
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
void freeLinkedList(LinkedList *list) {
    freeAllNodes(list);
    free(list);
}

/*
 * Adds element at the specified index
 * Returns true if addition of new element is successful else false
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
bool addAt(LinkedList *list, int index, char element) {
    if (index == 0) {
        addFirst(list, element);
        return true;
    } else if (list->head == NULL) {
        // don't do anything to the uninitialized list
        return false;
    }

    // iterate to the node one before node
    Node *curr = list->head;
    while (index != 1 && curr != NULL) {
        curr = getNext(curr);
        index--;
    }
    if (curr == NULL) {
        // invalid index found
        return false;
    }

    // attach the node in the list
    insertAfter(curr, element);
    return true;
}

/*
 * Adds element at the last of the list
 * Can be used to initialize the list
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
void addLast(LinkedList *list, char element) {
    // if list is initialized addLast and addFirst do the same work
    if (list->head == NULL) {
        addFirst(list, element);
        return;
    }

    // iterate towards the last of the list, and add the new node
    Node *curr;
    for (curr = list->head; getNext(curr) != NULL; curr = getNext(curr));
    insertAfter(curr, element);
}
/*
 * Adds all the elements of the array to the linked list, in the same order as they
 * occur
 * Returns true if addition is successful else false
 * Time Complexity: O(m+n)
 * Space Complexity: O(1)
 */
bool addAll(LinkedList *list, const char *arr, int lengthOfArr) {
    if (arr == NULL) {
        // return if array is empty
        return false;
    }

    // create a new linked list by starting from the last of the array
    // and add each element of the array at the head of the new list
    Node *head = newNode(arr[lengthOfArr - 1]);
    for (int i = lengthOfArr - 2; i >= 0; i--) {
        Node *new = newNode(arr[i]);
        setNext(new, head);
        head = new; // make the new node as new head
    }

    if (list->head == NULL) {
        list->head = head;
    } else {
        Node *curr = list->head;
        while (getNext(curr) != NULL) { curr = getNext(curr); }
        setNext(curr, head);
    }
    return true;
}

/*
 * Adds element at the first position of the list
 * Can be used to initialize the list
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */
void addFirst(LinkedList *list, char element) {
    Node *node = newNode(element);
    setNext(node, list->head);
    list->head = node;
}

/*
 * Empties the list
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
void clear(LinkedList *list) {
    freeAllNodes(list);
}

/*
 * Creates a copy of the list passed and returns the new copy of list
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
LinkedList *clone(const LinkedList *list) {
    if (list->head == NULL) {
        return NULL;
    }

    LinkedList *cloned = newLinkedList();
    // initialize the cloned list with given list's head
    cloned->head = newNode(getData(list->head));

    Node *clonedHead = cloned->head;
    for (Node *curr = getNext(list->head); curr != NULL; curr = getNext(curr)) {
        insertAfter(clonedHead, getData(curr));
        clonedHead = getNext(clonedHead);
    }

    return cloned;
}
/*
 * Returns true if element is present in list else false
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
bool contains(const LinkedList *list, char element) {
    for (Node *curr = list->head; curr != NULL; curr = getNext(curr)) {
        if (element == getData(curr)) { return true; }
    }
    return false;
}

/*
 * Returns element present at first position
 * NOTE: If list is uninitialized, GARBAGE VALUE is returned
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */
char getFirst(const LinkedList *list) {
    if (list->head == NULL) {
        return -1;
    }
    return getData(list->head);
}

/*
 * Returns last element present at last position of the list
 * NOTE: If list is uninitialized, GARBAGE VALUE is returned
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
char getLast(const LinkedList *list) {
    if (list->head == NULL)
        return -1;

    Node *end = list->head;
    while (getNext(end) != NULL) { end = getNext(end); }
    return getData(end);
}

/*
 * Returns element present at the specified index
 * NOTE: If list is uninitialized or index passed is invalid, GARBAGE VALUE is returned
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
char getAt(const LinkedList *list, int index) {
    if (list->head == NULL) {
        return -1;
    }
    // iterate to index of list
    Node *curr;
    for (curr = list->head; curr != NULL && index != 0; curr = getNext(curr), index--);

    // if invalid index return -1
    if (curr == NULL) {
        return -1;
    }

    return getData(curr);
}

/*
 * Returns the last index at which specified element is present
 * -1 is returned if element is not present in the list or if the list is
 * uninitialized
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
int lastIndexOf(const LinkedList *list, char element) {
    int lastIndex = -1;
    int i = 0;
    for (Node *curr = list->head; curr != NULL; curr = getNext(curr)) {
        if (getData(curr) == element) { lastIndex = i; }
        i++;
    }
    return lastIndex;
}

/*
 * Removes the first element from the list and returns the element
 * NOTE: A GARBAGE VALUE is returned if list is uninitialized
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
char removeFirst(LinkedList *list) {
    if (list->head == NULL) {
        // don't do anything if list is empty
        return -1;
    }
    // save data of the head that is to be returned
    char headData = getData(list->head);

    // set the next to head as new head
    Node *next = getNext(list->head);
    freeNode(list->head);
    list->head = next;

    return headData;
}

/*
 * Removes the last element from the list and returns the element
 * NOTE: A GARBAGE VALUE is returned if list is  uninitialized
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
char removeLast(LinkedList *list) {
    if (list->head == NULL) {
        return -1;
    } else if (getNext(list->head) == NULL) {
        char last = getData(list->head);
        // only 1 node in the list
        freeNode(list->head);
        list->head = NULL;
        return last;
    }

    // iterate to the last of the list
    Node *end;
    for (end = list->head; getNext(getNext(end)) != NULL; end = getNext(end));

    char last = getData(getNext(end));
    removeNext(end);
    return last;
}
/*
 * Removes first occurrence of the element in list, and returns true if successful
 * if the element is not present in the list, then returns false
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
bool removeFirstOccur(LinkedList *list, char element) {
    if (list->head == NULL) {
        return false;
    } else if (getData(list->head) == element) {
        removeFirst(list);
        return true;
    }

    Node *beforeNode = list->head;
    while (getNext(beforeNode) != NULL && getData(getNext(beforeNode)) != element) {
        beforeNode = getNext(beforeNode);
    }

    // couldn't find the element
    if (getNext(beforeNode) == NULL) { return false; }

    removeNext(beforeNode);
    return true;
}

/*
 * Remove element at the given index and returns the element
 * If index is invalid garbage value is returned
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
char removeAt(LinkedList *list, int index) {
    if (list->head == NULL) {
        return -1;
    } else if (index == 0) {
        return removeFirst(list);
    }

    // iterate 1 element before the index
    Node *beforeIndex = list->head;
    while (index != 1 && beforeIndex != NULL) {
        beforeIndex = getNext(beforeIndex);
        index--;
    }
    // if index is invalid return GARBAGE VALUE
    if (beforeIndex == NULL || getNext(beforeIndex) == NULL) {
        return -1;
    }
    char element = getData(getNext(beforeIndex));
    removeNext(beforeIndex);
    return element;
}

/*
 * Removes the last Occurrence of the element in list, and returns the element
 * If the element is not present in the list, then a GARBAGE VALUE other than the element
 * is returned
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
char removeLastOccur(LinkedList *list, char element) {
    if (list->head == NULL) { return -1; }

    Node *beforeLastOccur = NULL;
    for (Node *curr = list->head; getNext(curr) != NULL; curr = getNext(curr)) {
        if (getData(getNext(curr)) == element) {
            beforeLastOccur = curr;
        }
    }

    // if last occurrence of the element is at head only
    if (beforeLastOccur == NULL && getData(list->head) == element) {
        return removeFirst(list);
    } else if (beforeLastOccur == NULL) {
        // element not present in the list
        return -1;
    }

    removeNext(beforeLastOccur);
    return element;
}
/*
 * Sets element at given index, to provided value
 * Returns true if operation of setting is successful else false
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
bool set(LinkedList *list, int index, char val) {
    if (list->head) { return false; }

    Node *curr = list->head;
    while (index != 0 && curr != NULL) {
        curr = getNext(curr);
        index--;
    }

    if (curr == NULL) { return false; }
    setData(curr, val);
    return true;
}

/*
 * Converts the Linked List to array and returns ptr to it
 * If list is uninitialized NULL is returned
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
char *toArray(const LinkedList *list) {
    if (list->head == NULL) { return NULL; }

    int length = size(list), i = 0;
    char *arr = malloc(sizeof(char) * length);
    for (Node *curr = list->head; curr != NULL; curr = getNext(curr)) {
        arr[i++] = getData(curr);
    }

    return arr;
}

/*
 * Calls the passed function for each element in the list
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
void forEach(LinkedList *list, void (*lambda)(char)) {
    if (list->head == NULL) { return; }

    for (Node *curr = list->head; curr != NULL; curr = getNext(curr)) {
        lambda(getData(curr));
    }
}

/*
 * Returns size of the linked list
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
int size(const LinkedList *list) {
    if (list->head == NULL) { return 0; }
    int length = 0;
    for (Node *curr = list->head; curr != NULL; curr = getNext(curr)) { length++; }

    return length;
}

/*
 * Prints the list in same line separated by space
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
void printList(const LinkedList *list) {
    if (list == NULL) {
        printf("(null)\n");
        return;
    }
    for (Node *curr = list->head; curr != NULL; curr = getNext(curr)) {
        printf("%c ", getData(curr));
    }
    printf("\n");
}


Node *insertAfter(Node *node, char data) {
    Node *new = newNode(data);
    setNext(new, getNext(node));
    setNext(node, new);

    return node;
}

void removeNext(Node *node) {
    Node *toBeDeleted = getNext(node);
    Node *next = getNext(toBeDeleted);
    freeNode(toBeDeleted);

    setNext(node, next);
}

void freeAllNodes(LinkedList *list) {
    while (list->head != NULL) {
        Node *next = getNext(list->head);
        freeNode(list->head);
        list->head = next;
    }
}


