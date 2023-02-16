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
void addbeg(struct node **start, int val)
{
    struct node *newnode, *ptr;
    newnode = getnode();
    newnode->data = val;
    if (*start==NULL)
    {
         newnode->next = newnode;
        *start = newnode;
    }
    else
    {
        ptr=*start;
        while (ptr->next!=*start)
        {
            ptr=ptr->next;
        }
        ptr->next=newnode;
        newnode->next=*start;
        *start=newnode;  
    }
}
void addend(struct node **start, int val)
{
    if (*start == NULL)
    {
        addbeg(&(*start), val);
    }
    else
    {
        struct node *newnode, *ptr;
        newnode = getnode();
        newnode->data = val;
        ptr = *start;
        while (ptr->next != *start)
        {
            ptr = ptr->next;
        }
        ptr->next = newnode;
        newnode->next = *start;
    }
}
void deleteafter(struct node **q)
{
    struct node *ptr,*temp;
    ptr=*q;
    temp=ptr->next;
    ptr->next=temp->next;
    free(temp);
}
int josephus(struct node **start, int k)
{
    int c=1;
    struct node *p, *q;
    p=*start;
    q=NULL;
    while (p->next!=p)
    {
        while (c!=k)
        {
            q=p;
            p=p->next;
            c++;
        }
        p=p->next;
        deleteafter(&q);
        c=1;
    }
    return (p->data);
}
int main()
{
    struct node *start;
    start=NULL;
    addend(&start,1);
    addend(&start,2);
    addend(&start,3);
    addend(&start,4);
    addend(&start,5);
    addend(&start,6);
    addend(&start,7);
    addend(&start,8);
    printf("after josephus algo the final answer is %d\n", josephus(&start, 3));
    return 0;
}
