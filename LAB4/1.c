#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Function to calculate the total cost of a given assignment
int calculate_cost(int cost_matrix[3][3], int n, int assignment[]) {
    int total_cost = 0;
    for (int i = 0; i < n; i++) {
        total_cost += cost_matrix[i][assignment[i]];
    }
    return total_cost;
}

// Function to generate all permutations of the assignment and find the minimum cost
void generate_permutations(int cost_matrix[3][3], int n, int assignment[], int index, int *min_cost) {
    if (index == n) {
        int cost = calculate_cost(cost_matrix, n, assignment);
        if (cost < *min_cost) {
            *min_cost = cost;
        }
        return;
    }

    for (int i = index; i < n; i++) {
        // Swap elements
        int temp = assignment[index];
        assignment[index] = assignment[i];
        assignment[i] = temp;

        // Recursive call
        generate_permutations(cost_matrix, n, assignment, index + 1, min_cost);

        // Backtrack (swap back)
        temp = assignment[index];
        assignment[index] = assignment[i];
        assignment[i] = temp;
    }
}

// Function to find the minimum cost assignment using brute force
int assignment_bruteforce(int cost_matrix[3][3], int n) {
    int min_cost = INT_MAX;
    int assignment[n];

    // Initialize assignment array with values from 0 to n-1
    for (int i = 0; i < n; i++) {
        assignment[i] = i;
    }

    // Generate all permutations and calculate the minimum cost
    generate_permutations(cost_matrix, n, assignment, 0, &min_cost);

    return min_cost;
}

int main() {
    int cost_matrix[3][3] = {
        {4, 2, 8},
        {6, 3, 7},
        {5, 9, 1}
    };

    int n = 3;  // Number of workers (and jobs)
    int min_cost = assignment_bruteforce(cost_matrix, n);

    printf("The minimum cost of assignment is: %d\n", min_cost);
    return 0;
}
