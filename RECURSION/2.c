#include<stdio.h>
int expo(int a, int n, int k)
{
    if (n==0)
        return k;
        else return expo(a,n-1,a*k);
}
int main()
{
    int a, n,k=1,e;
    printf("enter the base number A\n");
    scanf("%d", &a);
    printf("enter the power n\n");
    scanf("%d", &n);
    e=expo(a,n,1);
    printf("the exponential is %d\n", e);
        return 0;
}
