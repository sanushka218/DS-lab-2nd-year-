#include<stdio.h>
int main()
{
    int i,j,n,x,a[10];
    printf("enter the number of elements\n");
    scanf("%d",&n);
    printf("enter the elements\n");
    for(i=0;i<n;i++)
    {
        scanf("%d", &a[i]);
    }
    printf("enter the number that you want to insert\n");
    scanf("%d",&x);
    for(j=n-1;j<n;j++)
    {
        a[j+1]=a[j];
        a[i]=x;
        n=n+1;
    }
    printf("new array\n");
    for(i=0;i<n;i++)
    {
        printf("%d", a[i]);
    }
    return 0;
}
