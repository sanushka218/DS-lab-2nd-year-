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
void concatenate(struct node **start1, struct node **start2)
{
    struct node *ptr;
    ptr = *start1;
    while (ptr->next != *start1)
    {
        ptr = ptr->next;
    }
    ptr->next = *start2;
    ptr = *start2;
    while (ptr->next != *start2)
    {
        ptr = ptr->next;
    }
    ptr->next = *start1;
}
int main(int argc, char const *argv[])
{
    struct node *start1, *start2;
    start1 = NULL;
    start2 = NULL;
    addend(&start1, 1);
    addend(&start1, 2);
    addend(&start1, 3);
    addend(&start1, 4);
    addend(&start1, 5);
    printf("linkedlist 1:-   ");
    display(&start1);
    printf("\n");

    addend(&start2, 6);
    addend(&start2, 7);
    addend(&start2, 8);
    addend(&start2, 9);
    addend(&start2, 10);
    printf("linkedlist 2:-   ");
    display(&start2);
    printf("\n");

    concatenate(&start1, &start2);
    printf("final list is:-");
    display(&start1);
    printf("\n");
    return 0;
}
