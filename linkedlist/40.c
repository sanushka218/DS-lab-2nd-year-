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
    if (*start == NULL)
    {
        newnode->next = newnode;
        *start = newnode;
    }
    else
    {
        ptr = *start;
        while (ptr->next != *start)
        {
            ptr = ptr->next;
        }
        ptr->next = newnode;
        newnode->next = *start;
        *start = newnode;
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
void sumofallnodesexceptitself(struct node **start)
{
    int sum = 0;
    struct node *ptr;
    ptr = *start;
    while (ptr->next!= *start)
    {
        sum += ptr->data;
        ptr = ptr->next;
    }
    sum += ptr->data;
    ptr = *start;
    while (ptr->next != *start)
    {
        ptr->data = sum - ptr->data;
        ptr = ptr->next;
    }
      ptr->data = sum - ptr->data;
    display(&(*start));
}
int main()
{
    struct node *start;
    start = NULL;
    addend(&start, 2);
    addend(&start, 7);
    addend(&start, 5);
    addend(&start, 6);
    addend(&start, 10);
    printf("original ll:  ");
    display(&start);
    printf("\n");
     printf("new ll:  ");
    sumofallnodesexceptitself(&start);
   
    return 0;
}
