#include<stdio.h>

double e(int x, int n)
{
    static double p=1,f=1;
    double r; //for storing result
    if(n==0)
    return 1;
    r=e(x,n-1);
    p=p*x;
    f=f*n;
    return r+p/f;
    
}

int main()
{
   printf("%1f",e(1,10));  //1f is used to give values of float
    return 0;
}