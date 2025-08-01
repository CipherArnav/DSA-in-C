#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *head=NULL;
void Create(int A[],int n)
{
    struct node *t, *last;
    head=(struct node*)malloc(sizeof(struct node));
    head->data=A[0];
    head->next=NULL;
    last=head;

    for(int i=1;i<n;i++)
    {
        t=(struct node*)malloc(sizeof(struct node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

void Display (struct node *p)
{
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
}

int isLoop(struct node*f)
{
    struct node*p,*q;
    p=q=f;
    do
    {
        p=p->next;
        q=q->next;
        q=q?q->next:q;
    }while(p && q && p!=q);
    if(p==q)
    return 1;
    else
    return 0;
}

int main()
{
    struct node* t1,*t2;
    int A[]={3,5,7,10,12};
    Create(A,5);
    t1=head->next->next;
    t2=head->next->next->next->next;
    t2->next=t1;

    printf("%d\n",isLoop(head));
    return 0;
}