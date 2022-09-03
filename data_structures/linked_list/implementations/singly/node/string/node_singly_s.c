#include <stdlib.h>
#include <string.h>

#include "node_singly_s.h"

struct Node {
    char *data;
    struct Node *next;
};

/*
 * Creates and returns a ptr to the newly created node with passed data
 */
Node *newNode(const char *data) {
    Node *node = malloc(sizeof(Node));
    node->data = malloc(sizeof(char) * (strlen(data) + 1));
    strcpy(node->data, data);
    node->next = NULL;
    return node;
}

/*
 * Frees the dynamically allocated node, and renders it unusable
 */
void freeNode(Node *node) {
    free(node->data);
    free(node);
}

/* getters and setters of each node */
const char *getData(Node *node) {
    return node->data;
}

Node *getNext(Node *node) {
    return node->next;
}

void setData(Node *node, const char *val) {
    node->data = realloc(node->data, sizeof(char) * (strlen(val) + 1));
    strcpy(node->data, val);
}

void setNext(Node *node, Node *ptr) {
    node->next = ptr;
}