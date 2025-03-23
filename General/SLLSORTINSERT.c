#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* link;
} Node;

Node* create(int value) {
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->data = value;
    newnode->link = NULL;
    return newnode;
}

Node* insert(Node* head, int value) {
    Node* newnode = create(value);

    // Case 1: Insert at the beginning (or empty list)
    if (head == NULL || value < head->data) {
        newnode->link = head;
        return newnode;
    }

    // Case 2: Insert in the middle or at the end
    Node* curr = head;
    while (curr->link != NULL && curr->link->data < value) {
        curr = curr->link;
    }

    // Insert new node
    newnode->link = curr->link;
    curr->link = newnode;

    return head;
}

// Function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->link;
    }
    printf("NULL\n");
}

// Main function for testing
int main() {
    Node* head = NULL;
    
    head = insert(head, 10);
    head = insert(head, 5);
    head = insert(head, 20);
    head = insert(head, 15);
    
    printList(head);  // Expected Output: 5 -> 10 -> 15 -> 20 -> NULL

    return 0;
}
