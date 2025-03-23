#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *rchild, *lchild;
} Node;

Node *create(int value) {
    Node *newnode = (Node *)malloc(sizeof(Node));
    newnode->data = value;
    newnode->lchild = newnode->rchild = NULL;
    return newnode;
}

Node *insert(Node *root, int value) { 
    if (root == NULL) return create(value);

    if (value < root->data)
        root->lchild = insert(root->lchild, value);
    else if (value > root->data)
        root->rchild = insert(root->rchild, value);

    return root;
}

int search(Node *root, int value) {
    if (root == NULL)
        return 0; 
    if (root->data == value)
        return 1;

    if (value < root->data)
        return search(root->lchild, value);
    else
        return search(root->rchild, value);
}

void inorder(Node *root) {
    if (root != NULL) {
        inorder(root->lchild);
        printf("%d ", root->data);
        inorder(root->rchild);
    }
}

int main() {
    Node *root = NULL;
    int key, choice, num;

    while (1) {
        printf("\n1. Insert element\n2. Search element\n3. Inorder Traversal\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number to insert: ");
                scanf("%d", &num);
                root = insert(root, num);
                break;

            case 2:
                printf("Enter number to search: ");
                scanf("%d", &key);
                if (search(root, key))
                    printf("Key found\n");
                else {
                    printf("Key not found, inserting key...\n");
                    root = insert(root, key);
                }
                break;

            case 3:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
