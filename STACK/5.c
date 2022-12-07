#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define size 20
struct stack
{
    int a[size];
    int top;
} * s;

void create(struct stack *s)
{
    s->top = -1;
}
void push(struct stack *s, int x)
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
        s->top--;
    }
    return x;
}
int main()
{
    int num, base, result;
    s = (struct stack *)malloc(sizeof(struct stack));
    create(s);
    printf("enter the number\n");
    scanf("%d", &num);
    printf("enter the base\n");
    scanf("%d", &base);
    while (num != 0)
    {
        push(s, num % base);
        num = num / base;
    }
    printf("result is\n");
    while (s->top != -1)
    {
        result = pop(s);
        printf("%d", result);
    }
    return 0;
}
