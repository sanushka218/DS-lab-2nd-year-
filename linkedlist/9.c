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
int main()
{
    struct node *start,*even,*odd
    return 0;
}