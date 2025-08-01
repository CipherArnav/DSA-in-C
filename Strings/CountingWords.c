#include<stdio.h>
int main()
{
    char name[]="Arnav is a good boy";
    int i;int word=1;
    for(i=0;name[i]!='\0';i++)
    {
      if(name[i]==' ' && name[i-1]!=' ')
      word++;
    }
    printf("Total Words is equal to %d",word);
    return 0;
}