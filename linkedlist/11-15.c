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
    printf("\n");
}
void addbeg(struct node **start, int val)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = *start;
    *start = newnode;
}
void addend(struct node **start, int val)
{
    if (start == NULL)
    {
        addbeg(&(*start), val);
    }
    else
    {
        struct node *newnode, *ptr;
        newnode = (struct node *)malloc(sizeof(struct node));
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
void addaft(struct node **start, int x)
{
    struct node *newnode, *ptr;
    ptr = *start;
    newnode = getnode();
    newnode->data = x;
    newnode->next = ptr->next;
    ptr->next = newnode;
}
void orderinser(struct node **start, int x)
{
    struct node *p, *q;
    p = *start;
    q = NULL;
    while (p != NULL && x >= p->data)
    {
        q = p;
        p = p->next;
    }
    if (q == NULL)
    {
        addbeg(&(*start), x);
    }
    else
        addaft(&q, x);
}
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
void mergell(struct node **start1, struct node **start2, struct node **start3)
{
    struct node *p, *q;
    p = *start1;
    q = *start2;
    while (p != NULL && q != NULL)
    {
        if (p->data < q->data)
        {
            addbeg(&(*start3), p->data);
            p = p->next;
        }
        else
        {
            addbeg(&(*start3), q->data);
            q = q->next;
        }
    }
    while (p != NULL)
    {
        addbeg(&(*start3), p->data);
        p = p->next;
    }
    while (q != NULL)
    {
        addbeg(&(*start3), q->data);
        q = q->next;
    }
    revll(&(*start3));
    display(&(*start3));
    printf("\n");
}
void unionll(struct node **start1, struct node **start2, struct node **start3)
{
    struct node *p, *q;
    p = *start1;
    q = *start2;
    while (p != NULL && q != NULL)
    {
        if (p->data < q->data)
        {
            addbeg(&(*start3), p->data);
            p = p->next;
        }
        else if (p->data > q->data)
        {
            addend(&(*start3), q->data);
            q = q->next;
        }
        else
        {
            addbeg(&(*start3), p->data);
            p = p->next;
            q = q->next;
        }
    }
    while (p != NULL)
    {
        addend(&(*start3), p->data);
        p = p->next;
    }
    while (q != NULL)
    {
        addbeg(&(*start3), q->data);
        q = q->next;
    }
    revll(&(*start3));
    display(&(*start3));
    printf("\n");
}
void intersectll(struct node **start1, struct node **start2, struct node **start3)
{
    struct node *p, *q;
    p = *start1;
    q = *start2;
    while (p != NULL && q != NULL)
    {
        if (p->data < q->data)
        {
            p = p->next;
        }
        else if (p->data > q->data)
        {
            q = q->next;
        }
        else
        {
            addbeg(&(*start3), p->data);
            p = p->next;
            q = q->next;
        }
    }
    revll(&(*start3));
    display(&(*start3));
    printf("\n");
}
void diffll(struct node **start1, struct node **start2, struct node **start3)
{
    struct node *p, *q;
    p = *start1;
    q = *start2;
    while (p != NULL && q != NULL)
    {
        if (p->data < q->data)
        {
            addbeg(&(*start3), p->data);
            p = p->next;
        }
        else if (p->data > q->data)
        {
            addbeg(&(*start3), p->data);
            q = q->next;
        }
        else
        {
            p = p->next;
            q = q->next;
        }
    }
    while (p != NULL)
    {
        addbeg(&(*start3), p->data);
        p = p->next;
    }
    revll(&(*start3));
    display(&(*start3));
    printf("\n");
}
void symdiffll(struct node **start1, struct node **start2, struct node **start3)
{
    struct node *p, *q;
    p = *start1;
    q = *start2;
    while (p != NULL && q != NULL)
    {
        if (p->data < q->data)
        {
            addbeg(&(*start3), p->data);
            p = p->next;
        }
        else if (p->data > q->data)
        {
            addbeg(&(*start3), q->data);
            q = q->next;
        }
        else
        {
            p = p->next;
            q = q->next;
        }
    }
    while (p != NULL)
    {
        addbeg(&(*start3), p->data);
        p = p->next;
    }
    while (q != NULL)
    {
        addbeg(&(*start3), q->data);
        q = q->next;
    }
    revll(&(*start3));
    display(&(*start3));
    printf("\n");
}
int main()
{
    struct node *start1 = NULL;
    struct node *start2 = NULL;
    struct node *start3 = NULL;
    orderinser(&start1, 2);
    orderinser(&start1, 7);
    orderinser(&start1, 5);
    orderinser(&start1, 6);
    orderinser(&start1, 10);

    orderinser(&start2, 9);
    orderinser(&start2, 4);
    orderinser(&start2, 7);
    orderinser(&start2, 2);
    orderinser(&start2, 12);

    int option;
    do
    {
        printf("1.Merge\n");
        printf("2. Union\n");
        printf("3. Intersection\n");
        printf("4.Difference\n");
        printf("5. Set difference\n");
        printf("6. EXIT\n");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            mergell(&start1, &start2, &start3);
            break;
        case 2:
            unionll(&start1, &start2, &start3);
            break;
        case 3:
            intersectll(&start1, &start2, &start3);
            break;
        case 4:
            diffll(&start1, &start2, &start3);
            break;
        case 5:
            symdiffll(&start1, &start2, &start3);
            break;
        }
    } while (option != 6);
    return 0;
}