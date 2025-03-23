#include <stdio.h>
#include <stdlib.h>

// Function to print the DP table
void printTable(int n, int W, int dp[n+1][W+1]) {
    printf("\nDP Table:\n");
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            printf("%3d ", dp[i][w]);
        }
        printf("\n");
    }
}

// Function to solve the 0/1 knapsack problem using bottom-up DP
void knapsack(int n, int W, int weights[], int values[]) {
    int dp[n + 1][W + 1];

    // Initialize the DP table
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;  // Base case
            } else if (weights[i - 1] <= w) {
                // Include or exclude the item
                dp[i][w] = (values[i - 1] + dp[i - 1][w - weights[i - 1]] > dp[i - 1][w])
                           ? values[i - 1] + dp[i - 1][w - weights[i - 1]]
                           : dp[i - 1][w];
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // Print the DP table
    printTable(n, W, dp);

    // Display the maximum value
    printf("\nMaximum Value: %d\n", dp[n][W]);

    // Backtrack to find the items included
    printf("\nItems included:\n");
    int w = W;
    for (int i = n; i > 0 && w > 0; i--) {
        if (dp[i][w] != dp[i - 1][w]) {
            printf("Item %d (Value: %d, Weight: %d)\n", i, values[i - 1], weights[i - 1]);
            w -= weights[i - 1];
        }
    }
}

// Main function
int main() {
    int n = 4;                       // Number of items
    int capacity = 8;                 // Knapsack capacity
    int weights[] = {2, 3, 4, 5};     // Weights of items
    int values[] = {3, 4, 5, 6};      // Values of items

    printf("0/1 Knapsack Problem (Bottom-Up DP)\n");
    printf("Items: %d, Capacity: %d\n", n, capacity);

    knapsack(n, capacity, weights, values);

    return 0;
}
