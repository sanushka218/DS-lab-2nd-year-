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
void inserbeg(struct node **start, int x)
{
    struct node *newnode;
    newnode = getnode();
    newnode->data = x;
    newnode->next = *start;
    *start = newnode;
}
void inserend(struct node **start, int x)
{
    if (*start == NULL)
    {
        inserbeg(&(*start), x);
    }
    else
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
}
void kthnode(struct node **start, int k)
{
    int count=0,i=1;
    struct node *ptr;
    ptr=*start;
    while (ptr!=NULL)
    {
        count++;
        ptr=ptr->next;
    }
    ptr=*start;
    while (i<=(count-k))
    {
        i++;
        ptr=ptr->next;
    }
    // O(3N)
   printf("the %dth node from last is %d\n", k,ptr->data); 
}
int main()
{
    struct node *start;
    start=NULL;
    inserend(&start,2);
    inserend(&start,4);
    inserend(&start,6);
    inserend(&start,7);
    inserend(&start,1);
    inserend(&start, 9);
    kthnode(&start, 3);
}