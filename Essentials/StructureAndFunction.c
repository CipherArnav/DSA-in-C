#include<stdio.h>
struct rectangle
{
    int length;
    int breadth;
};
void initialise(struct rectangle *r, int length,int breadth){
    r->length=2;
    r->breadth=3;
}int area (struct rectangle r){
    return r.length*r.breadth;
}void changelength(struct rectangle *r,int length){
    r->length = 5;
}
int main()
{
    struct rectangle a={12,8};
    printf("%d,%d",r->length,r->breadth);
}