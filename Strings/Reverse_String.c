#include<stdio.h>
int main()
{
    char A[]="Arnav";
    char t;
    int j,i;
    for(j=0;A[j]!='\0';j++)
    {
    }
    j=j-1;
    for(i=0;i<j;i++,j--)
    {
        t=A[i];
        A[i]=A[j];
        A[j]=t;
    }
    
    printf("Reverse of the string is %s",A);
    return 0;
}