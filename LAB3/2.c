#include <stdio.h>
#include <string.h>

void bruteForceStringMatch(const char text[], const char pattern[], int *opcount) {
    int n = strlen(text);    // Length of the text
    int m = strlen(pattern); // Length of the pattern
    *opcount = 0;            // Initialize operation count

    printf("Pattern found at positions: ");
    for (int i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++) {
            (*opcount)++; // Increment operation count for each comparison
            if (text[i + j] != pattern[j]) {
                break; // Mismatch found, move to the next position
            }
        }
        if (j == m) {
            // If we reach here, the pattern matches at position i
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main() {
    char text[100], pattern[50];
    int opcount; 

    // Input the text and pattern
    printf("Enter the text: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0'; // Remove trailing newline character

    printf("Enter the pattern: ");
    fgets(pattern, sizeof(pattern), stdin);
    pattern[strcspn(pattern, "\n")] = '\0'; // Remove trailing newline character

    // Perform brute-force string matching
    bruteForceStringMatch(text, pattern, &opcount);

    // Output the operation count
    printf("Operation count: %d\n", opcount);

    return 0;
}
