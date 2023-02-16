#include <stdio.h>
#include <stdlib.h>
struct node
{
    char data;
    struct node *next;
};
struct node *getnode()
{
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    return p;
}
void inserbeg(struct node **start, char x)
{
    struct node *newnode;
    newnode = getnode();
    newnode->data = x;
    newnode->next = *start;
    *start = newnode;
}
void inserend(struct node **start, char x)
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
void insafter(struct node **p, char x)
{
    struct node *newnode, *ptr;
    newnode = getnode();
    newnode->data = x;
    ptr = *p;
    newnode->next = ptr->next;
    ptr->next = newnode;
}
void deletenode(struct node **start, struct node **q)
{
    struct node *ptr, *preptr;
    ptr = *start;
    preptr = ptr;
    while (ptr != *q)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = ptr->next;
    
}
void vowels(struct node **start)
{
    struct node *p, *q;
    p = NULL;
    q = *start;
    while (q != NULL)
    {
        if (q->data == 'a' || q->data == 'e' || q->data == 'i' || q->data == 'o' || q->data == 'u')
        {
            if (p == NULL)
            {
                inserbeg(&q,q->data);
                deletenode(&(*start), &q);
                p=*start;
            }
            else
            {
                insafter(&p, q->data);
               deletenode(&(*start), &q);
            }
        }
        q = q->next;
    }
}
void display(struct node **start)
{
    struct node *ptr;
    ptr = *start;
    while (ptr != NULL)
    {
        printf("%c", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}
int main()
{
    struct node *start = NULL;
    inserbeg(&start, 'm');
    inserend(&start, 'u');
    inserend(&start, 'm');
    inserend(&start, 'b');
    inserend(&start, 'a');
    inserend(&start, 'i');
   // inserend(&start, 'a');
    vowels(&start);
    display(&start);
}