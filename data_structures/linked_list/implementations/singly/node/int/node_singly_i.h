#ifndef LEARNING_DATA_STRUCTURES_DSA_NODE_SINGLY_I_H
#define LEARNING_DATA_STRUCTURES_DSA_NODE_SINGLY_I_H

/* struct for each data node */
typedef struct Node Node;


/*
 * Creates and returns a ptr to the newly created node with passed data
 */
Node *newNode(int data);

/*
 * Frees the dynamically allocated node, and renders it unusable
 */
void freeNode(Node *node);

/* getters and setters of each node */
int getData(Node *node);

Node *getNext(Node *node);

void setData(Node *node, int val);

void setNext(Node *node, Node *ptr);


#endif //LEARNING_DATA_STRUCTURES_DSA_NODE_SINGLY_I_H
