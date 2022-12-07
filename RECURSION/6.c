#include <stdio.h>
void TOH(int n, char X, char Y, char Z)
{
    if (n == 1){
        printf("move disc %d from %c to %c\n", n, X, Z);
        return;
    }
    TOH(n - 1, X, Z, Y);
    printf("move disc %d from %c to %c\n", n, X, Z);
    TOH(n - 1, Y, X, Z);
}
int main()
{
    int n;
    printf("enter the number of discs\n");
    scanf("%d", &n);
    TOH(n, 'A', 'B', 'C');
    return 0;
}