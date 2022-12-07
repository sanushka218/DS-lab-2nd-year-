#include <stdio.h>
int hcf(int a, int b)
{
    if (a % b == 0)
        return b;
    return (b, a % b);
}
int main()
{
    int a,b,h;
    printf("enter the two numbers\n");
    scanf("%d %d", &a, &b);
    h=hcf(a,b);
    printf("the GCD of two numbers is %d",h);
    return 0;
}
