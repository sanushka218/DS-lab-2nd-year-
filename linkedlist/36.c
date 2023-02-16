#include <stdio.h>
#include <stdlib.h>
struct node
{
    int coef;
    int exp;
    struct node *next;
};
struct node *getnode()
{
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    return p;
}
void addbeg(struct node **poly, int c, int e)
{
    struct node *newnode;
    newnode = getnode();
    newnode->coef = c;
    newnode->exp = e;
    newnode->next = *poly;
    *poly = newnode;
}
void addend(struct node **poly, int c, int e)
{
    struct node *newnode, *ptr;
    ptr = *poly;
    if (*poly == NULL)
    {
        addbeg(&(*poly), c, e);
    }
    else
    {
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        newnode = getnode();
        newnode->coef = c;
        newnode->exp = e;
        newnode->next = NULL;
        ptr->next = newnode;
    }
}
void display(struct node *poly)
{
    struct node *ptr;
    ptr = poly;
    while (ptr != NULL)
    {
        printf("%dx%d +\t", ptr->coef, ptr->exp);
        ptr = ptr->next;
    }
}
void datfororder(int max, struct node *poly3)
{
    struct node *p;
    p = poly3;
    int i;
    int a[20] = {0};
    while (p != NULL)
    {
        a[p->exp] += p->coef;
        p = p->next;
    }
    printf("the multiplied linkedlist is\n");
    for (i = max; i >= 0; i--)
    {
        printf("%dx%d+\t", a[i], i);
    }
}
struct node *mulpoly(struct node *poly1, struct node *poly2)
{
    int max;
    struct node *poly3 = NULL;
    struct node *p, *q;
    p = poly1;
    q = poly2;
    max = p->exp + q->exp;
    while (p != NULL) // O(N^2)
    {
        while (q != NULL)
        {
            addbeg(&poly3, p->coef * q->coef, p->exp + q->exp);
            q = q->next;
        }
        p = p->next;
        q = poly2;
    }
    datfororder(max, poly3);
    return poly3;
}
int main()
{
    struct node *poly1, *poly2, *poly3;
    poly1 = NULL;
    poly2 = NULL;
    poly3 = NULL;
    addend(&poly1, 3, 4);
    addend(&poly1, 3, 3);
    addend(&poly1, -2, 1);
    addend(&poly1, 8, 0);
    printf("first polynomial is\n");
    display(poly1);
    printf("\n");
    addend(&poly2, 2, 5);
    addend(&poly2, 5, 4);
    addend(&poly2, -1, 3);
    addend(&poly2, 7, 2);
    addend(&poly2, -3, 1);
    printf("second polynomial is\n");
    display(poly2);
    printf("\n");
    poly3 = mulpoly(poly1, poly2);
    
    return 0;
}
