#include <stdio.h>
#include <stdlib.h>

// Define structure for a tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Function to find the Closest Common Ancestor (CCA)
struct Node* findCCA(struct Node* root, int n1, int n2) {
    if (root == NULL) return NULL;

    // If root matches either n1 or n2, return root
    if (root->data == n1 || root->data == n2) return root;

    // Recursively find CCA in left and right subtrees
    struct Node* leftCCA = findCCA(root->left, n1, n2);
    struct Node* rightCCA = findCCA(root->right, n1, n2);

    // If both left and right return non-null, root is the CCA
    if (leftCCA && rightCCA) return root;

    // Otherwise, return the non-null subtree
    return (leftCCA != NULL) ? leftCCA : rightCCA;
}

// Driver function
int main() {
    // Creating the binary tree
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    int n1, n2;
    printf("Enter two node values to find their Closest Common Ancestor: ");
    scanf("%d %d", &n1, &n2);

    struct Node* cca = findCCA(root, n1, n2);
    if (cca)
        printf("Closest Common Ancestor of %d and %d is: %d\n", n1, n2, cca->data);
    else
        printf("Nodes not found in the tree.\n");

    return 0;
}
