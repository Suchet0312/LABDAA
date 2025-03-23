#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 4  // Number of vertices

// Function to print the matrix
void printMatrix(int matrix[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to implement Warshall's algorithm
void warshall(int graph[N][N]) {
    // Transitive closure matrix
    int closure[N][N];

    // Initialize closure matrix with the original adjacency matrix
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            closure[i][j] = graph[i][j];
        }
    }

    // Warshall's algorithm
    for (int k = 0; k < N; k++) {          // Intermediate vertex
        for (int i = 0; i < N; i++) {      // Start vertex
            for (int j = 0; j < N; j++) {  // End vertex
                // If there is a path from i to k and k to j, set closure[i][j] = 1
                closure[i][j] = closure[i][j] || (closure[i][k] && closure[k][j]);
            }
        }
    }

    // Display the transitive closure matrix
    printf("\nTransitive Closure Matrix:\n");
    printMatrix(closure);
}

// Main function
int main() {
    int graph[N][N] = {
        {1, 1, 0, 0},
        {0, 1, 1, 0},
        {0, 0, 1, 1},
        {0, 0, 0, 1}
    };

    printf("Original Graph (Adjacency Matrix):\n");
    printMatrix(graph);

    warshall(graph);

    return 0;
}
