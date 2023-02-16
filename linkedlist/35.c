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
struct node *subpoly(struct node *poly1, struct node *poly2)
{
    struct node *poly3 = NULL;
    struct node *p, *q;
    p = poly1;
    q = poly2;
    while (p != NULL && q != NULL)
    {
        if (p->exp == q->exp)
        {
            addend(&poly3, p->coef - q->coef, p->exp);
            p = p->next;
            q = q->next;
        }
        else if (p->exp > q->exp)
        {
            addend(&poly3, p->coef, p->exp);
            p = p->next;
        }
        else
        {
            addend(&poly3, q->coef, q->exp);
            q = q->next;
        }
    }
    while (p != NULL)
    {
        addend(&poly3, p->coef, p->exp);
        p = p->next;
    }
    while (q != NULL)
    {
        addend(&poly3, q->coef, q->exp);
        q = q->next;
    }
    return poly3;
}
int main()
{
    struct node *poly1, *poly2, *poly3;
    poly1 = NULL;
    poly2 = NULL;
    poly3 = NULL;
    addend(&poly1, 3, 8);
    addend(&poly1, 5, 7);
    addend(&poly1, -2, 6);
    addend(&poly1, 8, 4);
    printf("first polynomial is\n");
    display(poly1);
    addend(&poly2, 4, 7);
    addend(&poly2, 5, 6);
    addend(&poly2, -1, 3);
    addend(&poly2, 7, 2);
    addend(&poly2, -3, 0);
    printf("second polynomial is\n");
    display(poly2);
    poly3 = subpoly(poly1, poly2);
    printf("the added polynomial is\n");
    display(poly3);
    return 0;
}
