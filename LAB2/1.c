#include <stdio.h>

int gcdConsecutiveChecking(int a, int b, int *opcount) {
    int gcd = (a < b) ? a : b; // Start with the smaller number
    *opcount = 0; // Initialize operation counter

    while (gcd > 0) {
        (*opcount)++; // Count each iteration
        if (a % gcd == 0 && b % gcd == 0) { // Check divisibility
            return gcd; // Return GCD if found
        }
        gcd--; // Decrement and check the next integer
    }
    return 1; // If no GCD found, return 1 (default for co-prime numbers)
}

int main() {
    int a, b, opcount;
    printf("Enter two numbers to find their GCD: ");
    scanf("%d %d", &a, &b);

    int gcd = gcdConsecutiveChecking(a, b, &opcount);
    printf("The GCD of %d and %d is: %d\n", a, b, gcd);
    printf("Number of operations performed: %d\n", opcount);

    return 0;
}
