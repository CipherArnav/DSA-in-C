#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node*prev;
    int data;
    struct node*next;
};
struct node*head=NULL;
void Create(int A[],int n)
{
    struct node*t,*last;
    head=(struct node*)malloc(sizeof(struct node));
    head->data=A[0];
    head->prev=NULL;
    head->next=NULL;
    last=head;

    for(int i=1;i<n;i++)
    {
        t=(struct node*)malloc(sizeof(struct node));
        t->data=A[i];
        t->next=last->next;
        t->prev=last;
        last->next=t;
        last=t;
    }

}

void Display(struct node* p)
{
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}
int Length(struct node*p)
{
    int len=0;
    while(p!=NULL)
    {
      len++;
      p=p->next;
    }
    return len;
}

int main()
{
    int A[]={2,5,4,12,18,20};
    Create(A,6);
    printf("Length is %d \n",Length(head));
    Display(head);
    return 0;
}