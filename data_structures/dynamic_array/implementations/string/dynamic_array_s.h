#ifndef LEARNING_DATA_STRUCTURES_DSA_DYNAMIC_ARRAY_S_H
#define LEARNING_DATA_STRUCTURES_DSA_DYNAMIC_ARRAY_S_H

#include <stdbool.h>

#define DEFAULT_SIZE 10

/* struct for Dynamic Array */
typedef struct DynamicArray DynamicArray;


/*
 * Creates a new Dynamic array with size DEFAULT_SIZE 10 and empty array
 * and returns a pointer to the struct DynamicArray
 */
DynamicArray *newDynamicArray();

/*
 * Frees the memory allocated for Dynamic array, and renders Array unusable
 * WARNING: This function should be used at last, when you don't want to use
 * the dynamic array at all
 */
void freeDynamicArray(DynamicArray *arr);

/*
 * Adds the passed element at the passed index
 * If the index is invalid, it does not do anything
 * NOTE: index should be provided keeping in mind 0 indexing
 * New memory is allocated for each element passed
 */
void addAt(DynamicArray *arr, int index, const char *element);

/*
 * Adds the passed element at the last index of the array
 * If the array is empty, it will initialize the array with given element
 * NOTE: New memory is allocated for string
 */
void addLast(DynamicArray *arr, const char *element);

/*
 * Copies the passed array elements to the dynamic array preserving the order
 * of the array
 * NOTE: New memory is allocated for each string in the array
 */
void addAll(DynamicArray *arr, const char **array, int sizeOfArray);

/*
 * Empties the array, but does not deallocate memory for it, only sets each element of the
 * array to NULL or 0 after freeing memory for each string
 */
void clear(DynamicArray *arr);

/*
 * Returns ptr (non-constant) to the element at the index passed, in the dynamic array
 * WARNING: If an invalid index is provided, then garbage value is returned
 */
char *getAt(const DynamicArray *arr, int index);

/*
 * Returns true if array is empty, ie, all values are set to NULL or 0
 */
bool isEmpty(const DynamicArray *arr);

/*
 * Gets the last index of the val passed
 * If val does not occur in the array,then returns -1
 */
int lastIndexOf(const DynamicArray *arr, const char *val);

/*
 * Returns a copy of Dynamic array independent of the passed array
 * WARNING: returned array returned by this function is independent array which
 * does not have any relation to arr, except all the elements are the same.
 * So it needs to be deallocated separately
 */
DynamicArray *clone(const DynamicArray *arr);

/*
 * returns first index of value at which passed val occurs, if val does not occur
 * in the array, -1 is returned
 */
int indexOf(const DynamicArray *arr, const char *val);

/*
 * Removes the element at the passed index and returns ptr to the element
 * If an invalid index is passed, GARBAGE VALUE is returned
 */
char *removeAt(DynamicArray *arr, int index);

/*
 * Removes first occurrence of the val from the array, if present and returns true
 * If val is not present in the array then returns false, and does not alter the array
 */
bool removeFirstOccur(DynamicArray *arr, const char *val);

/*
 * Removes a range of indices from the given array (excluding toIndex)
 * WARNING: if indices provided are not valid, func does not alter the array in any way
 */
void removeRange(DynamicArray *arr, int fromIndex, int toIndex);

/*
 * Sets the passed val at the passed index in the array and returns the ptr to the value in array
 * If index is invalid, then list is left unaltered, and GARBAGE VALUE != val is returned
 */
char *setAt(DynamicArray *arr, int index, const char *val);

/*
 * Returns a dynamic array with all the elements that lie within the given range (end excluded)
 * WARNING: if indices provided are not valid, NULL is returned
 */
DynamicArray *subArray(const DynamicArray *arr, int fromIndex, int toIndex);

/*
 * Returns current size of the Dynamic Array (0 >= size)
 */
int size(const DynamicArray *arr);

/*
 * Used to make size of array to provided size (<= size)
 * If passed size is more than the current size, nothing happens
 */
void trimToSize(DynamicArray *arr, int size);

#endif //LEARNING_DATA_STRUCTURES_DSA_DYNAMIC_ARRAY_S_H
