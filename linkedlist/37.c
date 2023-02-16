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
struct node *addbeg(struct node *start, int val)
{
    struct node *newnode, *ptr;
    newnode = getnode();
    newnode->data = val;
    if (start==NULL)
    {
         newnode->next = newnode;
        start = newnode;
    }
    else
    {
        ptr=start;
        while (ptr->next!=start)
        {
            ptr=ptr->next;
        }
        ptr->next=newnode;
        newnode->next=start;
        start=newnode;  
    }
    return start;
}
struct node *addend(struct node *start, int val)
{
    if (start == NULL)
    {
        start = addbeg(start, val);
    }
    else
    {
        struct node *newnode, *ptr;
        newnode = getnode();
        newnode->data = val;
        ptr = start;
        while (ptr->next != start)
        {
            ptr = ptr->next;
        }
        ptr->next = newnode;
        newnode->next = start;
    }
    return start;
}
struct node *deletebeg(struct node *start)
{
    struct node *ptr;
    ptr = start;
    while (ptr->next != start)
    {
        ptr = ptr->next;
    }
    ptr->next = start->next;
    free(start);
    start = ptr->next;
    return start;
}
struct node *deleteend(struct node *start)
{
    struct node *preptr, *ptr;
    ptr = start;
    while (ptr->next != start)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = start;
    free(ptr);
    return start;
}
struct node *display(struct node *start)
{
    struct node *ptr;
    ptr = start;
    while (ptr->next != start)
    {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
    printf("%d\t", ptr->data);
    printf("\n");
    return start;
}
int main()
{
    int option, value;
    struct node *start = NULL;
    start = addend(start, 4);
    start = addend(start, 12);
    start = addend(start, 9);
    start = addend(start, 33);
    start = addend(start, 78);
    do
    {
        printf("1. Display\n");
        printf("2. Add at the beginning\n");
        printf("3. Add at the end\n");
        printf("4. Delete at the beginning\n");
        printf("5. Delete at the end\n");
        printf("6. Exit\n");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            start = display(start);
            break;
        case 2:
            printf("enter the value\n");
            scanf("%d", &value);
            start = addbeg(start, value);
            break;
        case 3:
            printf("enter the value\n");
            scanf("%d", &value);
            start = addend(start, value);
            break;
        case 4:
            start = deletebeg(start);
            break;
        case 5:
            start = deleteend(start);
            break;
        }
    } while (option != 6);
    return 0;
}