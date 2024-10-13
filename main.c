#include <assert.h>
#include "node.h"
#include "queue.h"
#include <stdio.h>

int main() {
    Node* root = NULL;
    root = insertNode(root, 10);
    insertNode(root, 20);
    insertNode(root, 30);

    printTree(root);

    printf("\nWhat value are you looking for?\n");
    int value;
    scanf("%d", &value);
    searchNode(root, value) ? printf("\nFound\n") : printf("Not found\n");
    
    printf("\nWhat value do you want to delete?\n");
    int valueToDelete;
    scanf("%d", &valueToDelete);
    deleteNode(root, valueToDelete);
    assert(searchNode(root, valueToDelete) == NULL);

    printTree(root);

    freeNode(root);
    return 0;
}