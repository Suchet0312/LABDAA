#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure for linked list node
typedef struct Node {
    int key;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int key) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->next = NULL;
    return newNode;
}

// Hash function
int hashFunction(int key, int m) {
    return key % m;
}

// Function to insert a key into the hash table
void insert(Node* table[], int m, int key) {
    int index = hashFunction(key, m);
    
    // Create a new node and add it to the linked list
    Node* newNode = createNode(key);
    newNode->next = table[index];
    table[index] = newNode;
}

// Function to search for a key and count comparisons
int search(Node* table[], int m, int key, int* comparisons) {
    int index = hashFunction(key, m);
    Node* curr = table[index];
    
    *comparisons = 0;  // Initialize comparison count

    while (curr != NULL) {
        (*comparisons)++;
        if (curr->key == key) {
            return 1;  // Key found
        }
        curr = curr->next;
    }
    
    return 0;  // Key not found
}

// Function to free the hash table
void freeHashTable(Node* table[], int m) {
    for (int i = 0; i < m; i++) {
        Node* curr = table[i];
        while (curr != NULL) {
            Node* temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
}

// Function to run the hashing experiment
void runExperiment(int m, int n) {
    Node* table[m];  // Create hash table
    for (int i = 0; i < m; i++) {
        table[i] = NULL;
    }

    // Insert random keys
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        int key = rand() % 1000;  // Random key
        insert(table, m, key);
    }

    printf("\nHash Table Size (m) = %d, Number of Keys (n) = %d\n", m, n);
    printf("Load Factor (λ) = %.2f\n", (float)n / m);

    // Successful and unsuccessful searches
    int totalSuccessComparisons = 0;
    int totalFailComparisons = 0;

    // Perform successful searches
    for (int i = 0; i < n / 2; i++) {
        int key = rand() % 1000;  // Random key
        int comparisons;
        
        if (search(table, m, key, &comparisons)) {
            totalSuccessComparisons += comparisons;
        }
    }

    // Perform unsuccessful searches
    for (int i = 0; i < n / 2; i++) {
        int key = 10000 + (rand() % 1000);  // Key not in table
        int comparisons;
        
        if (!search(table, m, key, &comparisons)) {
            totalFailComparisons += comparisons;
        }
    }

    // Print the results
    printf("Avg. comparisons (Successful): %.2f\n", (float)totalSuccessComparisons / (n / 2));
    printf("Avg. comparisons (Unsuccessful): %.2f\n", (float)totalFailComparisons / (n / 2));

    // Free the hash table
    freeHashTable(table, m);
}

// Main function
int main() {
    // Running the experiment with different table sizes and keys
    runExperiment(10, 50);   // m=10, n=50
    runExperiment(10, 100);  // m=10, n=100
    runExperiment(10, 200);  // m=10, n=200

    runExperiment(20, 50);   // m=20, n=50
    runExperiment(20, 100);  // m=20, n=100
    runExperiment(20, 200);  // m=20, n=200

    runExperiment(50, 50);   // m=50, n=50
    runExperiment(50, 100);  // m=50, n=100
    runExperiment(50, 200);  // m=50, n=200

    return 0;
}
