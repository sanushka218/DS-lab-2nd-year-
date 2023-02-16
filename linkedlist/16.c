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
void middleement(struct node **start)
{
    struct node *i, *j;
    i = *start;
    j = (*start)->next;
    while (j != NULL && j->next!=NULL)
    {
        i = i->next;
        j = j->next->next;
    }
    printf("the middle element is %d\n", i->data);
}
int main()
{
    struct node *start;
    start = NULL;
    addbeg(&start, 3);
    addend(&start, 23);
    addend(&start, 69);
    addend(&start, 14);
    addend(&start, 9);
    addend(&start, 89);
    printf("the linkedlist is: ");
    display(&start);
    printf("\n");
    middleement(&start);
    return 0;
}
