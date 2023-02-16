#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *getnode()
{
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    return p;
}
void addbeg(struct node **start, int val)
{
    struct node *newnode, *ptr;
    newnode = getnode();
    newnode->data = val;
    newnode->next = newnode;
    (*start) = newnode;
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
void display(struct node **start)
{
    struct node *ptr;
    ptr = *start;
    while (ptr->next != *start)
    {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
    printf("%d\t", ptr->data);
    printf("\n");
}
void reversecll(struct node **start)
{
    struct node *p,*c,*n, *last;
    last =*start;
    p=*start;
    c=*start;
    n=(*start)->next;
    while (c->next!=*start)
    {
        c->next=p;
        p=c;
        c=n;
        if (n->next!=*start)
        {
            n=n->next;
        }
    }
    c->next=p;
    *start=c;
    last->next=c;
}
int main()
{
    struct node *start;
    start=NULL;
    addend(&start,5);
    addend(&start,10);
    addend(&start,22);
    addend(&start,6);
    addend(&start,32);
    printf("linked list is:-  ");
    display(&start);
    printf("\n");
    reversecll(&start);
    printf("after reversing:-   ");
    display(&start);
    printf("\n");
    return 0;
}
