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

void RemoveDuplicates(struct node*p)
{
    struct node*q=p->next;
    while(q!=NULL)
    {
        if(p->data!=q->data)
        {
           p=q;
           q=q->next;
        }
        else
        {
            p->next=q->next;
            free(q);
            q=p->next;
        }
    }
}
int main()
{
    int A[]={3,5,5,5,7,10,10,12};
    Create(A,8);
    Display(head);
    printf("\n");
    RemoveDuplicates(head);
    Display(head);
    return 0;
}