#include<stdio.h>

double e(int x, int n)
{
    double s=1;
    int i;
    double num=1;
    double den=1;
   for(int i=1;i<=n;i++)
   {
    num*=x;
    den*=i;
    s+=num/den;
   }
   return s;
}

int main()
{
   printf("%1f\n",e(1,10));  //1f is used to give values of float
    return 0;
}