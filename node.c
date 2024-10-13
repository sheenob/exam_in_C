#include "node.h"
#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

//Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (!newNode) {
        printf("Memorry error\n");
        return NULL;
    }
    newNode -> data = data;
    newNode -> left = NULL;
    newNode -> right = NULL;
    return newNode;
};

void freeNode(Node* node) {
    if (node != NULL) {
        freeNode(node->left);
        freeNode(node->right);
        free(node);
    }
}


//Function to insert a node into the binary tree
Node* insertNode(Node* root, int data) {
    if (root == NULL) {
        root = createNode(data);
        return root;
    }

    //Create a queue to store the nodes of the binary tree
    Queue* q = createQueue();
    addToQueue(q, root);

    while (!isEmpty(q)) {
        Node* temp = removeFromQueue(q);

        if (temp->left != NULL) {
            addToQueue(q, temp->left);
        } else {
            temp->left = createNode(data);
            free(q); // Libération de la mémoire de la queue
            return root;
        }

        if (temp->right != NULL) {
            addToQueue(q, temp->right);
        } else {
            temp->right = createNode(data);
            free(q); // Libération de la mémoire de la queue
            return root;
        }
    }

    free(q); // Libération de la mémoire de la queue
    return root;
}
