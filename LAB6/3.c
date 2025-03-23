#include <stdio.h>

// Merge function that counts inversions
int merge(int arr[], int temp[], int left, int mid, int right, int *opcount) {
    int i = left, j = mid, k = left;
    int inv_count = 0;

    while ((i <= mid - 1) && (j <= right)) {
        (*opcount)++; // Count comparison
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            inv_count += (mid - i); // Count inversions
        }
    }

    while (i <= mid - 1) {
        temp[k++] = arr[i++];
    }
    
    while (j <= right) {
        temp[k++] = arr[j++];
    }
    
    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }

    return inv_count;
}

// Merge Sort function
int mergeSort(int arr[], int temp[], int left, int right, int *opcount) {
    int mid, inv_count = 0;
    if (right > left) {
        mid = (right + left) / 2;

        inv_count += mergeSort(arr, temp, left, mid, opcount);
        inv_count += mergeSort(arr, temp, mid + 1, right, opcount);
        inv_count += merge(arr, temp, left, mid + 1, right, opcount);
    }
    return inv_count;
}

// Driver code
int main() {
    int arr[] = {2, 4, 1, 3, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int temp[n];
    int opcount = 0;
    
    int inv_count = mergeSort(arr, temp, 0, n - 1, &opcount);
    
    printf("Sorted Array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    
    printf("\nNumber of inversions: %d\n", inv_count);
    printf("Operation Count: %d\n", opcount);
    
    return 0;
}