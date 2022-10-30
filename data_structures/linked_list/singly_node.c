#include <malloc.h>
#include "singly_node.h"

/*
 * Creates a new Node which only contains data and next pointer
 * S -> Singly
 * Time Complexity: O(1)
 */
Node_S *newNode_S(ll data) {
    Node_S *node = malloc(sizeof(Node_S));
    node->data = data;
    node->next = NULL;
    return node;
}

/*
 * Frees the memory for node created using newNode_S
 * S -> Singly
 * Time Complexity: O(1)
 */
void freeNode_S(Node_S *node) {
    free(node);
}


