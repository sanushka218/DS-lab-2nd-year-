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
void addll(struct node **start1, struct node **start2, struct node **start3)
{
    int temp = 0, c = 0;
    struct node *p, *q;
    p = *start1;
    q = *start2;
    while (p != NULL || q != NULL )
    {
        if (p != NULL && q != NULL)
        {
            temp = c + p->data + q->data;
            inserbeg(&(*start3), temp % 1000);
            c = temp / 1000;
            p = p->next;
            q = q->next;
        }
        else if (q == NULL )
        {
            temp = c + p->data;
            inserbeg(&(*start3), temp % 1000);
            c = temp / 1000;
            p = p->next;
        }
        else
        {
            temp = c+ q->data;
            inserbeg(&(*start3), temp % 1000);
            c= temp / 1000;
            q = q->next;
        }
    }
    if(c!=0)
    {
        inserbeg(&(*start3),c);
    }
}
int main()
{
    struct node *start1, *start2, *start3;
    start1 = NULL;
    start2 = NULL;
    start3 = NULL;
    inserbeg(&start1, 423);
    inserbeg(&start1, 711);
    inserbeg(&start1, 210);
    inserbeg(&start1, 216);
    inserbeg(&start1, 444);

    inserbeg(&start2, 299);
    inserbeg(&start2, 513);
    inserbeg(&start2, 520);
    inserbeg(&start2, 433);
    inserbeg(&start2, 719);
    /* inserbeg(&start1, 1);
    inserbeg(&start1, 2);
    inserbeg(&start1, 5);

    inserbeg(&start2, 8);
    inserbeg(&start2, 5); */
    addll(&start1, &start2, &start3);
    display(&start3);
}