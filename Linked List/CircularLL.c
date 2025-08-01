#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node* head;
void Create(int A[],int n)
{
    int i;
    struct node*t,*last;
    head=(struct node*)malloc(sizeof(struct node));
    head->data=A[0];
    head->next=head;
    last=head;

    for(i=1;i<n;i++)
    {
        t=(struct node*)malloc(sizeof(struct node));
        t->data=A[i];
        t->next=last->next;
        last->next=t;
        last=t;
    }
}
void Display(struct node *p)
{
 do
 {
 printf("%d ",p->data);
 p=p->next;
 }while(p!=head);
}
void RecDisplay(struct node*p)
{
    static int flag=0;
    if(p!=head || flag==0)
    {
        flag=1;
        printf("%d ",p->data);
        RecDisplay(p->next);
    }
    flag=0;
}

int main()
{
    int A[]={2,5,7,9,14,17};
    Create(A,6);
    Display(head);
    printf("\n");
    RecDisplay(head);
    return 0;
}