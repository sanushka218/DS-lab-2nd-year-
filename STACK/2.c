#include <stdio.h>
#include <stdlib.h>
#define size 20
struct dtb
{
    int a[size];
    int top;
} * d;
void create(struct dtb *d)
{
    d->top = -1;
}
int isempty(struct dtb *d)
{
    if (d->top == -1)
    {
        return (1);
    }
    return (0);
}
int isfull(struct dtb *d)
{
    if (d->top == size - 1)
    {
        return (1);
    }
    return (0);
}
void push(struct dtb *d,int x)
{
    d->top++;
    d->a[d->top] = x;
}
int pop(struct dtb *d)
{
    int x;
    x = d->a[d->top];
    d->top--;
    return (x);
}
int main()
{
    int num,result;
    d = (struct dtb *)malloc(sizeof(struct dtb));
    create(d);
    printf("enter the number\n");
    scanf("%d", &num);
    while (num !=0)
    {
        if (!isfull(d))
        {
            push(d,num%2);
            num=num/2;
        }
        else
        {
            printf("stack overflow\n");
            exit(0);
        }
    }
    while (!isempty(d))
    {
        result=pop(d);
        printf("%d", result);
    }
    return 0;
}
