#include<stdio.h>
#include<stdlib.h>
struct Array
{
 int A[10];
 int size;
 int length;
};
void swap(int *x,int *y)
 {
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
 }
 void Display(struct Array arr)
 {
 int i;
 printf("\nElements are\n");
 for(i=0;i<arr.length;i++)
 printf("%d ",arr.A[i]);
 }
int isSorted(struct Array arr)
{
 int i;
 for(i=0;i<arr.length-1;i++)
 {
 if(arr.A[i]>arr.A[i+1])
 return 0;
 }
 return 1;
}
void Rearrange(struct Array *arr)
{
    int i,j;
    i=0;
    j=arr->length-1;
    while(i<j)
    {
        while(arr->A[i]<0)i++;
        while(arr->A[i]>0)j--;
        if(i<j)
        swap(&arr->A[i],&arr->A[j]);
    }
}
int main()
{
 struct Array arr={{-2,3,-9,16,18,-21,28,-32,35},10,9};
Rearrange(&arr);
Display(arr);
 return 0;
}