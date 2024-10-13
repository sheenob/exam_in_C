#include "node.h"
#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

//Function to display the tree
void printTree(Node* root) {
    if (root == NULL) {
        return;
    }

    Queue* q = createQueue();
    addToQueue(q, root);

    while (!isEmpty(q)) {
        Node* temp = removeFromQueue(q);
        printf("\n");
        printf("%d ", temp->data);

        if (temp->left != NULL) {
            addToQueue(q, temp->left);
        }

        if (temp->right != NULL) {
            addToQueue(q, temp->right);
        }
    }
    printf("\n");

    freeQueue(q);
}

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
            freeQueue(q); // Libération de la mémoire de la queue
            return root;
        }
    }

    freeQueue(q); // Libération de la mémoire de la queue
    return root;
}


//Function to search for a node in the binary tree
Node* searchNode(Node* root, int data) {
    if (root == NULL) {
        return NULL;
    }

    Queue* q = createQueue();
    addToQueue(q, root);

    while (!isEmpty(q)) {
        Node* temp = removeFromQueue(q);
        if (temp->data == data) {
            freeQueue(q);
            return temp;
        }

        if (temp->left != NULL) {
            addToQueue(q, temp->left);
        }

        if (temp->right != NULL) {
            addToQueue(q, temp->right);
        }

    }

    freeQueue(q);
    return NULL;
}

//Function to delete a node from the binary tree
Node* deleteNode(Node* root, int data) {
    if (root == NULL) {
        return NULL;
    }

    if (root->left == NULL && root->right == NULL) {
        if (root->data == data) {
            free(root);
            return NULL;
        } else {
            return root;
        }
    }

    Queue* q = createQueue();
    addToQueue(q, root);

    Node* temp = NULL;
    Node* keyNode = NULL;

    while (!isEmpty(q)) {
        temp = removeFromQueue(q);
        if (temp->data == data) {
            keyNode = temp;
        }

        if (temp->left != NULL) {
            addToQueue(q, temp->left);
        }

        if (temp->right != NULL) {
            addToQueue(q, temp->right);
        }
    }

    if (keyNode != NULL) {
        int x = temp->data;
        deleteDeepestNode(root, temp);
        keyNode->data = x;
    }

    freeQueue(q);
    return root;
}


//Function to delete the deepest node in the binary tree
Node* deleteDeepestNode(Node* root, Node* deepestNode) {
    Queue* q = createQueue();
    addToQueue(q, root);

    Node* temp = NULL;

    while (!isEmpty(q)) {
        temp = removeFromQueue(q);
        if (temp == deepestNode) {
            temp = NULL;
            free(deepestNode);
            freeQueue(q);
            return root;
        }

        if (temp->left != NULL) {
            if (temp->left == deepestNode) {
                temp->left = NULL;
                free(deepestNode);
                freeQueue(q);
                return root;
            } else {
                addToQueue(q, temp->left);
            }
        }

        if (temp->right != NULL) {
            if (temp->right == deepestNode) {
                temp->right = NULL;
                free(deepestNode);
                freeQueue(q);
                return root;
            } else {
                addToQueue(q, temp->right);
            }
        }
    }

    freeQueue(q);
    return root;
}
