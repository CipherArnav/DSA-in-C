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

void Display(struct node*p)
{
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
}

int Count(struct node *p)
{
    int c=0;
    while(p)
    {
        c++;
        p=p->next;
    }
    return c;
}

void Insert(struct node *p,int index,int x)
{
    struct node*t;
   if(index < 0 || index > Count(p))
   return;
   t=(struct node*)malloc(sizeof(struct node));
   t->data=x;

   if(index==0)
   {
    t->next=head;
    head=t;
   }
   else
   {
    for(int i=0;i<index-1;i++)
    p=p->next;
    t->next=p->next;
    p->next=t;
   }
}

void SortedInsert(struct node*p,int x)
{
    struct node*t,*q=NULL;
    t=(struct node*)malloc(sizeof(struct node));
    t->data=x;
    t->next=NULL;
    if(head==NULL)
    head=t;
    else{
        while(p!=NULL && p->data<x)
        {
            q=p;
            p=p->next;
        }
        if(p==head)
        {
            t->next=head;
            head=t;
        }
        else
        {
            t->next=q->next;
            q->next=t;
        }
    }
    
}

int main()
{
    int A[]={3,5,7,10,15,24};
    Create(A,6);
    Display(head);
    printf("\n");
   SortedInsert(head,9);
   SortedInsert(head,1);
    Display(head);
   
    return 0;
}