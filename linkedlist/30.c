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
void kthnode(struct node **start, int k)
{
    int a;
    struct node *i,*j,*temp;
    i=*start;
    j=*start;
    for(a=0;a<k;a++)
    {
        printf("%d\n",a);
        i=i->next;
    }
    while (i!=NULL && i->next!=NULL)
    {
        i=i->next;
        j=j->next;
    }
    temp=j->next;
    j->next=temp->next;
    free(temp);    
}
int main()
{
    int k;
    struct node *start;
    start=NULL;
    inserend(&start,2);
    inserend(&start,4);
    inserend(&start,6);
    inserend(&start,7);
    inserend(&start,1);
    inserend(&start, 9);
    printf("original linkedlist: ");
    display(&start);
    printf("enter the kth node you want to delete from the last\n");
    scanf("%d", &k);
    kthnode(&start,k);
    printf("after deletion:  ");
    display(&start);
    
}