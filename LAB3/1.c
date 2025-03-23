#include <stdio.h>
#include <stdlib.h>

void bubblesort(int arr[], int size, int *opcount) {
    *opcount = 0;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) { // Corrected inner loop
            if (arr[j] > arr[j + 1]) { // Compare adjacent elements
                (*opcount)++;
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int size;
    int arr[10]; // Fixed array size should match user input
    int opcount;

    printf("Enter size of the array: ");
    scanf("%d", &size);

    if (size > 10 || size <= 0) { // Check for valid input size
        printf("Invalid size! Enter a number between 1 and 10.\n");
        return 1;
    }

    printf("Enter the elements: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    bubblesort(arr, size, &opcount);

    printf("Sorted elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\nOperation count: %d\n", opcount); // Added newline for clarity

    return 0;
}
