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

int Delete(struct node*p,int pos)
{
  struct node*t,*q;
  int x;
   if(pos < 0 || pos > Length(head))
  return  -1;
  if(pos==1)
  {
    while(p->next!=head)
    p=p->next;
    x=head->data;
    if(head==p)
    {
        free(head);
        head=NULL;
    }
    else
    {
        p->next=head->next;
        free(head);
        head=p->next;
    }
  }
  else
  {
    for(int i=0;i<pos-2;i++)
    p=p->next;
    q=p->next;
    x=q->data;
    free(q);

  }
  return x;
}
int main()
{
    int A[]={2 ,4 ,7 ,21 , 13};
    Create(A,5);
    Display(head);
    printf("\n");
    Delete(head, 3);
    Display(head);
    
    return 0;
}