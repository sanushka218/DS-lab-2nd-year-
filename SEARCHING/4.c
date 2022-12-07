/*jump search*/
#include <stdio.h>
#include <math.h>
int jumpsearch(int a[], int n, int x)
{
    int i , m, j;
    m = sqrt(n);
    i=0;
    while (i < n && x > a[i])
    {
        i = i + m;
        if (i < n)
        {
            if (a[i] == x)
            {
                return i+1;
            }
            else
            {
                for (j = i - m + 1; j < i - 1; j++)
                {
                    if (a[j] == x)
                    {
                        return j+1;
                    }
                }
            }
        }
        else return -1;
    }  
}
int main()
{
    int a[10], n, i, x,f;
    printf("enter the number of elements\n");
    scanf("%d", &n);
    printf("enter the array element\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("enter the number to be searched\n");
    scanf("%d", &x);
    f=jumpsearch(a, n, x);
    if (f==-1)
    {
        printf("element not found\n");
    }
    else{
        printf("element found at position %d", f);
    }
    return 0;
}
