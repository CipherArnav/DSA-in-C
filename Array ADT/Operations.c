#include<stdio.h>
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
 int LinearSearch(struct Array arr, int key)
 {
    for(int i=0;i<arr.length;i++)
    {
        if(key==arr.A[i])
        return i;
    }
    return -1;
 }
 int Get(struct Array arr, int index)
 {
    if(index>=0 && index<arr.length)
    return arr.A[index];
    return -1;
 }
 void Set(struct Array *arr,int index,int x)
 {
    if(index>=0 && index<arr->length)
    arr->A[index]=x;
 }
 int Max(struct Array arr)
 {
    int max=arr.A[0];
    int index;
    for(index=1;index<arr.length;index++)
    {
      if(arr.A[index]>max)
      max=arr.A[index];
    }
    return max;
 }
 int Min(struct Array arr)
 {
    int index;
    int min=arr.A[0];
    for(index=1;index<arr.length;index++)
    {
      if(arr.A[index]<min)
      min=arr.A[index];
    }
    return min;
 }
 int Sum(struct Array arr)
 {
    int sum=0;
    for(int index=0;index<arr.length;index++)
    {
        sum=sum+arr.A[index];
    }
     return sum;
 }
 float Average(struct Array arr)
 {
    int sum=0;
    for(int index=0;index<arr.length;index++)
    {
        sum=sum+arr.A[index];
    }
    return sum/arr.length;
 }
int main()
{
 struct Array arr={{2,3,4,5,6,8,9,11,13,15},10,10};
 printf("Third index is %d\n",Get(arr,3));
 Set(&arr,5,12);
 printf("Modified array");
 Display(arr);
 printf("\n");
 printf("Maximum %d\n",Max(arr));
 printf("Minimum %d\n",Min(arr));
 printf("Sum %d\n",Sum(arr));
 printf("Average %f",Average(arr));
 return 0;
}