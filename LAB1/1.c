#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node *llink;
    struct node *rlink;
} Node;

// Function to create a new node
Node *create(int element) {
    Node *newnode = (Node *)malloc(sizeof(Node));
    newnode->data = element;
    newnode->llink = newnode->rlink = NULL;
    return newnode;
}
 
// Function to insert a node at the front
Node* insertFront(Node* head, int element) {
    Node *newnode = create(element);
    if (head == NULL) {
        return newnode;
    }
    newnode->rlink = head;
    head->llink = newnode;
    return newnode;
}

// Function to insert a node at the end
Node* insertEnd(Node* tail, int value) {
    Node *newnode = create(value);
    if (tail == NULL) {
        return newnode;
    }
    tail->rlink = newnode;
    newnode->llink = tail;
    return newnode;
}

// Function to display the list
void display(Node* head) {
    Node *curr = head;
    while (curr != NULL) {
        printf("%d\t", curr->data);
        curr = curr->rlink;
    }
    printf("\n");
}

int main() {
    Node *head = NULL, *tail = NULL;
    int choice, value;

    do {
        printf("1. Insert at Front\n2. Insert at End\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert at front: ");
                scanf("%d", &value);
                head = insertFront(head, value);
                if (tail == NULL) {
                    tail = head; // If first element, update tail too
                }
                break;
            case 2:
                printf("Enter the value to insert at end: ");
                scanf("%d", &value);
                if (tail == NULL) {
                    tail = insertEnd(tail, value);
                    head = tail; // If first element, update head too
                } else {
                    tail = insertEnd(tail, value);
                }
                break;
            case 3:
                printf("Doubly Linked List: ");
                display(head);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
