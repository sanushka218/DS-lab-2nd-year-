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
void pairwiseswap(struct node **start)
{
    struct node *ptr;
    int temp;
    ptr=*start;
    while (ptr!=NULL && ptr->next!=NULL)
    {
        temp=ptr->data;
        ptr->data=ptr->next->data;
        ptr->next->data=temp;
        ptr=ptr->next->next;

    }
}
int main()
{
    struct node *start;
    start=NULL;
    addbeg(&start,1);
    addend(&start,2);
    addend(&start,3);
    addend(&start,4);
    addend(&start,5);
    addend(&start,6);
    printf("original linkedlist is:  ");
    display(&start);
    pairwiseswap(&start);
    printf("after swaping:  ");
    display(&start);
    return 0;

}