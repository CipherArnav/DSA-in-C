#include<stdio.h>
toh(int n, int a, int b, int c)
{
    if(n>0)
    {
        toh(n-1,a,c,b);
        printf("%d -> %d\n",a,c);
        toh(n-1,b,a,c);
    }
}
int main()
{
    int n,p;
    printf("Enter the nuber of dics: ");
    scanf("%d",&n);
    toh(n,1,2,3);
    return 0;
}