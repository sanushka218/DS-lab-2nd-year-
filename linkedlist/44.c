#include <stdio.h>
#include <stdlib.h>
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
void addbeg(struct node **start, int x)
{
    if (*start == NULL)
    {
        struct node *newnode, *ptr;
        newnode = getnode();
        newnode->data = x;
        newnode->next = newnode;
        newnode->prev = newnode;
        *start = newnode;
    }
    else
    {
        struct node *newnode, *ptr;
        newnode = getnode();
        newnode->data = x;
        ptr = *start;
        while (ptr->next != *start)
        {
            ptr = ptr->next;
        }
        ptr->next = newnode;
        newnode->prev = ptr;
        newnode->next = *start;
        (*start)->prev = newnode;
        *start = newnode;
    }
}
void addend(struct node **start, int x)
{
    struct node *newnode, *ptr;
    newnode = getnode();
    newnode->data = x;
    newnode->next = *start;
    ptr = *start;
    while (ptr->next != *start)
    {
        ptr = ptr->next;
    }
    ptr->next = newnode;
    newnode->prev = ptr;
    (*start)->prev = newnode;
}
void deletebeg(struct node **start)
{
    struct node *ptr;
    ptr = *start;
    while (ptr->next != *start)
    {
        ptr = ptr->next;
    }
    ptr->next = (*start)->next;
    (*start)->next->prev = ptr;
    free(&(*start));
    (*start) = ptr->next;
}
void deleteend(struct node **start)
{
    struct node *ptr;
    ptr = *start;
    while (ptr->next != *start)
    {
        ptr = ptr->next;
    }
    ptr->prev->next = *start;
    (*start)->prev = ptr->prev;
    free(ptr);
}
void display(struct node **start)
{
    struct node *ptr;
    ptr = *start;
    while (ptr->next != *start)
    {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
    printf("%d\n", ptr->data);
}
int main()
{
    struct node *start;
    start = NULL;
    int option, y;
    addbeg(&start,1);
     addend(&start,2);
     addend(&start,3);
     addend(&start,4);
     addend(&start,5); 
    do
    {
        printf("************\n");
        printf("1.enter a node at the begining\n");
        printf("2. enter a node at the end\n");
        printf("3. delete the begining node\n");
        printf("4. delete the end node\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            printf("enter the  no\n");
            scanf("%d", &y);
            addbeg(&start, y);
            break;
        case 2:
            printf("enter the  no\n");
            scanf("%d", &y);
            addend(&start, y);
            break;
        case 3:
            deletebeg(&start);
            break;
        case 4:
            deleteend(&start);
            break;
        case 5:
            display(&start);
            break;
        }
    } while (option != 6);

    return 0;
}
