#include <stdio.h>
#include <stdlib.h>

// Define AVL Tree Node using typedef
typedef struct Node {
    int key;
    int height;
    struct Node *left, *right;
} Node;

// Function to get height of a node
int getHeight(Node *node) {
    return node ? node->height : 0;
}

// Function to get balance factor of a node
int getBalanceFactor(Node *node) {
    return node ? getHeight(node->left) - getHeight(node->right) : 0;
}

// Function to create a new node
Node* createNode(int key) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->height = 1;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Right Rotate (Single Rotation)
Node* rightRotate(Node *y) {
    Node *x = y->left;
    Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + (getHeight(y->left) > getHeight(y->right) ? getHeight(y->left) : getHeight(y->right));
    x->height = 1 + (getHeight(x->left) > getHeight(x->right) ? getHeight(x->left) : getHeight(x->right));

    return x;
}

// Left Rotate (Single Rotation)
Node* leftRotate(Node *x) {
    Node *y = x->right;
    Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + (getHeight(x->left) > getHeight(x->right) ? getHeight(x->left) : getHeight(x->right));
    y->height = 1 + (getHeight(y->left) > getHeight(y->right) ? getHeight(y->left) : getHeight(y->right));

    return y;
}

// Function to insert a node iteratively in AVL tree
Node* insertNode(Node *root, int key) {
    Node *parent = NULL, *current = root, *newNode = createNode(key);
    
    // Step 1: Iterative insertion in BST
    while (current != NULL) {
        parent = current;
        if (key < current->key)
            current = current->left;
        else if (key > current->key)
            current = current->right;
        else
            return root; // Duplicate keys are not allowed
    }

    // Attach new node to the parent
    if (parent == NULL)
        return newNode;
    else if (key < parent->key)
        parent->left = newNode;
    else
        parent->right = newNode;

    // Step 2: Rebalance the tree iteratively
    current = root;
    while (current != NULL) {
        current->height = 1 + (getHeight(current->left) > getHeight(current->right) ? 
                               getHeight(current->left) : getHeight(current->right));
        int balance = getBalanceFactor(current);

        // Left Heavy (Right Rotation needed)
        if (balance > 1 && key < current->left->key)
            return rightRotate(current);

        // Right Heavy (Left Rotation needed)
        if (balance < -1 && key > current->right->key)
            return leftRotate(current);

        // Left Right Case (Left-Right Rotation)
        if (balance > 1 && key > current->left->key) {
            current->left = leftRotate(current->left);
            return rightRotate(current);
        }

        // Right Left Case (Right-Left Rotation)
        if (balance < -1 && key < current->right->key) {
            current->right = rightRotate(current->right);
            return leftRotate(current);
        }

        current = parent; // Move upwards
    }

    return root;
}

// Function to print in-order traversal (sorted order)
void inorderTraversal(Node *root) {
    if (root) {
        inorderTraversal(root->left);
        printf("%d ", root->key);
        inorderTraversal(root->right);
    }
}

// Main function to test AVL tree
int main() {
    Node *root = NULL;
    int arr[] = {30, 20, 40, 10, 25, 50, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Insert nodes iteratively
    for (int i = 0; i < n; i++) {
        root = insertNode(root, arr[i]);
    }

    // Print in-order traversal (sorted output)
    printf("In-order Traversal of AVL Tree: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}
