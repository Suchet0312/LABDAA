#include<stdio.h>
#include<string.h>

void bruteForceString(const char text[],const char pattern[],int *opcount){
    int n = strlen(text);
    int m = strlen(pattern);
    *opcount = 0;

    printf("Pattern found at positions: ");
    for(int i=0;i<=n-m;i++){
        int j;
        for(j=0;j<m;j++){
            (*opcount)++;
            if(text[i+j]!=pattern[j]){
                break;
            }
        }
        if(j==m){
            printf("%d ",i);
        }
    }
    printf("\n");
}
int main() {
    char text[100], pattern[50];
    int opcount;

   
    printf("Enter the text: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0'; 
    printf("Enter the pattern: ");
    fgets(pattern, sizeof(pattern), stdin);
    pattern[strcspn(pattern, "\n")] = '\0'; 

 
    bruteForceString(text, pattern, &opcount);

 
    printf("Operation count: %d\n", opcount);

    return 0;
}