#ifndef LEARNING_DATA_STRUCTURES_DSA_NODE_SINGLY_C_H
#define LEARNING_DATA_STRUCTURES_DSA_NODE_SINGLY_C_H

/* struct for each data node */
typedef struct Node Node;


/*
 * Creates and returns a ptr to the newly created node with passed data
 */
Node *newNode(char data);

/*
 * Frees the dynamically allocated node, and renders it unusable
 */
void freeNode(Node *node);

/* getters and setters of each node */
char getData(Node *node);

Node *getNext(Node *node);

void setData(Node *node, char val);

void setNext(Node *node, Node *ptr);


#endif //LEARNING_DATA_STRUCTURES_DSA_NODE_SINGLY_C_H
