#include <stdio.h>
int indexsequentialsearch(int a[], int n, int x)
{
    int index[10], i, j = 0, m;
    m = n / 3;
    
    while (j < m)
    {
        if (a[index[j]] == x)
        {
            return index[j];
        }
        else if (a[index[j]] < x)
        {
            j=j-m;
        }
        else if (a[index[j]] > x)
        {
            j=j+m;
        }
        else
            return -1;
    }
}
int main()
{
    int a[10], i, n, x, f;
    printf("enter the number of elements\n");
    scanf("%d", &n);
    printf("enter the array elements\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("enter the number to be searched\n");
    scanf("%d", &x);
    f = indexsequentialsearch(a, n, x);
if(f==-1)
{
    printf("number is not present\n");
}
   else{
    printf("number is at %d", f);
   } 
    return 0;
}
