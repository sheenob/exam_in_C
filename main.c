#include <assert.h>
#include "node.h"
#include "queue.h"
#include <stdio.h>

int main() {
    Node* root = NULL;
    root = INSERT(root, 10);
    INSERT(root, 20);
    INSERT(root, 30);
    INSERT(root, 40);
    INSERT(root, 50);
    INSERT(root, 60);
    INSERT(root, 70);


    // Inorder traversal
    printf("\nInorder traversal of the given Binary Search "
           "Tree is: ");
    TRAVERSAL(root);
    printf("\n");

    // Delete
    int valueToDelete;
    printf("\nWich data do you want to delete : ");
    scanf("%d", &valueToDelete);
    DELETE(root, valueToDelete);
    assert(SEARCH(root, valueToDelete) == NULL);
    printf("\nInorder traversal after deletion of %d : ", valueToDelete);
    TRAVERSAL(root);
    printf("\n");

    //Search
    int valueToSearch;
    printf("\nWich data do you want to search : ");
    scanf("%d", &valueToSearch);
    SEARCH(root, valueToSearch);
    if (SEARCH(root, valueToSearch) != NULL) {
        printf("\n%d is in the tree\n", valueToSearch);
    } else {
        printf("\n%d is not in the tree\n", valueToSearch);
    }

    //SWAP
    int valueToSwap1, valueToSwap2;
    printf("\nWich data do you want to swap : ");
    scanf("%d %d", &valueToSwap1, &valueToSwap2);
    SWAP(root, valueToSwap1, valueToSwap2);
    printf("\nInorder traversal after swapping %d and %d : ", valueToSwap1, valueToSwap2);
    TRAVERSAL(root);
    printf("\n");

    freeNode(root);
    return 0;
}