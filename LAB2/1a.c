#include<stdio.h>

int gcdconsecutive(int a,int b){
    int gcd = (a<b)? a: b;
    while(gcd>0){
        if(a%gcd==0 && b%gcd==0){
            return gcd;
        }
        gcd--;
    }
    return 1;
}

int main(){
    int a, b;
    printf("enter a and b");
    scanf("%d %d",&a,&b);

    int gcd = gcdconsecutive(a,b);
    printf("gcd of the given number is: %d",gcd);

    return 0;
}