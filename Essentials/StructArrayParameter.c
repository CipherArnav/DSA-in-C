#include<stdio.h>
#include<stdlib.h>
struct Rectangle{
int length;
int breadth;
};
struct Rectangle *fun(){
    struct Rectangle *p;
    p=(struct Rectangle*)malloc(sizeof(struct Rectangle));
    p->length=21;
    p->breadth=24;
    return p;
}

int main(){
    struct Rectangle *ptr=fun();
    printf("Length %d, Breadth %d",ptr->length,ptr->breadth);
}