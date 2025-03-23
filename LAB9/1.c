#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 256

void preprocess(char*pattern,int patterlen,int shiftTable[]){
    for(int i=0;i<MAX;i++){
        shiftTable[i] = patterlen;
    }

    for(int i=0;i<patterlen-1;i++){
        shiftTable[(unsigned char)pattern[i]] = patterlen-1-i;
    }
}

int horspoolSearch(char*text,char*pattern){
    int textLen = strlen(text);
    int patternLen = strlen(pattern);
    int shiftTable[MAX];

    preprocess(pattern,patternLen,shiftTable);

    int i = patternLen-1;

    while(i<textLen){
        int j = patternLen -1;

        while(j>=0 && pattern[j] == text[i-(patternLen-1-j)]){
            j--;
        }

        if(j<0){
            return i-patternLen+1;
        }
        i+=shiftTable[(unsigned char)text[i]];
    }
    return -1;
}
int main() {
    char text[] = "ABAAABCD";
    char pattern[] = "ABC";

    int result = horspoolSearch(text, pattern);
    if (result != -1)
        printf("Pattern found at index %d\n", result);
    else
        printf("Pattern not found\n");

    return 0;
}
