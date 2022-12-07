/*ternary search*/
#include <stdio.h>
int ts(int a[], int x, int l, int h)
{
    int mid1, mid2;
    while (l < h)
    {
        mid1 = l + (h - l) / 3;
        mid2 = h - (h - l) / 3;
        if (x < a[mid1])
        {
            h = mid1 - 1;
        }
        else if (x > a[mid1])
        {
            l = mid1 + 1;
        }
        else if (x < a[mid2])
        {
            l = mid1 + 1;
            h = mid2 - 1;
        }
        else if (x > a[mid2])
        {
            l = mid2 + 1;
        }
        else if (x == mid1)
        {
            return mid1;
            break;
        }
        else if (x == mid2)
        {
            return mid2;
            break;
        }
    }
    return -1;
}
int main()
{
    int a[10], i, n, x, found;
    printf("enter the number of element\n");
    scanf("%d", &n);
    printf("enter the element\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("enter the element to find\n");
    scanf("%d", &x);
    found = ts(a, x, 0, n - 1);
    if (found == -1)
    {
        printf("element not found\n");
    }
    else
    {
        printf("element found at %d ", found);
    }
    return 0;
}