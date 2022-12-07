#include<stdio.h>
int main()
{
    int i,n,a[10];
    printf("enter the number of elements\n");
    scanf("%d", &n);
    printf("enter the element\n");
    for(i=0;i<n;i++)
    {
        scanf("%d", &a[i]);

    }
    printf("travesal of array\n");
    for(i=0;i<n;i++)
    {
        printf("%d\n",a[i]);
    }
     return 0;
}
