#include <stdio.h>

// Function to perform insertion sort
void insertionSort(int A[], int n) {
    for (int i = 1; i < n; i++) {
        int v = A[i];  // Store current element
        int j = i - 1;

        // Shift elements that are greater than v to one position ahead
        while (j >= 0 && A[j] > v) {
            A[j + 1] = A[j];
            j = j - 1;
        }
        A[j + 1] = v;  // Insert the element at the correct position
    }
}

// Function to print an array
void printArray(int A[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
}

// Main function
int main() {
    int A[] = {9, 2, 7, 8, 6, 4, 3, 1};
    int n = sizeof(A) / sizeof(A[0]);

    printf("Original array: ");
    printArray(A, n);

    insertionSort(A, n);

    printf("Sorted array: ");
    printArray(A, n);

    return 0;
}
