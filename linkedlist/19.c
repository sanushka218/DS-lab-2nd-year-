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
void addbeg(struct node **start, int x)
{
    struct node *newnode;
    newnode = getnode();
    newnode->data = x;
    newnode->next = *start;
    *start = newnode;
}
void addend(struct node **start, int x)
{
    struct node *newnode, *ptr;
    ptr = *start;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    newnode = getnode();
    newnode->data = x;
    newnode->next = NULL;
    ptr->next = newnode;
}
void display(struct node **start)
{
    struct node *ptr;
    ptr = *start;
    while (ptr != NULL)
    {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}
void reversepf(struct node *start)
{
    struct node *ptr;
    ptr=start;
    if (ptr==NULL)
    {
        return ;
    }
    else{
        reversepf(ptr->next);
    }
    printf("%d\t", ptr->data); 
}
int main()
{
    struct node *start;
    start=NULL;
    addbeg(&start, 1);
    addend(&start, 2);
    addend(&start, 3);
    addend(&start, 4);
    addend(&start, 5);
    printf("original linkedlist:-   ");
    display(&start);
    printf("data of linkedlist in reverse order:-  ");
    reversepf(start);
}