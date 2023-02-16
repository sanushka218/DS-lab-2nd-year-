// data is the priority here, lower the data value higher the priority
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *getnode()
{
    struct node *p;
    p=(struct node *)malloc(sizeof(struct node));
    return p;   
}
void addbeg(struct node **start, int x)
{
    struct node *newnode;
    newnode = getnode();
    newnode->data = x;
    newnode->next = *start;
    *start = newnode;
}
void addafter(struct node **q, int x)
{
    struct node *newnode, *ptr;
    newnode = getnode();
    newnode->data = x;
    ptr = *q;
    newnode->next = ptr->next;
    ptr->next = newnode;
}
void deletebeg(struct node **start)
{
    struct node *ptr;
    if (*start == NULL)
    {
        printf("underflow\n");
    }
    else
    {
        ptr = *start;
        *start = (*start)->next;
        free(ptr);
    }
}
void display(struct node *start)
{
    struct node *ptr;
    ptr = start;
    while (ptr != NULL)
    {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}
void enqueue(struct node **start, int x)
{
    struct node *p, *q;
    p= *start;
    q=NULL;
    while (p!=NULL && x>=p->data)
    {
        q=p;
        p=p->next;
    }
    if (q==NULL)
    {
        addbeg(&(*start),x);
    }
    else{
       addafter(&q,x);
    }
}
void dequeue(struct node **start)
{
    deletebeg(&(*start));
}
int main()
{
    int x;
    struct node *start;
    start=NULL;
    printf("enter -1 to end\n");
    do
    {
        printf("enter the data(priority)\n");
        scanf("%d", &x);
        enqueue(&start, x);
    } while (x!=-1);
    printf("the PRIORITY QUEUE IS\n");
    display(start);
    dequeue(&start);
    printf("after dequeue\n");
    display(start);
    return 0;
}
