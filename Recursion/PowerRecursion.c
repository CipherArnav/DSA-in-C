//METHOD 1

#include<stdio.h>
#include<math.h>
int power(int m, int n)
{
    if(n==0)
    return 1;
    if(n%2==0)
    return power(m*m,n/2);
    else 
    return m*power(m*m,(n-1)/2);
}

int main()
{
    int r;
    r=power(2,6); //2 to the power 5
    printf("%d",r);
    return 0;
}

//METHOD 2

/*#include<stdio.h>
#include<math.h>
int power(int m, int n)
{
    if(n==0)
    return 1;
    return power(m,n-1)*m;
}

int main()
{
    int r;
    r=power(2,5); //2 to the power 5
    printf("%d",r);
    return 0;
}*/