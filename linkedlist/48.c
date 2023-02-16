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
void add(struct node **start, int x)
{
    struct node *newnode, *ptr;
    newnode = getnode();
    newnode->data = x;
    newnode->next = NULL;
    if (*start == NULL)
    {
       (*start) = getnode();
        (*start)->data = 1;
        (*start)->next = newnode;
    }
    else
    {
        ptr = (*start)->next;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next=newnode;
        (*start)->data++;
    }
}
void display(struct node **start)
{
    struct node *ptr;
    ptr=(*start)->next;
    while (ptr!=NULL)
    {
        printf("%d\t",ptr->data);
        ptr=ptr->next;
    }
}
int main()
{
   struct node *start;
   start=NULL;
   add(&start,1);
   add(&start,2);
   add(&start,3);
   add(&start,4);
   add(&start,5);
   add(&start,6);
   display(&start);
    return 0;
}
