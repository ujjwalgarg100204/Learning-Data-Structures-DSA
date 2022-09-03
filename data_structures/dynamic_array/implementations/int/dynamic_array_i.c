#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "dynamic_array_i.h"

struct DynamicArray {
    int *array;
    int size;
    int capacity;
};

/*
 * Returns true if index passed is valid for the given dynamic array, else false
 */
bool isValidIndex(const DynamicArray *arr, int index);

/*
 * It ensures the capacity of the dynamic array to be more than or equal to
 * passed minimum capacity
 */
void ensureCapacity(DynamicArray *arr, int minCapacity);

/*
 * Creates a new Dynamic array with size DEFAULT_SIZE 10 and empty array
 * and returns a pointer to the struct DynamicArray
 */
DynamicArray *newDynamicArray() {
    DynamicArray *dynamicArray = malloc(sizeof(DynamicArray));
    dynamicArray->array = calloc(DEFAULT_SIZE, sizeof(int));
    dynamicArray->size = 0;
    dynamicArray->capacity = DEFAULT_SIZE;

    return dynamicArray;
}

/*
 * Frees the memory allocated for Dynamic array, and renders Array unusable
 * WARNING: This function should be used at last, when you don't want to use
 * the dynamic array at all
 */
void freeDynamicArray(DynamicArray *arr) {
    free(arr->array);
    free(arr);
}

/*
 * Adds the passed element at the passed index
 * If the index is invalid, it does not do anything
 * NOTE: index should be provided keeping in mind 0 indexing
 */
void addAt(DynamicArray *arr, int index, int element) {
    if (!(index >= 0 && index <= arr->size)) {
        return;
    }
    ensureCapacity(arr, arr->size + 1);
    // increase the size of the array to accommodate for the new element
    arr->size++;

    // move elements 1 step forward
    for (int i = arr->size - 1; i > index; --i) {
        arr->array[i] = arr->array[i - 1];
    }
    arr->array[index] = element;
}

/*
 * Adds the passed element at the last index of the array
 * If the array is empty, it will initialize the array with given element
 */
void addLast(DynamicArray *arr, int element) {
    ensureCapacity(arr, arr->size + 1);

    arr->array[arr->size++] = element;
}

/*
 * Copies the passed array elements to the dynamic array preserving the order
 * of the array
 */
void addAll(DynamicArray *arr, const int *array, int sizeOfArray) {
    if (array == NULL)
        return;

    ensureCapacity(arr, arr->size + sizeOfArray);

    for (int i = 0, j = arr->size; i < sizeOfArray; i++, j++) {
        arr->array[j] = array[i];
    }
    arr->size += sizeOfArray;
}

/*
 * Empties the array, but does not deallocate memory for it, only sets each element of the
 * array to NULL or 0
 */
void clear(DynamicArray *arr) {
    memset(arr->array, 0, sizeof(int) * arr->size);
}

/*
 * Returns the element at the index passed, in the dynamic array
 * WARNING: If an invalid index is provided, then garbage value is returned
 */
int getAt(const DynamicArray *arr, int index) {
    if (isValidIndex(arr, index)) {
        return arr->array[index];
    }

    return -1;
}

/*
 * Returns true if array is empty, ie, all values are set to NULL or 0
 */
bool isEmpty(const DynamicArray *arr) {
    return arr->size == 0;
}

/*
 * Gets the last index of the val passed
 * If val does not occur in the array,then returns -1
 */
int lastIndexOf(const DynamicArray *arr, int val) {
    int lastIndex = -1;
    for (int i = 0; i < arr->size; ++i)
        if (arr->array[i] == val)
            lastIndex = i;

    return lastIndex;
}


/*
 * Returns a copy of Dynamic array independent of the passed array
 * WARNING: returned array returned by this function is independent array which
 * does not have any relation to arr, except all the elements are the same.
 * So it needs to be deallocated separately
 */
DynamicArray *clone(const DynamicArray *arr) {
    DynamicArray *newArr = newDynamicArray();
    ensureCapacity(newArr, arr->size);

    for (int i = 0; i < arr->size; ++i) {
        newArr->array[i] = arr->array[i];
    }
    newArr->size += arr->size;

    return newArr;
}

/*
 * returns first index of value at which passed val occurs, if val does not occur
 * in the array, -1 is returned
 */
int indexOf(const DynamicArray *arr, int val) {
    for (int i = 0; i < arr->size; i++)
        if (arr->array[i] == val)
            return i;

    return -1;
}

/*
 * Removes the element at the passed index and returns the element
 * If an invalid index is passed, GARBAGE VALUE is returned
 */
int removeAt(DynamicArray *arr, int index) {
    if (!isValidIndex(arr, index)) {
        return -1;
    }

    int element = arr->array[index];
    // left shift the array by 1 position
    for (int i = index; i < arr->size - 1; ++i) {
        arr->array[i] = arr->array[i + 1];
    }

    // decrease the array size by 1
    arr->size--;

    return element;
}

/*
 * Removes first occurrence of the val from the array, if present and returns true
 * If val is not present in the array then returns false, and does not alter the array
 */
bool removeFirstOccur(DynamicArray *arr, int val) {
    for (int i = 0; i < arr->size; i++) {
        if (arr->array[i] == val) {
            removeAt(arr, i);
            return true;
        }
    }
    return false;
}

/*
 * Removes a range of indices from the given array (excluding toIndex)
 * WARNING: if indices provided are not valid, func does not alter the array in any way
 */
void removeRange(DynamicArray *arr, int fromIndex, int toIndex) {
    // validate the indexes
    if (!(isValidIndex(arr, fromIndex) && isValidIndex(arr, toIndex - 1 >= 0 ? toIndex - 1 : 0) &&
          toIndex > fromIndex)) {
        return;
    }

    for (int i = fromIndex, j = toIndex; i < arr->size && j < arr->size; ++i, j++) {
        arr->array[i] = arr->array[j];
    }

    arr->size -= toIndex - fromIndex;
}

/*
 * Sets the passed val at the passed index in the array and returns the val
 * If index is invalid, then list is left unaltered, and GARBAGE VALUE != val is returned
 */
int setAt(DynamicArray *arr, int index, int val) {
    if (isValidIndex(arr, index)) {
        arr->array[index] = val;
        return val;
    }
    return -1 == val ? -2 : -1;
}

/*
 * Returns a dynamic array with all the elements that lie within the given range (end excluded)
 * WARNING: if indices provided are not valid, NULL is returned
 */
DynamicArray *subArray(const DynamicArray *arr, int fromIndex, int toIndex) {
    if (!(isValidIndex(arr, fromIndex) && (isValidIndex(arr, toIndex - 1 >= 0 ? toIndex - 1 : 0)) &&
          toIndex > fromIndex)) {
        return NULL;
    }

    DynamicArray *subArr = newDynamicArray();
    int bound = toIndex > arr->size ? arr->size : toIndex;
    for (int i = fromIndex; i < bound; ++i) {
        addLast(subArr, getAt(arr, i));
    }

    return subArr;
}

/*
 * Returns current size of the Dynamic Array (0 >= size)
 */
int size(const DynamicArray *arr) {
    return arr->size;
}

/*
 * Used to make size of array to provided size (<= size)
 * If passed size is more than the current size, nothing happens
 */
void trimToSize(DynamicArray *arr, int size) {
    if (size <= arr->size && size > 0) {
        arr->size = size;
    }
}


void ensureCapacity(DynamicArray *arr, int minCapacity) {
    // min capacity is already satisfied
    if (minCapacity <= arr->capacity) {
        return;
    }

    // change the capacity of array to be >= than minimum capacity
    while (arr->capacity < minCapacity) {
        arr->capacity = arr->capacity + (arr->capacity >> 1);
    }

    arr->array = realloc(arr->array, sizeof(int) * arr->capacity);
}

bool isValidIndex(const DynamicArray *arr, int index) {
    return index < arr->size && index >= 0;
}

