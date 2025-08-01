#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *head=NULL,*second=NULL,*third=NULL;
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

void Create2(int B[],int n)
{
    struct node *t, *last;
    second=(struct node*)malloc(sizeof(struct node));
    second->data=B[0];
    second->next=NULL;
    last=second;

    for(int i=1;i<n;i++)
    {
        t=(struct node*)malloc(sizeof(struct node));
        t->data=B[i];
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

void Concat(struct node*p,struct node*q)
{
    third=p;
    while(p->next!=NULL)
       p=p->next;
       p->next=q;
}

void Merge(struct node *p,struct node *q)
{
 struct node *last;
 if(p->data < q->data)
 {
  third=last=p;
  p=p->next;
  third->next=NULL;
 }
 else
 {
  third=last=q;
  q=q->next;
  third->next=NULL;
 }
  while(p && q)
 {
  if(p->data < q->data)
 {
  last->next=p;
  last=p;
  p=p->next;
  last->next=NULL;

 }
 else
 {
  last->next=q;
  last=q;
  q=q->next;
  last->next=NULL;
 }
 }
 if(p)
 last->next=p;
 if(q)
 last->next=q;

}

int main()
{
    int A[]={3,5,7,10,12};
    int B[]={4,9,11,24,36};
    Create(A,5);
    Create2(B,5);
    printf("First Linked List: \n");
    Display(head);
    printf("\n");
    printf("Second Linked List: \n");
    Display(second);
    printf("\n");
    Merge(head,second);
    Display(third); 

   

    return 0;
}