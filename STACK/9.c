#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define size 20
struct stack{
    char a[size];
    int top;
}*s;
void create(struct stack *s)
{
    s->top=-1;
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
    char x;
    if (s->top == -1)
    {
        printf("underflow\n");
    }
    else
    {
        x=s->a[s->top];
        s->top--;
    }
    return x;
}
void reversestr(char str[])
{
    char result[size];
    int i=0,j=0;
    while (str[i]!= '\0')
    {
        push(s,str[i]);
        i++;
    }
    while (s->top>=0)
    { 
        result[j]=pop(s);
        j++;
    }
    result[j]='\0';
    printf("the reversed string is\n");
    puts(result); 
}
int main()
{
    char str[size];
    s= (struct stack *)malloc(sizeof(struct stack));
    create(s);
    printf("enter the string\n");
    gets(str);
    reversestr(str);
    return 0;
}
