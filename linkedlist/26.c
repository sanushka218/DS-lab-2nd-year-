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
void createlinkedlist(struct node **start1, struct node **start2)
{
    struct node *newnode1, *newnode2, *newnode3, *newnode4, *newnode5, *newnode6, *newnode7, *newnode8, *newnode9;
    newnode1 = getnode();
    newnode1->data = 1;
    *start1 = newnode1;
    newnode2 = getnode();
    newnode2->data = 2;
    newnode1->next = newnode2;
    newnode3 = getnode();
    newnode3->data = 3;
    newnode2->next = newnode3;
    newnode4 = getnode();
    newnode4->data = 4;
    newnode3->next = newnode4;
    newnode5 = getnode();
    newnode5->data = 5;
    newnode4->next = newnode5;
    newnode6 = getnode();
    newnode6->data = 6;
    newnode5->next = newnode6;
    newnode6->next = NULL;

    newnode7 = getnode();
    newnode7->data = 7;
    *start2 = newnode7;

    newnode8 = getnode();
    newnode8->data = 8;
    newnode7->next = newnode8;
    newnode9 = getnode();
    newnode9->data = 9;
    newnode8->next = newnode9;
    newnode9->next = newnode5;
}
int count(struct node *start)
{
    int c = 0;
    struct node *p;
    p = start;
    while (p != NULL)
    {
        c++;
        p = p->next;
    }
    return c;
}
int mergepoint(struct node *start1, struct node *start2)
{
    struct node *p, *q;
    int m, n, i;
    p = start1;
    q = start2;
    m = count(p);
    n = count(q);
    if (m > n)
    {
        for (i = 0; i < (m - n); i++)
        {
            p = p->next;
        }
    }
    else
    {
        for (i = 0; i < (n - m); i++)
        {
            q = q->next;
        }
    }
    while (p != q)
    {
        p = p->next;
        q = q->next;
    }
    return p->data;
}
int main()
{
    struct node *start1, *start2;
    int a;
    start1 = NULL;
    start2 = NULL;
    createlinkedlist(&start1, &start2);
    a = mergepoint(start1, start2);
    printf("the merging point is %d\n", a);
    return 0;
}
