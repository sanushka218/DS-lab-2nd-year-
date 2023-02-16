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
struct node *sorting(struct node *start)
{
    struct node *ptr1, *ptr2;
    int temp;
    ptr1 = start;
    while (ptr1->next != NULL)
    {
        ptr2 = ptr1->next;
        while (ptr2 != NULL)
        {
            if (ptr1->data > ptr2->data)
            {
                temp = ptr1->data;
                ptr1->data = ptr2->data;
                ptr2->data = temp;
            }
            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
    return start;
}
int main()
{
    printf("First create a link list\n");
    start = createll(start);
    printf("****Unsorted list\n");
    start = display(start);
    printf("Now sort the list\n");
    start = sorting(start);
    printf("****DISPLAYING THE SORTED LISt*****\n");
    start = display(start);
    return 0;
}