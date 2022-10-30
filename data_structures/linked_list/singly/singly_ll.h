#ifndef CODES_SINGLY_LL_H
#define CODES_SINGLY_LL_H

#include <stdbool.h>
#include "../singly_node.h"

typedef struct LinkedList_S {
    Node_S *head;
} LinkedList_S;


/*
 * Creates a new linked list and returns a ptr to new list
 * S -> Singly
 */
LinkedList_S *newSinglyLinkedList_S();

/*
 * Frees the linked list and frees each node in the list
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
void freeLinkedList_S(LinkedList_S *list);

/*
 * Adds element at the specified index
 * Returns true if addition of new element is successful else false
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
bool addAtList_S(LinkedList_S *list, int index, ll element);

/*
 * Adds element at the last of the list
 * Can be used to initialize the list
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
void addLastList_S(LinkedList_S *list, ll element);

/*
 * Adds all the elements of the array to the linked list, in the same order as they
 * occur
 * Returns true if addition is successful else false
 * Time Complexity: O(n + lengthOfArr)
 * Space Complexity: O(1)
 */
bool addAllList_S(LinkedList_S *list, const ll *arr, int lengthOfArr);

/*
 * Adds element at the first position of the list
 * Can be used to initialize the list
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */
void addFirstList_S(LinkedList_S *list, ll element);

/*
 * Empties the list
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
void clearList_S(LinkedList_S *list);

/*
 * Creates a copy of the list passed and returns the new copy of list
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
LinkedList_S *cloneList_S(const LinkedList_S *list);

/*
 * Returns true if element is present in list else false
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
bool containsList_S(const LinkedList_S *list, ll element);

/*
 * Returns element present at first position
 * NOTE: If list is uninitialized, GARBAGE VALUE is returned
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */
ll getFirstList_S(const LinkedList_S *list);

/*
 * Returns last element present at last position of the list
 * NOTE: If list is uninitialized, GARBAGE VALUE is returned
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
ll getLastList_S(const LinkedList_S *list);

/*
 * Returns element present at the specified index
 * NOTE: If list is uninitialized or index passed is invalid, GARBAGE VALUE is returned
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
ll getAtList_S(const LinkedList_S *list, int index);

/*
 * Returns the last index at which specified element is present
 * -1 is returned if element is not present in the list or if the list is
 * uninitialized
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
int lastIndexOfList_S(const LinkedList_S *list, ll element);

/*
 * Removes the first element from the list and returns the element
 * NOTE: A GARBAGE VALUE is returned if list is uninitialized
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
ll removeFirstList_S(LinkedList_S *list);

/*
 * Removes the last element from the list and returns the element
 * NOTE: A GARBAGE VALUE is returned if list is  uninitialized
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
ll removeLastList_S(LinkedList_S *list);

/*
 * Removes first occurrence of the element in list, and returns true if successful
 * if the element is not present in the list, then returns false
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
bool removeFirstOccurList_S(LinkedList_S *list, ll element);

/*
 * Remove element at the given index and returns the element
 * If index is invalid garbage value is returned
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
ll removeAtList_S(LinkedList_S *list, int index);

/*
 * Removes the last Occurrence of the element in list, and returns the element
 * If the element is not present in the list, then a GARBAGE VALUE other than the element
 * is returned
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
ll removeLastOccurList_S(LinkedList_S *list, ll element);

/*
 * Sets element at given index, to provided value
 * Returns true if operation of setting is successful else false
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
bool setList_S(LinkedList_S *list, int index, ll val);

/*
 * Converts the Linked List to array and returns ptr to it
 * If list is uninitialized NULL is returned
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
ll *toArrayList_S(const LinkedList_S *list);

/*
 * Calls the passed function for each element in the list
 * Time Complexity: O(n * O(lambda function))
 * Space Complexity: O(1)
 */
void forEachList_S(LinkedList_S *list, void (*lambda)(ll));

/*
 * Returns true if list is empty ,ie, head is NULL or not
 * Time Complexity: O(n)
 */
bool isEmptyList_S(LinkedList_S *list);

/*
 * Returns size of the linked list
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
int sizeList_S(const LinkedList_S *list);

/*
 * Prints the list in same line separated by space
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
void printList_S(const LinkedList_S *list);


#endif //CODES_SINGLY_LL_H
