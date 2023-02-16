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
void loopformation(struct node **start)
{
    struct node *newnode1, *newnode2, *newnode3, *newnode4, *newnode5, *newnode6;
    newnode1 = getnode();
    newnode1->data = 1;
    *start = newnode1;

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
    newnode6->next = newnode3;
}
int loop(struct node **start)
{
    struct node *i, *j;
    i = *start;
    j = *start;
    while (i != NULL && i->next != NULL)
    {
        i = i->next->next;
        j = j->next;
        if (i == j)
        {
            return 1;
        }
    }
    return 0;
}
int lengthofloop(struct node **start)
{
    int count = 0;
    struct node *i, *j;
    i = *start;
    j = *start;
    while (i != NULL && i->next != NULL)
    {
        i = i->next->next;
        j = j->next;
        if (i == j)
        {
            j = j->next;
            count++;
            while (j != i)
            {
                j = j->next;
                count++;
            }
            return count;
        }
    }
    return 0;
}
int startofloop(struct node **start)
{
    struct node *i, *j;
    i = *start;
    j = *start;
    while (i != NULL && i->next != NULL)
    {
        i = i->next->next;
        j = j->next;
        if (i == j)
        {
            do
            {
                i=i->next->next;
                j=j->next;
            } while (j->next==i);
            return j->data;
        }
    }
    return 0;
}
int main()
{
    int a = 0;
    struct node *start;
    start = NULL;
    loopformation(&start);
    a = loop(&start);
    if (a == 1)
    {
        printf("YES\n");
    }
    else
        printf("NO\n");
    printf("length of loop is %d\n", lengthofloop(&start));
    printf("starting point of loop is %d\n",startofloop(&start));
    return 0;
}