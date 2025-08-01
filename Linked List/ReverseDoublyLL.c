#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node* previous;
    int data;
    struct node* next;
};
struct node*head=NULL;
void Create(int A[],int n)
{
    struct node*t,*last;
    head=(struct node*)malloc(sizeof(struct node));
    head->data=A[0];
    head->previous=NULL;
    head->next=NULL;
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
int Delete(struct node*p,int pos)
{
    int x;
    if(pos<0 || pos>length(head))
    return -1;
    if(pos==1)
    {
        head=head->next;
        if(head!=NULL)head->previous=p;
        x=p->data;
        free(p);
    }
    else
    {
        for(int i=0;i<pos-1;i++)
        {
            p=p->next;
            p->previous->next=p->next;
            if(p->next!=NULL)p->next->previous=p->previous;
            x=p->data;
            free(p);
        }
        return x;
    }
}
void Reverse(struct node*p)
{
    struct node*temp;
    while(p!=NULL)
    {
   temp = p->previous;
        p->previous = p->next;
        p->next = temp;
        p = p->previous;
    }
    head = temp->previous;
    }

int main()
{
    int A[]={3,7,14,16,19};
    Create(A,5);
    Display(head);
    Reverse(head);
    printf("%\n");
    Display(head);
    return 0;
}