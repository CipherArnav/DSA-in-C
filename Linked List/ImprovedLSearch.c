#include<stdio.h>
#include<stdlib.h>

struct node
{
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
struct node* ImprovedLSearch(struct node *p,int key)
{
    struct node* q;
    while(p!=NULL)
    {
        if(key==p->data)
        {
            q->next=p->next;
            p->next=head;
            head=p;
            return p;
        }
        q=p;
        p=p->next;
    }
}
int main()
{  struct node *temp;
    int A[]={3,6,9,5,21,1,18};
    Create(A,7);
    int m;
    printf("Enter the key to be found:");
    scanf("%d",&m);

    temp=ImprovedLSearch(head,m);
    if(temp!=NULL)
    printf("Key is found %d\n",temp->data);
    else
    printf("Key not found\n");

    Display(head);
    return 0;
}