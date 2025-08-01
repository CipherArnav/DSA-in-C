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

int Min(struct node *p)
{
    int min=INT_MAX;
    while(p)
    {
        if(p->data<min)
        {
            min=p->data;
        }
        p=p->next;
    }
    return min;
}

int main()
{
    int A[]={3,5,7,10,12,18};
    Create(A,6);
    Display(head);
    printf("\n");
    printf("The Minimum Element is %d",Min(head));
    
    return 0;
}