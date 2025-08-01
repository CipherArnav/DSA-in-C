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

void RecReverse(struct node*p)
{
    if(p!=NULL)
{
    RecReverse(p->next);
    printf("%d ",p->data);
}

}

int main()
{
    int A[]={3,5,7,10,12};
    Create(A,5);
    Display(head);
    printf("\n");
    RecReverse(head);
    return 0;
}