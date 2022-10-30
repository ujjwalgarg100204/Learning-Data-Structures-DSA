#ifndef CODES_SINGLY_NODE_H
#define CODES_SINGLY_NODE_H

#define ll long long

/*
 * struct for holding long int data and pointer to next node
 * Used only for singly linked list
 * S -> Singly
 */
typedef struct Node_S {
    ll data;
    struct Node_S *next;
} Node_S;

/*
 * Creates a new Node which only contains data and next pointer
 * S -> Singly
 * Time Complexity: O(1)
 */
Node_S *newNode_S(ll data);

/*
 * Frees the memory for node created using newNode_S
 * S -> Singly
 * Time Complexity: O(1)
 */
void freeNode_S(Node_S *node);

#endif //CODES_SINGLY_NODE_H
