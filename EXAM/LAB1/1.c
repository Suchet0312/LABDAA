#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *rchild, *lchild;
} Node;

// Function to create a new node
Node* create(int value) {
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->data = value;
    newnode->lchild = newnode->rchild = NULL;
    return newnode;
}

// Function to insert a node in the BST
Node* insert(Node* root, int value) {
    if (root == NULL) return create(value);

    if (value < root->data) {
        root->lchild = insert(root->lchild, value);
    } else if (value > root->data) {
        root->rchild = insert(root->rchild, value);
    }
    return root;
}

// Function to search for a key and insert if not found
Node* searchAndInsert(Node* root, int key) {
    if (root == NULL) {
        printf("Key not found, inserting %d\n", key);
        return create(key);
    }

    if (key == root->data) {
        printf("Key found: %d\n", key);
        return root;
    } else if (key < root->data) {
        root->lchild = searchAndInsert(root->lchild, key);
    } else {
        root->rchild = searchAndInsert(root->rchild, key);
    }
    return root;
}

// Inorder traversal (Left, Root, Right)
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->lchild);
        printf("%d ", root->data);
        inorder(root->rchild);
    }
}

// Preorder traversal (Root, Left, Right)
void preorder(Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->lchild);
        preorder(root->rchild);
    }
}

// Postorder traversal (Left, Right, Root)
void postorder(Node* root) {
    if (root != NULL) {
        postorder(root->lchild);
        postorder(root->rchild);
        printf("%d ", root->data);
    }
}

// Driver function
int main() {
    Node* root = NULL;
    int choice, key;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert/Search key\n");
        printf("2. Inorder Traversal\n");
        printf("3. Preorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key: ");
                scanf("%d", &key);
                root = searchAndInsert(root, key);
                break;
            case 2:
                printf("Inorder: ");
                inorder(root);
                printf("\n");
                break;
            case 3:
                printf("Preorder: ");
                preorder(root);
                printf("\n");
                break;
            case 4:
                printf("Postorder: ");
                postorder(root);
                printf("\n");
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
