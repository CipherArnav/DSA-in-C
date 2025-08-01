#include<stdio.h>
int main()
{
    char A[]="Arnav";
    int i;
    for(i=0;A[i]!='\0';i++)
    {
       if(A[i]>65 && A[i]<=90)
       A[i]=A[i]+32;
       else if(A[i]>='a' && A[i]<=122)
       A[i]=A[i]-32;
    }
    printf("After Changing case %s",A);
    return 0;
}