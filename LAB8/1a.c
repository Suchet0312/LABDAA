#include<stdio.h>
#include<stdlib.h>

#define MAX 100

void heapify(int a[MAX], int n) {
    int i, j, k, v, flag;
    
    for (i = n / 2; i >= 1; i--) {  // Start heapifying from last non-leaf node
        k = i;
        v = a[k];
        flag = 0;
        
        while (!flag && 2 * k <= n) {  // Ensure within bounds
            j = 2 * k; // Left child
            
            if (j < n && a[j] < a[j + 1]) {  // Choose the larger child
                j = j + 1;
            }
             
            if (v >= a[j]) {  // If heap property is satisfied
                flag = 1;
            } else {
                a[k] = a[j];  // Move child up
                k = j;        // Move down to child's position
            }
        }
        
        a[k] = v;  // Restore original value at correct position
    }
}

void heapsort(int a[MAX],int n){
    int i,temp;
    for(i=n;i>1;i--){
        temp = a[1];
        a[1] = a[i];
        a[i] = temp;
        heapify(a,i-1);
    }
}

int main(){
    int i,n,a[MAX];
    printf("enter the number of elements...");
    scanf("%d",&n);

    printf("enter the elements...");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    heapify(a,n);
    heapsort(a,n);
    printf("sorted elements are \n");
    for(int i=1;i<=n;i++){
        printf("%d\t",a[i]);
    }
    return 0;
}
