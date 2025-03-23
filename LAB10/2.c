#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF 99999  // Representation for infinity
#define N 5        // Number of vertices

// Function to print the matrix
void printMatrix(int dist[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (dist[i][j] == INF)
                printf("INF ");
            else
                printf("%3d ", dist[i][j]);
        }
        printf("\n");
    }
}

// Floyd-Warshall algorithm to find all-pairs shortest paths
void floydWarshall(int graph[N][N]) {
    int dist[N][N];

    // Initialize the distance matrix with graph weights
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    // Apply Floyd-Warshall Algorithm
    for (int k = 0; k < N; k++) {        // Intermediate vertex
        for (int i = 0; i < N; i++) {    // Start vertex
            for (int j = 0; j < N; j++) {// End vertex
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Print the result
    printf("\nAll-Pairs Shortest Paths Matrix:\n");
    printMatrix(dist);
}

// Main function
int main() {
    // Adjacency matrix representation of the graph
    int graph[N][N] = {
        {0, 3, INF, 5, INF},
        {INF, 0, 2, INF, INF},
        {INF, INF, 0, 1, 4},
        {INF, INF, INF, 0, 2},
        {INF, INF, INF, INF, 0}
    };

    printf("Original Graph (Weighted Adjacency Matrix):\n");
    printMatrix(graph);

    floydWarshall(graph);

    return 0;
}
