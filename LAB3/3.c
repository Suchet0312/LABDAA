#include <stdio.h>

// Function to calculate the sum of an array
int arraySum(int arr[], int n) {
    int total = 0;
    for (int i = 0; i < n; i++) {
        total += arr[i];
    }
    return total;
}

// Recursive function to check if a subset with a given sum exists
int subsetSum(int arr[], int n, int target) {
    // Base case: If target sum becomes 0, subset exists
    if (target == 0) return 1;
    
    // If no elements left or target becomes negative, return false
    if (n == 0 || target < 0) return 0;

    // Include current element in the subset OR exclude it
    return subsetSum(arr, n - 1, target - arr[n - 1]) || subsetSum(arr, n - 1, target);
}

// Function to check if the array can be partitioned into two equal-sum subsets
int canPartition(int arr[], int n) {
    int totalSum = arraySum(arr, n);

    // If total sum is odd, partition is not possible
    if (totalSum % 2 != 0) return 0;

    // Check if a subset with sum = totalSum / 2 exists
    return subsetSum(arr, n, totalSum / 2);
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Check for partition possibility
    if (canPartition(arr, n)) {
        printf("The set can be partitioned into two subsets with equal sum.\n");
    } else {
        printf("The set cannot be partitioned into two subsets with equal sum.\n");
    }

    return 0;
}
