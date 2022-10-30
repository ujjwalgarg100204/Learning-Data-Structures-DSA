#ifndef CODES_DOUBLY_NODE_H
#define CODES_DOUBLY_NODE_H

#define ll long long

/*
 * struct for holding long int data and pointer to next node as well
 * as pointer to prev node
 * Used only for doubly linked list
 * D -> Doubly
 */
typedef struct Node_D {
    ll data;
    struct Node_D *next;
    struct Node_D *prev;
} Node_D;

/*
 * Creates a new Node which only contains data, next pointer and prev pointer
 * D -> Doubly
 * Time Complexity: O(1)
 */
Node_D *newNode_D(ll data);

/*
 * Frees the memory for node created using newNode_D
 * D -> Doubly
 * Time Complexity: O(1)
 */
void freeNode_D(Node_D *node);

#endif //CODES_DOUBLY_NODE_H
