#ifndef CODES_DOUBLY_CIRCULAR_LL_H
#define CODES_DOUBLY_CIRCULAR_LL_H

#include <stdbool.h>
#include "../doubly_node.h"

typedef struct LinkedList_D {
    Node_D *head;
} LinkedList_D;


/*
 * Creates a new Doubly linked list and returns a ptr to new list
 */
LinkedList_D *newLinkedList_DC();

/*
 * Frees the linked list and frees each node in the list
 * Time Complexity: O(n) operation
 * Space Complexity: O(1)
 */
void freeLinkedList_DC(LinkedList_D *list);

/*
 * Adds element at the specified index
 * Returns true if addition of new element is successful else false
 */
bool addAtList_DC(LinkedList_D *list, int index, ll element);

/*
 * Adds element at the last of the list
 * Can be used to initialize the list
 */
void addLastList_DC(LinkedList_D *list, ll element);

/*
 * Adds all the elements of the array to the linked list, in the same order as they
 * occur
 * Returns true if addition is successful else false
 */
bool addAllList_DC(LinkedList_D *list, const ll *arr, int lengthOfArr);

/*
 * Adds element at the first position of the list
 * Can be used to initialize the list
 */
void addFirstList_DC(LinkedList_D *list, ll element);

/*
 * Empties the list
 */
void clearList_DC(LinkedList_D *list);

/*
 * Creates a copy of the list passed and returns the new copy of list
 */
LinkedList_D *cloneList_DC(const LinkedList_D *list);

/*
 * Returns true if element is present in list else false
 */
bool containsList_DC(const LinkedList_D *list, ll element);

/*
 * Returns element present at first position
 * NOTE: If list is uninitialized, GARBAGE VALUE is returned
 */
ll getFirstList_DC(const LinkedList_D *list);

/*
 * Returns last element present at last position of the list
 * NOTE: If list is uninitialized, GARBAGE VALUE is returned
 */
ll getLastList_DC(const LinkedList_D *list);

/*
 * Returns element present at the specified index
 * NOTE: If list is uninitialized or index passed is invalid, GARBAGE VALUE is returned
 */
ll getAtList_DC(const LinkedList_D *list, int index);

/*
 * Returns the last index at which specified element is present
 * -1 is returned if element is not present in the list or if the list is
 * uninitialized
 */
int lastIndexOfList_DC(const LinkedList_D *list, ll element);

/*
 * Removes the first element from the list and returns the element
 * NOTE: A GARBAGE VALUE is returned if list is uninitialized
 */
ll removeFirstList_DC(LinkedList_D *list);

/*
 * Removes the last element from the list and returns the element
 * NOTE: A GARBAGE VALUE is returned if list is  uninitialized
 */
ll removeLastList_DC(LinkedList_D *list);

/*
 * Removes first occurrence of the element in list, and returns true if successful
 * If the element is not present in the list, then returns false
 */
bool removeFirstOccurList_DC(LinkedList_D *list, ll element);

/*
 * Remove element at
 */
ll removeAtList_DC(LinkedList_D *list, int index);

/*
 * Removes the last Occurrence of the element in list, and returns the element
 * If the element is not present in the list, then a GARBAGE VALUE other than the element
 * is returned
 */
bool removeLastOccurList_DC(LinkedList_D *list, ll element);

/*
 * Sets element at given index, to provided value
 * Returns true if operation of setting is successful else false
 */
bool setList_DC(LinkedList_D *list, int index, ll val);

/*
 * Converts the Linked List to array and returns ptr to it
 * If list is uninitialized NULL is returned
 */
ll *toArrayList_DC(const LinkedList_D *list);

/*
 * Calls the passed function for each element in the list
 */
void forEachList_DC(LinkedList_D *list, void (*lambda)(ll));

/*
 * Returns size of the linked list
 */
int sizeList_DC(const LinkedList_D *list);


void printList_DC(const LinkedList_D *list);


#endif //CODES_DOUBLY_CIRCULAR_LL_H
