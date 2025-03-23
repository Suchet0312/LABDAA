#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int opcount = 0; // Operation count variable

/* Function to swap two elements */
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    opcount++; // Counting swap operations
}

/* Partition function: places pivot at correct position */
int partition(int arr[], int low, int high) {
    int pivot = arr[high];    // pivot element
    int i = (low - 1);        // index of smaller element
    
    for (int j = low; j < high; j++) {
        opcount++; // Counting comparisons
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    // place pivot in the correct position
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

/* Quick Sort function (Divide and Conquer) */
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Divide: partition the array
        int pi = partition(arr, low, high);

        // Conquer: recursively sort the sub-arrays
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
        // Combine: no explicit combine needed since array is sorted in-place
    }
}

/* Helper function to print the array */
void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int *arr = (int*)malloc(n * sizeof(int));

    // Read array elements (or generate them randomly)
    printf("Enter the elements:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\nOriginal array:\n");
    printArray(arr, n);

    // Sort the array
    quickSort(arr, 0, n - 1);

    printf("\nSorted array:\n");
    printArray(arr, n);
    printf("\nTotal operation count: %d\n", opcount);

    free(arr);
    return 0;
}