#include <stdio.h>

// Function to swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perform heapify upward operation
void heapifyUp(int heap[], int index) {
    int parent = (index - 1) / 2;
    
    while (index > 0 && heap[index] > heap[parent]) {
        swap(&heap[index], &heap[parent]);
        index = parent;
        parent = (index - 1) / 2;
    }
}

// Function to build max-heap using top-down construction
void buildHeap(int arr[], int n) {
    int heap[n];  // Create heap array

    for (int i = 0; i < n; i++) {
        heap[i] = arr[i];           // Add element to heap
        heapifyUp(heap, i);         // Perform heapify upward
        
        // Print heap after each insertion
        printf("\nHeap after inserting %d: ", arr[i]);
        for (int j = 0; j <= i; j++) {
            printf("%d ", heap[j]);
        }
    }

    // Print the final heap
    printf("\n\nFinal Max-Heap: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", heap[i]);
    }
}

// Main function
int main() {
    int arr[] = {15, 40, 30, 10, 20, 50, 35};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    buildHeap(arr, n);

    return 0;
}
