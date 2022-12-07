#include <stdio.h>
struct marks
{
    int rn;
    char name[20];
    int cm, pm, mm;
} m[3];
int main()
{
    int sum, i;
    float per;
    for (i = 0; i < 2; i++)
    {
        printf("enter the roll no\n");
        scanf("%d", &m[i].rn);
        printf("enter name\n");
        fflush(stdin);
        gets(m[i].name);
        printf("enter CHEM marks\n");
        scanf("%d", &m[i].cm);
        printf("enter PHY marks\n");
        scanf("%d", &m[i].pm);
        printf("enter MATHS marks\n");
        scanf("%d", &m[i].mm);
        sum = m[i].cm + m[i].pm + m[i].mm;
        per = sum / 3;
        printf("percetage is %f\n", per);
    }
    return 0;
}
