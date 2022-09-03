#include <stdlib.h>
#include <string.h>

#include "node_doubly_s.h"

struct Node {
    char *data;
    struct Node *next;
    struct Node *prev;
};

Node *newNode(const char *data) {
    Node *node = malloc(sizeof(Node));
    node->data = malloc(sizeof(char) * (strlen(data) + 1));
    strcpy(node->data, data);

    node->next = NULL;
    node->prev = NULL;
    return node;
}

void freeNode(Node *node) {
    free(node->data);
    free(node);
}

const char *getData(Node *node) {
    return node->data;
}

Node *getNext(Node *node) {
    return node->next;
}

Node *getPrev(Node *node) {
    return node->prev;
}

void setData(Node *node, const char *val) {
    node->data = realloc(node->data, sizeof(char) * (strlen(val) + 1));
    strcpy(node->data, val);
}

void setNext(Node *node, Node *ptr) {
    node->next = ptr;
}

void setPrev(Node *node, Node *ptr) {
    node->prev = ptr;
}
