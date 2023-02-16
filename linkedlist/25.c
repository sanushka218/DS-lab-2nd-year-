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
// for SORTED LINKEDLIST
/* void duplicatenode(struct node **start)
{
    struct node *i, *j;
    i = *start;
    while (i->next != NULL)
    {
        if (i->data == i->next->data)
        {
            j = i->next;
            i->next = i->next->next;
            free(j);
        }
        else
            i = i->next;
    }
} */
// for UNSORTED LINKEDLIST
void duplicatenode(struct node **start)
{
    struct node *i, *j, *temp;
    i = *start;
    while (i != NULL && i->next != NULL)
    {
        j=i;
        while (j->next != NULL)
        {
            if (i->data == j->next->data)
            {
                temp = j->next;
                j->next = j->next->next;
                free(temp);
            }
            else
                j = j->next;
        }
        i = i->next;
    }
}
int main()
{
    struct node *start;
    start = NULL;
    addbeg(&start, 12);
    addend(&start, 11);
    addend(&start, 12);
    addend(&start, 21);
    addend(&start, 41);
    addend(&start, 43);
    addend(&start, 21);
    addend(&start, 5);
    printf("original linkedlist:  ");
    display(&start);
    duplicatenode(&start);
    printf("after deleting duplicate nodes:  ");
    display(&start);
    return 0;
}