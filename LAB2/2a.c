#include<stdio.h>

int isPrime(int num){
    if(num<2) return 0;
    for(int i=2;i*i<=num;i++){
        if(num%i==0){
            return 0;
        }
        return 1;
    }
}

int gcdmiddleschool(int a,int b){
    int gcd = 1;

    int min = (a>b)? a:b;
    for(int i=2;i<=min;i++){
        if(isPrime(i) && a%i==0 && b%i==0){
            gcd *=i;

            while(a%i==0 && b%i ==0){
                a = a/i;
                b = b/i;
            }
        }
    }
    return gcd;
}

int main() {
    int a, b;
    printf("Enter two numbers to find their GCD: ");
    scanf("%d %d", &a, &b);

    int gcd = gcdmiddleschool(a, b);
    printf("The GCD of %d and %d is: %d\n", a, b, gcd);

    return 0;
}