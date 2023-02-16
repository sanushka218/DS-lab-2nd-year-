#include <stdio.h>
#include <stdlib.h>
#define size 20
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *getnode()
{
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    return p;
}
void addbeg(struct node **start, int val)
{
    struct node *newnode;
    newnode = getnode();
    newnode->data = val;
    newnode->next = *start;
    *start = newnode;
}
void addend(struct node **start, int x)
{
    /*  if (*start = NULL)
    {
        addbeg(&(*start), x);
    }
    else
    {  */
        struct node *newnode, *ptr;
        newnode=getnode();
        newnode->data = x;
        newnode->next = NULL;
        ptr = *start;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = newnode;
        newnode->prev = ptr;
   // }
}
void palindrome(struct node **start)
{
    struct node *head, *tail;
    int count=1,i=1,temp;
    head=*start;
    while (head->next!=NULL)
    {
        count++;
        head=head->next;
    }
    printf("%d\n", count);
    tail=head;
    head=*start;
    while (i<=count/2)
    {
        temp=head->data;
        head->data=tail->data;
        tail->data=temp;
        head=head->next;
        tail=tail->prev;
        i++;
    }
if (i==(count/2)+1)
{
    printf("palindrome\n");
}
else printf("not a palindrome\n");
}
int main()
{
    struct node *start;
    start = NULL;
    addbeg(&start, 9);
    addend(&start, 3);
    addend(&start, 6);
    addend(&start, 3);
    addend(&start, 9);
    palindrome(&start);
}