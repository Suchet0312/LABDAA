#include<stdio.h>


int gcdd(int a,int b,int*opcount){
    int gcd = (a<b)?a:b;
    *opcount = 0;

    while(gcd>0){
        (*opcount)++;
        if(a%gcd==0 && b%gcd==0){
            return gcd;
        }
        gcd --;
    }
    return 1;
}

int main(){
    int a,b,opcount;
    printf("enter 2 numbers: ");
    scanf("%d %d",&a,&b);

    int gcd  = gcdd(a,b,&opcount);
    printf("The GCD of %d and %d is: %d\n", a, b, gcd);
    printf("Number of operations performed: %d\n", opcount);

    return 0;
}
