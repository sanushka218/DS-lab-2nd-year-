#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define size 20
struct stack
{
    int a[size];
    int top;
}*s;

void create(struct stack *s)
{
    s->top = -1;
}
void push(struct stack *s,int x)
{
    if (s->top == size - 1)
    {
        printf("overflow\n");
    }
    else
    {
        s->top++;
        s->a[s->top] = x;
    }
}
int pop(struct stack *s)
{
    int x;
    if (s->top == -1)
    {
        printf("underflow\n");
    }
    else
    {
        x = s->a[s->top];
        printf("\n\npopped element is=%d\n", x);
        s->top--;
    }
}
int display(struct stack *s)
{
    printf("\nSTACK:");
    for(int i=0;i<=s->top;i++)
    {
        printf("%d ",s->a[i]);
    }
    printf("\n");
}

int main()
{
    int i,x;
    s = (struct stack *)malloc(sizeof(struct stack));
    create(s);
    while (1)
    {
        printf("enter the choice\n");
        printf("1.Push the element\n");
        printf("2.Pop the element\n");
        printf("3. know the element at top of stack\n");
        printf("4. Display");
        printf("5. Exit\n");
        scanf("%d", &i);
        switch (i)
        {
        case 1:
            printf("\n\nenter the element to be pushed:");
            scanf("%d", &x);
            push(s,x);
            break;
        case 2:
            pop(s);
            break;
        case 3:
            printf("\n\nELEMENT AT TOP:%d \n\n",s->a[s->top]);
            break;
        case 4:
            display(s);
            break;
        case 5:
            return 0;
        }
    }
    return 0;
}
