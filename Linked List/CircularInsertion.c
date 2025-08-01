#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};
struct node*head;
void Create(int A[],int n)
{
struct node*t,*last;
head=(struct node*)malloc(sizeof(struct node));
head->data=A[0];
head->next=head;
last=head;

for(int i=1;i<n;i++)
{
    t=(struct node*)malloc(sizeof(struct node));
    t->data=A[i];
    t->next=last->next;
    last->next=t;
    last=t;
}
}

void Display(struct node*p)
{
    do
    {
        printf("%d ",p->data);
        p=p->next;
    }   while(p!=head);
}
int Length(struct node*p)
{
    int len=0;
    do
    {
        len++;
        p=p->next;
    }while(p!=head);
    return len;
}
void Insert(struct node*p,int pos,int x)
{
  struct node*t;
  if(pos < 0 || pos > Length(head))
  return;
  if(pos==0)
  {
    t=(struct node*)malloc(sizeof(struct node));
    t->data=x;
    if(head==NULL)
    {
        head=t;
        head->next=head;
    }
    else
    {
        while(p->next!=head)p=p->next;
        p->next=t;
        t->next=head;
        head=t;
    }
  }
  else
  {
    for(int i=0;i<pos-1;i++)p=p->next;
     t=(struct node*)malloc(sizeof(struct node));
    t->data=x;
    t->next=p->next;
    p->next=t;

  }
}
int main()
{
    int A[]={2,4,7,21,13};
    Create(A,5);
    Display(head);
    printf("\n");
    Insert(head,2,19);
    Display(head);
    
    return 0;
}