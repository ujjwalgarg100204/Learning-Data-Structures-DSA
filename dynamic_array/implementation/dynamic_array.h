#ifndef DATA_STRUCTURES_AND_ALGORITHM_DYNAMIC_ARRAY_H
#define DATA_STRUCTURES_AND_ALGORITHM_DYNAMIC_ARRAY_H

#include <stdbool.h>

typedef struct DynamicArrayI {
    int *arr;
    int size;
} DynamicArrayI;

DynamicArrayI *newDynamicArrayI();

void freeDynamicArrayI(DynamicArrayI *dynamicArr);

void addAtIndexI(DynamicArrayI *dynamicArr, int index, int val);

void addAtLastI(DynamicArrayI *dynamicArr, int val);

bool containsI(DynamicArrayI *dynamicArr, int val);

int getI(DynamicArrayI *dynamicArr, int index);

bool isEmptyI(DynamicArrayI *dynamicArr);

void removeAtIndexI(DynamicArrayI *dynamicArr, int index);

void setI(DynamicArrayI *dynamicArr, int index, int val);


#endif //DATA_STRUCTURES_AND_ALGORITHM_DYNAMIC_ARRAY_H
