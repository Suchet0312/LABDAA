#include <stdio.h>

#define N 4 // Number of jobs/persons

int minCost = 1e9; // Large number to store minimum cost
int assigned[N] = {0}; // Keeps track of assigned jobs

// Function to find the minimum assignment cost using backtracking
void solve(int cost[N][N], int person, int totalCost) {
    if (person == N) { // Base case: all persons assigned
        if (totalCost < minCost) {
            minCost = totalCost;
        }
        return;
    }

    for (int job = 0; job < N; job++) {
        if (!assigned[job]) { // If job is not taken
            assigned[job] = 1; // Mark job as taken
            solve(cost, person + 1, totalCost + cost[person][job]); // Recur for next person
            assigned[job] = 0; // Backtrack
        }
    }
}

int main() {
    int cost[N][N] = {
        {9, 2, 7, 8},
        {6, 4, 3, 7},
        {5, 8, 1, 8},
        {7, 6, 9, 4}
    };

    solve(cost, 0, 0);
    printf("Minimum assignment cost: %d\n", minCost);

    return 0;
}
