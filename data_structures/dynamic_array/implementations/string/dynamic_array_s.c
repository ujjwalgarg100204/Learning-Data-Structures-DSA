#include <stdlib.h>
#include <string.h>

#include "dynamic_array_s.h"

struct DynamicArray {
    char **array;
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

int strLength(const char *str);

void createStrAt(char **location, const char *str);

/*
 * Creates a new Dynamic array with size DEFAULT_SIZE 10 and empty array
 * and returns a pointer to the struct DynamicArray
 */
DynamicArray *newDynamicArray() {
    DynamicArray *dynamicArray = malloc(sizeof(DynamicArray));
    dynamicArray->array = calloc(DEFAULT_SIZE, sizeof(char *));
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
    // free the individual memory allocated for each string
    for (int i = 0; i < arr->size; ++i) {
        free(arr->array[i]);
    }
    free(arr->array);
    free(arr);
}

/*
 * Adds the passed element at the passed index
 * If the index is invalid, it does not do anything
 * NOTE: index should be provided keeping in mind 0 indexing
 * New memory is allocated for each element passed
 */
void addAt(DynamicArray *arr, int index, const char *element) {
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
    createStrAt(&arr->array[index], element);

}

/*
 * Adds the passed element at the last index of the array
 * If the array is empty, it will initialize the array with given element
 * NOTE: New memory is allocated for string
 */
void addLast(DynamicArray *arr, const char *element) {
    ensureCapacity(arr, arr->size + 1);

    createStrAt(&arr->array[arr->size], element);

    arr->size++;
}

/*
 * Copies the passed array elements to the dynamic array preserving the order
 * of the array
 * NOTE: New memory is allocated for each string in the array
 */
void addAll(DynamicArray *arr, const char **array, int sizeOfArray) {
    ensureCapacity(arr, arr->size + sizeOfArray);
    // manually copy each string to the array
    for (int i = 0, j = arr->size - 1; i < sizeOfArray; i++, j++) {
        createStrAt(&arr->array[j], array[i]);
    }
}

/*
 * Empties the array, but does not deallocate memory for it, only sets each element of the
 * array to NULL or 0 after freeing memory for each string
 */
void clear(DynamicArray *arr) {
    // free each string memory manually
    for (int i = 0; i < arr->size; i++) {
        free(arr->array[i]);
    }
    memset(arr->array, 0, sizeof(int) * arr->size);
}


/*
 * Returns ptr (non-constant) to the element at the index passed, in the dynamic array
 * WARNING: If an invalid index is provided, then garbage value is returned
 */
char *getAt(const DynamicArray *arr, int index) {
    if (isValidIndex(arr, index)) {
        return arr->array[index];
    }

    return NULL;
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
int lastIndexOf(const DynamicArray *arr, const char *val) {
    int lastIndex = -1;
    for (int i = 0; i < arr->size; ++i)
        if (strcmp(arr->array[i], val) == 0)
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
        createStrAt(&newArr->array[i], arr->array[i]);
    }
    newArr->size += arr->size;

    return newArr;
}

/*
 * returns first index of value at which passed val occurs, if val does not occur
 * in the array, -1 is returned
 */
int indexOf(const DynamicArray *arr, const char *val) {
    for (int i = 0; i < arr->size; i++)
        if (strcmp(arr->array[i], val) == 0)
            return i;

    return -1;
}

/*
 * Removes the element at the passed index and returns ptr to the element
 * If an invalid index is passed, GARBAGE VALUE is returned
 */
char *removeAt(DynamicArray *arr, int index) {
    if (!isValidIndex(arr, index)) {
        return NULL;
    }

    char *element = arr->array[index];
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
bool removeFirstOccur(DynamicArray *arr, const char *val) {
    for (int i = 0; i < arr->size; i++) {
        if (strcmp(arr->array[i], val) == 0) {
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
        free(arr->array[i]);
        arr->array[i] = arr->array[j];
    }

    arr->size -= toIndex - fromIndex;
}


/*
 * Sets the passed val at the passed index in the array and returns the ptr to the value in array
 * If index is invalid, then list is left unaltered, and GARBAGE VALUE != val is returned
 */
char *setAt(DynamicArray *arr, int index, const char *val) {
    if (isValidIndex(arr, index)) {
        // free the previous string
        free(arr->array[index]);
        createStrAt(&arr->array[index], val);
        return arr->array[index];
    }
    return NULL;
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
        for (int i = size; i < arr->size; i++) {
            free(arr->array[i]);
            arr->array[i] = NULL;
        }
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

int strLength(const char *str) {
    return strlen(str) + 1;
}

void createStrAt(char **location, const char *str) {
    *location = malloc(sizeof(char) * strLength(str));
    strcpy(*location, str);
}
