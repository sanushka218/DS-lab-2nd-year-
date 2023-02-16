#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int data;
    struct node *next;
};
struct node *getnode()
{
    struct node *p;
    p=(struct node *)malloc(sizeof(struct node));
    return p;
}
void inserbeg(struct node **start, int x)
{
   struct node *newnode;
   newnode=getnode();
   newnode->data=x;
   newnode->next=*start;
   *start=newnode;
}
void inserend(struct node **start, int x)
{
    struct node *newnode, *ptr;
    ptr= *start;
    while (ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    newnode=getnode();
    newnode->data=x;
    newnode->next=NULL;
    ptr->next=newnode;  
}
void inseraft(struct node **temp, int x)
{
    struct node *newnode, *ptr;
    ptr=*temp;
    newnode=getnode();
    newnode->data=x;
    newnode->next=ptr->next;
    ptr->next=newnode;
}
void display(struct node **start)
{
    struct node *ptr;
    ptr=*start;
    while (ptr!=NULL)
    {
        printf("%d\t", ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}
void orderinser(struct node **start, int x)
{
    struct node *p, *q;
    p=*start;
    q=NULL;
    while (p!=NULL && x>=p->data)
    {
        q=p;
        p=p->next;
    }
    if (q==NULL)
    {
        inserbeg(&(*start), x);
    }
    else inseraft(&q, x);   
}
int main()
{
    struct node *start;
    start=NULL;
    int x;
    printf("enter -1 to end\n");
    do
    {
        printf("NUMBER:- ");
        scanf("%d", &x);
        orderinser(&start,x);
        printf("\n");
    } while (x!=-1);
    
    //orderinser(&start, 55);
    //orderinser(&start, 20);
    //orderinser(&start, 90);
    //orderinser(&start, 10);
    //orderinser(&start, 100);
    //orderinser(&start, 1);
    display(&start);
    return 0;
}
