#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#define size 20
struct stack
{
    char a[size];
    int top;
} * s;
void create(struct stack *s)
{
    s->top = -1;
}
void push(struct stack *s, char sym)
{
    if (s->top == size - 1)
    {
        printf("overflow\n");
    }
    else
    {
        s->top++;
        s->a[s->top] = sym;
    }
}
char pop(struct stack *s)
{
    if (s->top == -1)
    {
        printf("underflow\n");
    }
    else
    {
        return (s->a[s->top]);
    }
}
int parenthesis(char exp[])
{
    int i = 0;
    while (exp[i] != '\0')
    {
        if (exp[i] == '(')
        {
            push(s, exp[i]);
        }
        else if (exp[i] == ')')
        {
            return 1;
        }
        i++;
    }
}
int main()
{
    char exp[size];
    int r;
    s = (struct stack *)malloc(sizeof(struct stack));
    create(s);
    printf("enter the expression\n");
    gets(exp);
    r = parenthesis(exp);
    if (r == 1)
    {
        printf("valid\n");
    }
    else
        printf("not valid\n");

    return 0;
}
