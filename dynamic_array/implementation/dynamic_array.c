#include <stdlib.h>
#include <stdio.h>

#include "dynamic_array.h"

void shiftArrByI(int *arr, int by);

bool isValidIndexI(DynamicArrayI *dynamicArr, int index);

DynamicArrayI *newDynamicArrayI() {
    DynamicArrayI *dynamicArray = malloc(sizeof(DynamicArrayI));
    dynamicArray->arr = NULL;
    dynamicArray->size = 0;
    return dynamicArray;
}

void freeDynamicArrayI(DynamicArrayI *dynamicArr) {
    free(dynamicArr->arr);
    free(dynamicArr);
}

void addAtIndexI(DynamicArrayI *dynamicArr, int index, int val) {
    if (!isValidIndexI(dynamicArr, index)) {
        return;
    }

    // allocate memory for new element and increment size by 1
    dynamicArr->arr = realloc(dynamicArr->arr, sizeof(int) * (++dynamicArr->size));

    // shift the elements after the specified by 1 position
    for (int i = dynamicArr->size - 1; i != index; --i) {
        dynamicArr->arr[i] = dynamicArr->arr[i - 1];
    }

    // add the element
    dynamicArr->arr[index] = val;
}

void addAtLastI(DynamicArrayI *dynamicArr, int val) {
    // allocate the memory for new element
    dynamicArr->arr = realloc(dynamicArr->arr, sizeof(int) * (++dynamicArr->size));

    // set the element
    dynamicArr->arr[dynamicArr->size - 1] = val;
}

bool containsI(DynamicArrayI *dynamicArr, int val) {
    // loop through the whole array in search of the array, if found return true
    for (int i = 0; i < dynamicArr->size; ++i) {
        if (dynamicArr->arr[i] == val) {
            return true;
        }
    }

    return false;
}

int getI(DynamicArrayI *dynamicArr, int index) {
    if (!isValidIndexI(dynamicArr, index)) {
        return -1;
    }

    return dynamicArr->arr[index];
}

bool isEmptyI(DynamicArrayI *dynamicArr) {
    return dynamicArr->size == 0;
}

void removeAtIndexI(DynamicArrayI *dynamicArr, int index) {
    if (!isValidIndexI(dynamicArr, index)) {
        return;
    }
    // shift the array from the index to index before
    for (int i = index; i < dynamicArr->size - 1; i++) {
        dynamicArr->arr[i] = dynamicArr->arr[i + 1];
    }

    // deallocate mem for that element
    dynamicArr->arr = realloc(dynamicArr->arr, sizeof(int) * (--dynamicArr->size));
}

void setI(DynamicArrayI *dynamicArr, int index, int val) {
    if (!isValidIndexI(dynamicArr, index)) {
        return;
    }

    dynamicArr->arr[index] = val;
}

bool isValidIndexI(DynamicArrayI *dynamicArr, int index) {
    printf("Invalid index");


    return index >= 0 && index < dynamicArr->size;
}
