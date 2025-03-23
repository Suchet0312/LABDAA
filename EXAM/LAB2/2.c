#include<stdio.h>

int isPrime(int num,int*opcount){
    if(num<2) return 0;
    for(int i=2;i*i<=num;i++){
        (*opcount)++;
        if(num%i==0) return 0;
    }
    return 1;
}

int gcdMiddleSchool(int a, int b, int *opcount) {
    int gcd = 1; // Initialize GCD as 1
    int min = (a < b) ? a : b; // Get the smaller number

    for (int i = 2; i <= min; i++) {
        (*opcount)++; // Count each loop iteration
        if (isPrime(i, opcount) && a % i == 0 && b % i == 0) {
            gcd *= i; // Multiply the common prime factor

            // Divide both numbers by the factor to handle multiple occurrences
            while (a % i == 0 && b % i == 0) {
                (*opcount)++; // Count each division step
                a /= i;
                b /= i;
            }
        }
    }
    return gcd;
}

int main() {
    int a, b, opcount = 0;
    printf("Enter two numbers to find their GCD: ");
    scanf("%d %d", &a, &b);

    int gcd = gcdMiddleSchool(a, b, &opcount);
    printf("The GCD of %d and %d is: %d\n", a, b, gcd);
    printf("Number of operations performed: %d\n", opcount);

    return 0;
}
