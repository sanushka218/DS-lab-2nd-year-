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
void subll(struct node **start1, struct node **start2, struct node **start3)
{
    int temp = 0;
    struct node *p, *q;
    p = *start1;
    q = *start2;
    while (p != NULL || q != NULL)
    {
        if (p != NULL && q != NULL)
        {
            if (p->data >=q->data)
            {
                temp = (p->data) - (q->data);
                inserbeg(&(*start3), temp);
                p = p->next;
                q = q->next;
            }
            else
            {
                temp = ((p->data)+ 10) - (q->data);
                inserbeg(&(*start3), temp);
                p->next->data--;
                p = p->next;
                q = q->next;
            }
        }
        else if (q == NULL)
        {
            inserbeg(&(*start3), p->data);
            p = p->next;
        }
        else
        {
            inserbeg(&(*start3), q->data);
            q = q->next;
        }
    }
}
int main()
{
    struct node *start1, *start2, *start3;
    start1 = NULL;
    start2 = NULL;
    start3 = NULL;
    inserbeg(&start1, 4);
    inserbeg(&start1, 1);
    inserbeg(&start1, 2);
    inserbeg(&start2, 1);
    inserbeg(&start2, 9);
    inserbeg(&start2, 5);
    subll(&start1, &start2, &start3);
    display(&start3);
}