#include<stdio.h>
int fib(int n)
{
    int t0=0,t1=1,s=0;
    if(n<=1)
    return n;
    for(int i=2;i<=n;i++)
{
s=t0+t1;
    t0=t1;
    t1=s;
}
return s;
}

int rfib(int x)  //Using Recursion function
{
    if(x<=1) return x;
    return rfib(x-2)+rfib(x-1);
}

int main()
{
    printf("%d\n",fib(9));
    printf("%d\n",rfib(6));
    return 0;
}