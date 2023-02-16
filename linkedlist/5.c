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
struct node *linearsearch(struct node *start, int val)
{
    struct node *ptr,*pos;
    ptr = start;
    while (ptr != NULL)
    {
        if (ptr->data == val )
        {
            return(ptr);
        }
        else
        {
            ptr = ptr->next;
        }
    }
    return (NULL);
}
int main()
{
    int val;
    struct node *answer;
    printf("CREATE A LINKLIST\n");
    start = createll(start);
    printf("enter the value you want to searh\n");
    scanf("%d", &val);
    answer=linearsearch(start, val);
    if (answer==NULL)
    {
        printf("no\n");
    }
    else printf("yes\n");
    
    
    return 0;
}