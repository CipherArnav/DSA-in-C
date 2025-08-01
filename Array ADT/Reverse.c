#include<stdio.h>
#include<stdlib.h>
struct Array
{
 int A[10];
 int size;
 int length;
};

 void Display(struct Array arr)
 {
 int i;
 printf("\nElements are\n");
 for(i=0;i<arr.length;i++)
 printf("%d ",arr.A[i]);
 }

 void swap(int *x,int *y)
 {
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
 }
 void Reverse1(struct Array *arr)
 {
    int *b;
    int i,j;
    b=(int *)malloc(arr->length*sizeof(int));

    for(i=arr->length-1,j=0;i>=0;i--,j++)
    b[j]=arr->A[i];
    for(i=0;i<arr->length;i++)
    arr->A[i]=b[i];
 }
 void Reverse2(struct Array *arr)
 {
    int i,j;
    for(i=0,j=arr->length-1;i<j;i++,j--)
    {
        swap(&arr->A[i],&arr->A[j]);
    }
 }

int main()
{
    struct Array arr={{2,3,4,5,6},10,5};
 Reverse1(&arr);
 Reverse2(&arr);
 Display(arr);
 return 0;
}