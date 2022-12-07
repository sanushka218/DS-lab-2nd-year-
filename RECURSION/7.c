#include <stdio.h>
int reversenumber(int n)
{
    int r, sum=0;
    if (n==0)
    {
        return -1;
    }
    else {
        r = n % 10;
        sum = sum * 10 + r;
        reversenumber(n / 10);
        return sum;
    }
    
}
int main()
{
    int n, s;
    printf("enter the number\n");
    scanf("%d", &n);
    s = reversenumber(n);
    printf("the reverse of number is %d", s);
    return 0;
}
