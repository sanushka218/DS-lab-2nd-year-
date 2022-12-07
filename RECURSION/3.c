#include <stdio.h>
int DAT[101];
int fib(int n)
{
    if (n == 1)
    {
        DAT[1] = 0;
    }
    else if (n == 2)
    {
        DAT[2] = 1;
    }
    else if (DAT[n] == 0)
    {
        DAT[n] = fib(n - 1) + fib(n - 2);
    }
    return DAT[n];
}
int main()
{
    int i, n;
    for (i = 1; i <= 100; i++)
    {
        printf("%d\t", fib(i));
    }
    return 0;
}
