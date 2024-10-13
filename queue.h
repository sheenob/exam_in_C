#ifndef QUEUE_H
#define QUEUE_H

#include "node.h"

/* I find it easier to manage to create a queue to navigate through the nodes
to search for an empty place to modify the tree. It offers a better modularity*/


//The elements int the queue
typedef struct QueueNode {
    Node* node;
    struct QueueNode* next;
} QueueNode;


//The queue itself
typedef struct Queue {
    QueueNode* front;
    QueueNode* rear;
} Queue;


Queue* createQueue();
void addToQueue(Queue* q, Node* node);
Node* removeFromQueue(Queue* q);
int isEmpty(Queue* q);
void freeQueue(Queue* q);


#endif // QUEUE_H