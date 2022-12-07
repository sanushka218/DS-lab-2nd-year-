#include <stdio.h>
int main()
{
    int a[10], b[10], c[20], i, j, k, n, m;
    printf("enter the number of elemnets in first array\n");
    scanf("%d", &n);
    printf("enter the number of elements in second array\n");
    scanf("%d", &m);
    printf("enter the first array\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("enter the second array\n");
    for (j = 0; j < m; j++)
    {
        scanf("%d", &b[j]);
    }
    /* set symmetric diffrnce*/
    i=0; j=0; k=0;
        while (i < n && j < m)
        {
            if (a[i]==b[j])
            {
                i++;
                j++;
            }

           else if (a[i] < b[j])
            {
                c[k] = a[i];
                i++;
                k++;
            }
            else
            {
                c[k]=b[j];
                j++;
                k++;
            }
        }
        while (i < n)
        {
            c[k] = a[i];
            i++;
            k++;
        }
        while (j < m)
        {
            c[k] = b[j];
            j++;
            k++;
        }
        printf("the set symmetric diffrence of two array is\n");
        for (i=0; i<k;i++)
        {
            printf("%d\t", c[i]);
        } 
        printf("\n");
    /*set diffrence B-A*/
    i=0; j=0;k=0;
    while (i<n && j<m)
    {
        if (a[i]<b[j])
        {
            c[k]=b[j];
            i++; k++;
        }
        else if (a[i]>b[j])
        {
            c[k]=b[j];
            j++; k++;
        }
        else
        {
            i++; j++;
        }   
    }
    while (j<m)
    {
        c[k]=b[j];
        j++;k++;
    }
    
     printf("the set diffrence B-A is \n");
        for ( j = 0; j < k; j++)
        {
            printf("%d\t", c[j]);
        }
      printf("\n");
    /*set diffrence A-B*/
    i=0; j=0;k=0;
    while (i<n && j<m)
    {
        if (a[i]<b[j])
        {
            c[k]=a[i];
            i++; k++;
        }
        else if (a[i]>b[j])
        {
            c[k]=a[i];
            j++; k++;
        }
        else
        {
            i++; j++;
        }   
    }
    while (i<n)
    {
        c[k]=a[i];
        i++;k++;
    }
    
     printf("the set diffrence A-B is \n");
        for ( i = 0; i < k; i++)
        {
            printf("%d\t", c[i]);
        } 
          printf("\n"); 
    /* intersection*/
    i = 0;
    j = 0;
    k = 0;
    while (i < n && j < m)
    {
        if (a[i] < b[j])
        {
            i++;
        }
        else if (a[i] > b[j])
        {
            j++;
        }
        else
        {
            c[k] = a[i];
            i++;
            j++;
            k++;
        }
    }

    printf("the intersection of two array is\n");
    for (i = 0; i < k; i++)
    {
        printf("%d\t", c[i]);
    }
printf("\n");
        /*union*/
        i=0; j=0; k=0;
        while (i < n && j < m)
        {
            if (a[i]==b[j])
            {
                c[k]=a[i];
                i++;
                j++;
                k++;
            }

           else if (a[i] < b[j])
            {
                c[k] = a[i];
                i++;
                k++;
            }
            else
            {
                c[k]=b[j];
                j++;
                k++;
            }
        }
        while (i < n)
        {
            c[k] = a[i];
            i++;
            k++;
        }
        while (j < m)
        {
            c[k] = b[j];
            j++;
            k++;
        }
        printf("the union of two array is\n");
        for (i= 0; i<k; i++)
        {
            printf("%d\t", c[i]);
        } 
printf("\n");
        /* merging*/
        i=0; j=0; k=0;
        while (i < n && j < m)
        {
            if (a[i] < b[j])
            {
                c[k] = a[i];
                i++;
                k++;
            }
            else
            {
                c[k]=b[j];
                j++;
                k++;
            }
        }
        while (i < n)
        {
            c[k] = a[i];
            i++;
            k++;
        }
        while (j < m)
        {
            c[k] = b[j];
            j++;
            k++;
        }
        printf("the merged array is\n");
        for (k= 0; k< (n+m); k++)
        {
            printf("%d\t", c[k]);
        } 
printf("\n");
        return 0;
}
