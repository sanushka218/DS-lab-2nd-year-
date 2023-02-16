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
void addbeg(struct node **start, int x)
{
    struct node *newnode;
    newnode = getnode();
    newnode->data = x;
    newnode->next = *start;
    *start = newnode;
}
void addend(struct node **start, int x)
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
struct node *middleement(struct node *start)
{
    struct node *i, *j;
    i = start;
    j = start->next;
    while (j != NULL && j->next != NULL)
    {
        i = i->next;
        j = j->next->next;
    }
    return i;
}
struct node *binarysearch(struct node *start, int key)
{
    struct node *mid;
    if (start != NULL)
    {
        mid = middleement(start);
        if (mid->data == key)
        {
            return mid;
        }
        else
        {
            if (key < mid->data)
            {
                mid->next = NULL;
                    binarysearch(start, key);
            }
            else
            {
                start = mid->next;
                binarysearch(start, key);
            }
        }
    }
    else return NULL;
}
int main()
{
    int key;
     struct node *start,*ptr;
     start=NULL;
     addbeg(&start,2);
     addend(&start,4);
     addend(&start,7);
     addend(&start,12);
     addend(&start,19);
     addend(&start,40);
     printf("the linkedlist is:  ");
    display(&start);
     printf("enter the number you want to find\n");
    scanf("%d", &key);
    ptr= binarysearch(start,key);
    printf("%d is at %d\n", key,ptr);

    return 0;
}
