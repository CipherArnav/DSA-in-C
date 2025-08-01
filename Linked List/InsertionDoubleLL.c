#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node*previous;
    int data;
    struct node*next;
};
struct node*head=NULL;
void Create(int A[],int n)
{
    struct node*t,*last;
    head=(struct node*)malloc(sizeof(struct node));
    head->data=A[0];
    head->next=NULL;
    head->previous=NULL;
    last=head;

    for(int i=1;i<n;i++)
    {
        t=(struct node*)malloc(sizeof(struct node));
        t->data=A[i];
        t->next=last->next;
        t->previous=last;
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
int length(struct node*p)
{
    int len=0;
    while(p!=NULL)
    {
    len++;
    p=p->next;
    }
    return len;
}
void Insert(struct node*p,int pos,int x)
{
    struct node*t;
    if(pos<0 || pos>length(head))
    return;
    if(pos==0)
    {
       t=(struct node*)malloc(sizeof(struct node));
       t->data=x;
       t->previous=NULL;
       t->next=head;
       head->previous=t;
       head=t;
    }
    else
    {
        for(int i=0;i<pos-1;i++)
        p=p->next;
        t=(struct node*)malloc(sizeof(struct node));
        t->data=x;
        t->previous=p;
        t->next=p->next;
        if(p->next!=NULL)p->next->previous=t;
        p->next=t;
    }
}   
int main()
{
    int A[]={11,14,16,21,19};
    Create(A,5);
    Display(head);
    printf("\n");
    Insert(head,3,69);
    Display(head);

    return 0;
}