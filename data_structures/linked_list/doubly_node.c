#include <malloc.h>
#include "doubly_node.h"

Node_D *newNode_D(long long int data) {
    Node_D *node = malloc(sizeof(Node_D));
    node->data = data;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

void freeNode_D(Node_D *node) {
    free(node);
}
