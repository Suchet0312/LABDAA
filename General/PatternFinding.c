#include<stdio.h>
#include<string.h>

void match(char text[],char pattern[]){
    int n = strlen(text);
    int m = strlen(pattern);
    int found = 0;
    for(int i=0;i<=n-m;i++){
        int j;
        for(j=0;j<m;j++){
            if(text[i+j]!=pattern[j]){
                break;
            }
        }
        if (j == m) {
            printf("Pattern found at index %d\n", i);
            found = 1;
        }
    }
    if (!found) {
        printf("Pattern not found in the text\n");
    }
}
int main() {
    char text[] = "It is never too late to be happy";
    char pattern[] = "happy";

    printf("Text: %s\n", text);
    printf("Pattern: %s\n", pattern);

    match(text, pattern);

    return 0;
}