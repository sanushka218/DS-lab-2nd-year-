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
void deletebeg(struct node **start)
{
    struct node *ptr;
    ptr = *start;
    *start = (*start)->next;
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
void deletex(struct node **start, int x)
{
    struct node *ptr, *preptr;
    ptr = *start;
    preptr = NULL;
    while (ptr !=NULL)
    {
        if (ptr->data == x)
        {
            if (preptr==NULL)
            {
                deletebeg(&(*start));
                
            }
           else{ 
            preptr->next=ptr->next;    
           } 
        }
        preptr=ptr;
        ptr=ptr->next;
    }
}
int main()
{
    struct node *start=NULL;
    inserbeg(&start,2);
    inserend(&start, 4);
    inserend(&start, 2);
    inserend(&start, 34);
    inserend(&start, 89);
    inserend(&start, 2);
    inserend(&start, 94);
    inserend(&start, 2);
    inserend(&start, 39);
    printf("before deletion:- ");
    display(&start);
    printf("\n");
    deletex(&start, 2);
    printf("after deletion:- ");
    display(&start);
    return 0;
}
