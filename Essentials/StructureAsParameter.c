#include<stdio.h>
struct Rectangle{
int length;
int breadth;
};
void fun(struct Rectangle *a){
    a->length=69;
    printf("Length %d, Breadth %d\n",a->length,a->breadth);
}

int main(){
    struct Rectangle r={6,9};
    fun(&r);
    printf("Length %d, Breadth %d",r.length,r.breadth);
}