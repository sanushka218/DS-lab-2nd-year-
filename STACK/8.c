#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define size 10
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
void palindrome(int NUM)
{
    int i = 1, flag = 1, sum = 0;
    int n=NUM,count=0;
    while (n != 0)
    {
        push(s, n % 10);
        n = n / 10;
    }
    while(s->top!=-1)
    {
        sum = sum + i* pop(s);
        i=i*10;
    }
    if (sum == NUM)
    {
        printf("palindrome\n");
    }
    else
        printf("not palindrome\n");
}
int main()
{
    int n;
    s = (struct stack *)malloc(sizeof(struct stack));
    create(s);
    printf("enter the number\n");
    scanf("%d", &n);
    palindrome(n);
    return 0;
}
