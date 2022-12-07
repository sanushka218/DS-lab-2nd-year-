/*binary search*/
#include <stdio.h>
int bs(int a[], int x, int l, int h)
{
    int mid, flag = 0;
    while (l < h)
    {
        mid = (l + h) / 2;
        if (x < a[mid])
        {
            h = mid - 1;
        }
        else if (x > a[mid])
        {
            l = mid + 1;
        }
        else if (x == a[mid])
        {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
    {
        printf("element found at position %d\n", mid);
    }
    else
    {
        printf("element not found\n");
    }
}
int main()
{
    int a[10], x, mid, n, i;
    printf("enter the number of elements\n");
    scanf("%d", &n);
    printf("enter the element\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("enter the element to be searched\n");
    scanf("%d", &x);
    bs(a, x, 0, n - 1);
    return 0;
}
