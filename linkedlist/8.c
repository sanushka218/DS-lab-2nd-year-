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
struct node *countnodes(struct node *start)
{
    int counte = 0,counto=0;
    struct node *ptr;
    ptr = start;
    while (ptr != NULL)
    {
        if (ptr->data%2==0)
        {
            counte++;
        }
        else counto++;
        ptr = ptr->next;
    }
    printf("number of even data nodes: %d\n", counte);
    printf("number of odd data nodes: %d\n",counto);
    return start;
}
int main()
{
    int option;
    do
    {
        printf("******\n");
        printf("1. Creation of linkedlist\n");
        printf("2. Display\n");
        printf("3. Count even and odd data nodes\n");
        printf("4. EXIT\n");
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
            start = countnodes(start);
            break;
        }
    } while (option != 4);
}