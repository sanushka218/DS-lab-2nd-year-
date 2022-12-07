#include <stdio.h>
int main()
{
  int a[10], i, n, j, l = 0, b[10] = {0};
  printf("enter the number of elements\n");
  scanf("%d", &n);
  printf("enter the elements\n");
  for (i = 0; i < n; i++)
  {
    scanf("%d", &a[i]);
  }
  j = n - 1;
  for (i = 0; i < n;)
  {
    if (a[i] < a[j])
    {
      l = a[j];
      i++;
    }
    else
    {
      l = a[i];
      j--;
    }
    if (i == j || i > j)
    {
      break;
    }
  }
  printf("largest is %d\n", l);
  for (i = 0; i < n; i++)
  {
    b[a[i]]++;
  }
  for (j = 0; j <= l; j++)
  {
    printf("%d\t", b[j]);
  }
  printf("\n");
  printf("repeated elements are\n");
  for (i = 0; i <= l; i++)
  {
    if (b[i] > 1)
    {
      printf("%d\t", i);
    }
  }
  return 0;
}
