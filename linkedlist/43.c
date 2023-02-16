#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *next;
    int data;
    struct node *prev;
};
struct node *getnode()
{
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    return p;
}
struct node *createdoublyll(struct node *start)
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
            newnode->prev = NULL;
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
            newnode->prev = ptr;
            newnode->next = NULL;
        }
        printf("enter the data\n");
        scanf("%d", &num);
    }
    return start;
}
void displaystart(struct node *start)
{
    struct node *ptr;
    ptr = start;
    while (ptr != NULL)
    {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}
void displayend(struct node *start)
{
    struct node *ptr;
    ptr = start;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    while (ptr->prev != NULL)
    {
        printf("%d\t", ptr->data);
        ptr = ptr->prev;
    }
    printf("%d", ptr->data);
    printf("\n");
}
struct node *addbeg(struct node *start)
{
    struct node *newnode;
    int val;
    printf("enter the data\n");
    scanf("%d", &val);
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = val;
    start->prev = newnode;
    newnode->next = start;
    start = newnode;
    return start;
}
struct node *addend(struct node *start)
{
    int x;
    struct node *newnode, *ptr;
    newnode->data = x;
    newnode->next = NULL;
    printf("enter the value\n");
    scanf("%d", &x);
    ptr = start;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = newnode;
    newnode->prev = ptr;
    return start;
}
struct node *addafter(struct node *start)
{
    int x, val;
    struct node *newnode, *ptr;
    newnode = getnode();
    printf("enter the value after which u want to add\n");
    scanf("%d", &x);
    printf("enter the value\n");
    scanf("%d", &val);
    newnode->data = val;
    ptr = start;
    while (ptr->data != x)
    {
        ptr = ptr->next;
    }
    newnode->next = ptr->next;
    ptr->next->prev = newnode;
    ptr->next = newnode;
    newnode->prev = ptr;
    return start;
}
struct node *addbefore(struct node *start)
{
    int x,val;
    struct node *ptr, preptr;
    
    ptr=start;
    preptr=ptr;

}
int main()
{
    struct node *start;
    start = NULL;
    int option;
    do
    {
        printf("***********\n");
        printf("1. Create a link list\n");
        printf("2. Display the link list from head\n");
        printf("3. Display the link list from end\n");
        printf("4. Insert a node at the begining\n");
        printf("5. Insert a node at the end\n");
        printf("6. Insert a node after a node\n");
        printf("7.Insert a node before a node\n");
        printf("8. Delete beginning node\n");
        printf("9. Delete end node\n");
        printf("10. Delete a node after a node\n");
        printf("11. Delete a node before a node");
        printf("12. EXIT\n");
        printf("enter your choice\n");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            start = createdoublyll(start);
            break;
        case 2:
            displaystart(start);
            break;
        case 3:
            displayend(start);
            break;
        case 4:
            start = addbeg(start);
            break;
        case 5:
            start = addend(start);
            break;
        case 6:
            start = addafter(start);
            break;
        }
    } while (option != 12);

    return 0;
}
