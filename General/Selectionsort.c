#include<stdio.h>

void selectionsort(int arr[],int n){
    int i,j,min,temp;

    for(int i=0;i<n-1;i++){
        min = i;

        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min]){
                min = j;
            }
        }
        temp = arr[min];
    arr[min] = arr[i];
    arr[i] = temp;

    }
    
}
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    selectionsort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}