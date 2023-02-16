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
void addbeg(struct node **top, int x)
{
    struct node *newnode;
    newnode = getnode();
    newnode->data = x;
    newnode->next = *top;
    *top = newnode;
}
void deletebeg(struct node **top)
{
    struct node *ptr;
    ptr = *top;
    *top = (*top)->next;
    free(ptr);
}
void push(struct node **top, int x)
{
    addbeg(&(*top), x);
}
void pop(struct node **top)
{
   deletebeg(&(*top));
}
void display(struct node *top)
{
    struct node *ptr;
    ptr=top;
    while (ptr!=NULL)
    {
        printf("%d\t",ptr->data);
        ptr=ptr->next;
    }
}
int main()
{
    struct node *top=NULL;
    push(&top,90);
    push(&top,56);
    push(&top,23);
    push(&top,44);
    push(&top,10);
    display(top);printf("\n");
    pop(&top);pop(&top);
    display(top);printf("\n");
    push(&top,888);
    display(top);printf("\n");
}