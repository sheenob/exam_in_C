#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include "node.h"

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


