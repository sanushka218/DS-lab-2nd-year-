#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *start1 = NULL;
struct node *start2 = NULL;
struct node *create1(struct node *start1)
{
    struct node *newnode, *ptr1;
    int num;
    printf("enter -1 to end\n");
    printf("enter the data\n");
    scanf("%d", &num);
    while (num != -1)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = num;
        if (start1 == NULL)
        {
            newnode->next = NULL;
            start1 = newnode;
        }
        else
        {
            ptr1 = start1;
            while (ptr1->next != NULL)
            {
                ptr1 = ptr1->next;
            }
            ptr1->next = newnode;
            newnode->next = NULL;
        }
        printf("enter the data\n");
        scanf("%d", &num);
    }
    return start1;
}
struct node *create2(struct node *start2)
{
    struct node *newnode, *ptr2;
    int num;
    printf("enter -1 to end\n");
    printf("enter the data\n");
    scanf("%d", &num);
    while (num != -1)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = num;
        if (start2 == NULL)
        {
            newnode->next = NULL;
            start2 = newnode;
        }
        else
        {
            ptr2 = start2;
            while (ptr2->next != NULL)
            {
                ptr2 = ptr2->next;
            }
            ptr2->next = newnode;
            newnode->next = NULL;
        }
        printf("enter the data\n");
        scanf("%d", &num);
    }
    return start2;
}
struct node *concatenate(struct node *start1, struct node *start2)
{
    struct node *ptr1;
    ptr1 = start1;
    while (ptr1->next != NULL)
    {
        ptr1 = ptr1->next;
    }
    ptr1->next = start2;
    return start1;
}
struct node *display(struct node *start1)
{
    struct node *ptr;
    ptr = start1;
    while (ptr != NULL)
    {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
    return start1;
}
int main()
{
    int option;
    printf("******\n");
    printf("CREATE 1ST LINKLIST\n");
    start1 = create1(start1);
    printf("CREATE 2ND LINKLIST\n");
    start2 = create2(start2);
    start1 = concatenate(start1, start2);
    printf("ON CONCATENATION OF LINK LIST\n");
    start1 = display(start1);
    return 0;
}