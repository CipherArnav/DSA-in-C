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

int Delete(struct node*p,int index)
{
    struct node* q;
    int x;
    if(index < 1 || index > Count(p))
    return -1;
    if(index==1)
    {
        q=head;
        x=head->data;
        head=head->next;
        free(q);
        return x;
    }
    else
    {
        for(int i=0;i<index-1;i++)
        {
            q=p;
            p=p->next;
        }
        q->next=p->next;
        x=p->data;
        free (p);
        return x;
    }

}
int main()
{
    int A[]={3,5,7,10,15,24};
    Create(A,6);
    Display(head);
    printf("\n");
    printf("Deleted Element is %d\n",Delete(head,3));
    Display(head);
    
   
    return 0;
}