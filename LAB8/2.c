#include <stdio.h>

// Function to swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to heapify down (used for bottom-up construction)
void heapifyDown(int arr[], int n, int i) {
    int largest = i;      // Initialize largest as root
    int left = 2 * i + 1;  // Left child
    int right = 2 * i + 2; // Right child

    // Check if left child is larger than root
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // Check if right child is larger than largest so far
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // If largest is not root, swap and continue heapifying
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapifyDown(arr, n, largest);
    }
}

// Function to perform heap sort using bottom-up construction
void heapSort(int arr[], int n) {
    // Bottom-up max-heap construction
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapifyDown(arr, n, i);
    }

    // Display the constructed max-heap
    printf("\nMax-Heap constructed: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    // Perform heap sort
    for (int i = n - 1; i > 0; i--) {
        // Move the current largest (root) to the end
        swap(&arr[0], &arr[i]);
        // Restore the heap property by heapifying the reduced heap
        heapifyDown(arr, i, 0);
    }
}

// Main function
int main() {
    int arr[] = {45, 20, 35, 50, 10, 60, 30};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    heapSort(arr, n);

    printf("\n\nSorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);

    }

    return 0;
}
