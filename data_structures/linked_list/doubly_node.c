#include <malloc.h>
#include "doubly_node.h"

/*
 * Creates a new Node which only contains data, next pointer and prev pointer
 * D -> Doubly
 * Time Complexity: O(1)
 */
Node_D *newNode_D(long long int data) {
    Node_D *node = malloc(sizeof(Node_D));
    node->data = data;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

/*
 * Frees the memory for node created using newNode_D
 * D -> Doubly
 * Time Complexity: O(1)
 */
void freeNode_D(Node_D *node) {
    free(node);
}
