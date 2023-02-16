#include <stdio.h>
#include <stdlib.h>
#define size 20
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
void inserbeg(struct node **start, int val)
{
    struct node *newnode;
    newnode = getnode();
    newnode->data = val;
    newnode->next = *start;
    *start = newnode;
}
void inserend(struct node **start, int val)
{
    struct node *newnode, *ptr;
    if (*start == NULL)
    {
        inserbeg(&(*start), val);
    }
    else
    {
        newnode = getnode();
        newnode->data = val;
        newnode->next = NULL;
        ptr = *start;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = newnode;
    }
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
}
// BY STACK;
/*
struct stack
{
    int a[size];
    int top;
}*s;
void create(struct stack *s)
{
    s->top = -1;
}
void push(struct stack *s,int x)
{
    if (s->top == size - 1)
    {
        printf("overflow\n");
    }
    else
    {
        s->top++;
        s->a[s->top] = x;
    }
}
int pop(struct stack *s)
{
    int x;
    if (s->top == -1)
    {
        printf("underflow\n");
    }
    else
    {
        x = s->a[s->top];
        s->top--;
    }
    return x;
}
struct node *reversell(struct node *start)
{
    int x;
    struct node *p;
    s = (struct stack *)malloc(sizeof(struct stack));
    create(s);
    p=start;
    while (p!=NULL)
    {
        push(s, p->data);
        p=p->next;
    }
    p= start;
    while (s->top!=-1)
    {
        x=pop(s);
        p->data=x;
        p=p->next;
    }
    return start;
}
*/
// BY LINKEDLIST
void revll(struct node **start)
{
    struct node *p, *c, *n;
    p = NULL;
    c = *start;
    n = (*start)->next;
    while (c != NULL)
    {
        c->next = p;
        p = c;
        c = n;
        if (n != NULL)
        {
            n = n->next;
        }
    }
    *start = p;
}
int main()
{
    struct node *start = NULL;
    struct node *start2 = NULL;
    inserend(&start, 8);
    inserend(&start, 19);
    inserend(&start, 12);
    inserend(&start, 5);
    inserend(&start, 22);
    printf("the original list\n");
    display(&start);
    printf("\n");
    /*
    start=reversell(start);
    printf("the reversed linked list is(USING STACK)\n");
    start=display(start);
    */
    revll(&start);
    printf("the reversed linkedlist is\n");
    display(&start);
    return 0;
}
