#include<stdio.h>

double e(int x, int n)
{
    static double s;
    if(n==0)
    return s;
    s=1+x*s/n;
    return e(x,n-1);
}


int main()
{
   printf("%1f\n",e(1,10));  //1f is used to give values of float
    return 0;
}