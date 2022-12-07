#include <stdio.h>
int main()
{
    int r1, c1, r2, c2, a[10][10], i, j, k, b[10][10], m[10][10],sum=0;
    printf("enter the number of rows of first matrix\n");
    scanf("%d", &r1);
    printf("enter the number of columns of first matrix\n");
    scanf("%d", &c1);
    printf("enter the number of rows of second matrix\n");
    scanf("%d", &r2);
    printf("enter the number of columns of second matrix\n");
    scanf("%d", &c2);
    if (c1 != r2)
    {
        printf("the matrix cant be multiplied\n");
    }
    else
    {
        printf("enter the matrix A elements\n");
        for (i = 0; i < r1; i++)
        {
            for (j = 0; j < c1; j++)
            {
                scanf("%d", &a[i][j]);
            }
        }
        printf("enter the matrix B elements\n");
        for (i = 0; i < r2; i++)
        {
            for (j = 0; j < c2; j++)
            {
                scanf("%d", &b[i][j]);
            }
        }
        for (i = 0; i < r1; i++)
        {
            for (j = 0; j < c2; j++)
            {
                m[i][j]=0;
                for (k = 0; k < c1; k++)
                {
                    m[i][j] +=a[i][k] * b[k][j];
                    
                }
            }
        }
        for (i = 0; i < r1; i++)
        {
            for (j = 0; j < c2; j++)
            {
                printf("%d\t", m[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}