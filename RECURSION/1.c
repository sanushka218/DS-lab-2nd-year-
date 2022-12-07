#include<stdio.h>
int fact(int n, int k)
{
    if(n==0)
    return k;
    else
    return fact(n-1, n*k);
}
int main()
{
    int n,k=1,f;
    printf("enter the number you want factorial of\n");
    scanf("%d", &n);
    f= fact(n,1);
    printf("the factorial is %d\n", f);
    return 0;
}
