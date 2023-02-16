#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *start = NULL;
struct node *createll(struct node *start)
{
    struct node *newnode, *ptr;
    int num;
    printf("enter -1 to end\n");
    printf("enter the data\n");
    scanf("%d", &num);
    while (num != -1)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = num;
        if (start == NULL)
        {
            newnode->next = NULL;
            start = newnode;
        }
        else
        {
            ptr = start;
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = newnode;
            newnode->next = NULL;
        }
        printf("enter the data\n");
        scanf("%d", &num);
    }
    return start;
}
struct node *display(struct node *start)
{
    struct node *ptr;
    ptr = start;
    while (ptr != NULL)
    {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
    return start;
}
struct node *addbeg(struct node *start)
{
    struct node *newnode;
    int val;
    printf("enter the data\n");
    scanf("%d", &val);
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = start;
    start = newnode;
    return start;
}
struct node *addend(struct node *start)
{
    struct node *newnode, *ptr;
    int val;
    printf("enter the data\n");
    scanf("%d", &val);
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = NULL;
    ptr = start;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = newnode;
    return start;
}
struct node *addafter(struct node *start)
{
    struct node *newnode, *ptr;
    int num, val;
    printf("enter the data\n");
    scanf("%d", &val);
    printf("enter the value after which you want to add\n");
    scanf("%d", &num);
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = val;
    ptr = start;
    while (ptr->data != num)
    {
        ptr = ptr->next;
    }
    newnode->next = ptr->next;
    ptr->next = newnode;
    return start;
}
struct node *addbefore(struct node *start)
{
    struct node *newnode, *ptr;
    int num, val;
    printf("enter the data\n");
    scanf("%d", &val);
    printf("enter the value before which you want to add\n");
    scanf("%d", &num);
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = val;
    ptr = start;
    while (ptr->next->data != num)
    {
        ptr = ptr->next;
    }
    newnode->next = ptr->next;
    ptr->next = newnode;
    return start;
}
struct node *countnodes(struct node *start)
{
    int count = 0;
    struct node *ptr;
    ptr = start;
    while (ptr != NULL)
    {
        count++;
        ptr = ptr->next;
    }
    printf("number of nodes: %d\n", count);
    return start;
}
struct node *deletebeg(struct node *start)
{
    struct node *ptr;
    if (start == NULL)
    {
        printf("underflow\n");
    }
    else
    {
        ptr = start;
        start = start->next;
        free(ptr);
    }
    return start;
}
struct node *deletelast(struct node *start)
{
    struct node *ptr, *preptr;
    if (start == NULL)
    {
        printf("underflow\n");
    }
    else
    {
        ptr = start;
        while (ptr->next != NULL)
        {
            preptr = ptr;
            ptr = ptr->next;
        }
        preptr->next = NULL;
        free(ptr);
    }
    return start;
}
struct node *deleteafter(struct node *start)
{
    struct node *ptr, *preptr;
    int val;
    printf("enter the value after which u want to delete\n");
    scanf("%d", &val);
    if (start == NULL)
    {
        printf("underflow\n");
    }
    else
    {
        ptr = start;
        preptr = ptr;
        while (preptr->data != val)
        {
            preptr = ptr;
            ptr = ptr->next;
        }
        preptr->next = ptr->next;
        free(ptr);
    }
    return start;
}
struct node *deletenode(struct node *start)
{
    struct node *ptr, *preptr;
    int val;
    printf("enter the value after which u want to delete\n");
    scanf("%d", &val);
    if (start == NULL)
    {
        printf("underflow\n");
    }
    else
    {
        ptr = start;
        preptr = ptr;
        while (ptr->data != val)
        {
            preptr = ptr;
            ptr = ptr->next;
        }
        preptr->next = ptr->next;
        free(ptr);
    }
    return start;
}
int main()
{
    int option;
    do
    {
        printf("*************\n");
        printf("1. Create linklist\n");
        printf("2. Display linklist\n");
        printf("3. Add at the begining\n");
        printf("4. Add after a node\n");
        printf("5. Add before a node\n");
        printf("6.Add at the end\n");
        printf("7. Count number of nodes\n");
        printf("8. Delete a node at the begining\n");
        printf("9. Delete a node at the last\n");
        printf("10. Delete a node\n");
        printf("11. Delete a node after\n");
        printf("12. EXIT\n");
        printf("enter your choice\n");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            start = createll(start);
            break;
        case 2:
            start = display(start);
            break;
        case 3:
            start = addbeg(start);
            break;
        case 4:
            start = addafter(start);
            break;
        case 5:
            start = addbefore(start);
            break;
        case 6:
            start = addend(start);
            break;
        case 7:
            start = countnodes(start);
            break;
        case 8:
            start = deletebeg(start);
            break;
        case 9:
            start =
                deletelast(start);
            break;
        case 10:
            start = deletenode(start);
            break;
        case 11:
            start = deleteafter(start);
            break;
        }
    } while (option != 12);

    return 0;
}
