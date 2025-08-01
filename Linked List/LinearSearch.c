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
    struct node*t ,*last;
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
struct node* LSearch(struct node *p, int key)
{
    while(p!=NULL)
    {
        if(key==p->data)
        return p;
        p=p->next;
    }
    return NULL;
    
}
struct node *Recursivesearch(struct node*p,int key)
{
    if(p==NULL)
    return NULL;
    if(p!=NULL)
    return p;
    return Recursivesearch(p->next,key);
}
int main()
{
    struct node *temp;
    int A[]={3,6,9,5,21,1,18};
    Create(A,8);
    int m;
    printf("Enter the key to be found:");
    scanf("%d",&m);
    temp=LSearch(head,m);

    if(temp!=NULL)
    printf("Key is found %d\n",temp->data);
    else
    printf("Key not found");
    return 0;
}

