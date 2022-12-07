#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define size 30
struct os
{
    int a[size];
    int top;
} * o;
void create(struct os *o)
{
    o->top = -1;
}
void push(struct os *o, int op)
{
    if (o->top == size - 1)
    {
        printf("overflow\n");
    }
    else
    {
        o->top++;
        o->a[o->top] = op;
    }
}
int pop(struct os *o)
{
    int x;
    if (o->top == -1)
    {
        printf("underflow\n");
    }
    else
    {
        x = o->a[o->top];
        o->top--;
    }
    return x;
}
int postfixevaluation(char exp[])
{
    int i = 0, value, a, b;
    while (exp[i] != '\0')
    {
        if (isdigit(exp[i]))
        {
            push(o, (exp[i] - '0'));
        }
        else
        {
            a = pop(o);
            b = pop(o);
            switch (exp[i])
            {
            case '+':
                value = (a + b);
                break;
            case '-':
                value = (a - b);
                break;
            case '*':
                value = (a * b);
                break;
            case '/':
                value = (a / b);
                break;
            case '%':
                value = (a % b);
                break;
            }
            push(o, value);
        }
        i++;
    }
    return (pop(o));
}
int main()
{
    char exp[size];
    int r;
    o = (struct os *)malloc(sizeof(struct os));
    create(o);
    printf("enter the expression\n");
    gets(exp);
    r = postfixevaluation(strrev(exp));
    printf("result is : %d\n", r);
    return 0;
}
