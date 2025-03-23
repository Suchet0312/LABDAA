#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define EMPTY -1  // Indicates an empty slot

// Function to initialize the hash table
void initializeTable(int table[], int m) {
    for (int i = 0; i < m; i++) {
        table[i] = EMPTY;
    }
}

// Hash function
int hashFunction(int key, int m) {
    return key % m;
}

// Function to insert keys using linear probing
void insert(int table[], int m, int key) {
    int index = hashFunction(key, m);
    int i = 0;

    // Linear probing to find an empty slot
    while (table[(index + i) % m] != EMPTY) {
        i++;
        if (i == m) {
            printf("\nTable is full!\n");
            return;
        }
    }
    table[(index + i) % m] = key;
}

// Function to search for a key and count comparisons
int search(int table[], int m, int key, int* comparisons) {
    int index = hashFunction(key, m);
    int i = 0;

    *comparisons = 0;

    // Linear probing for search
    while (table[(index + i) % m] != EMPTY) {
        (*comparisons)++;

        if (table[(index + i) % m] == key) {
            return 1;  // Key found
        }

        i++;
        if (i == m) break;  // Stop if all slots are checked
    }

    return 0;  // Key not found
}

// Function to display the hash table
void displayTable(int table[], int m) {
    printf("\nHash Table: ");
    for (int i = 0; i < m; i++) {
        if (table[i] == EMPTY)
            printf(" - ");
        else
            printf("%d ", table[i]);
    }
    printf("\n");
}

// Function to run the experiment
void runExperiment(int m, int n) {
    int table[m];
    initializeTable(table, m);

    // Insert random keys
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        int key = rand() % 1000;
        insert(table, m, key);
    }

    printf("\nHash Table Size (m) = %d, Number of Keys (n) = %d\n", m, n);
    printf("Load Factor (λ) = %.2f\n", (float)n / m);

    displayTable(table,m);

    // Successful and unsuccessful searches
    int totalSuccessComparisons = 0;
    int totalFailComparisons = 0;

    // Perform successful searches
    for (int i = 0; i < n / 2; i++) {
        int key = table[rand() % m];  // Search for existing keys
        int comparisons;

        if (key != EMPTY && search(table, m, key, &comparisons)) {
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
}

// Main function
int main() {
    // Running the experiment with different table sizes and keys
    runExperiment(10, 5);   // m=10, n=5
    runExperiment(10, 10);  // m=10, n=10
    runExperiment(10, 15);  // m=10, n=15

    runExperiment(20, 10);  // m=20, n=10
    runExperiment(20, 15);  // m=20, n=15
    runExperiment(20, 20);  // m=20, n=20

    runExperiment(50, 25);  // m=50, n=25
    runExperiment(50, 30);  // m=50, n=30
    runExperiment(50, 40);  // m=50, n=40

    return 0;
}
