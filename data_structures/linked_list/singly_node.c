#include <malloc.h>
#include "singly_node.h"

Node_S *newNode_S(ll data) {
    Node_S *node = malloc(sizeof(Node_S));
    node->data = data;
    node->next = NULL;
    return node;
}

void freeNode_S(Node_S *node) {
    free(node);
}


