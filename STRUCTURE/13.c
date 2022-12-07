#include <stdio.h>
#include <string.h>
int count = 3;
struct books
{
    char name[30];
    char author[30];
    int no;
} b[5];
void display()
{
    int i;
    printf("The availabe books at library are:\n");
    for (i = 0; i < count; i++)
    {
        printf("%s ", b[i].name);
        printf("%s", b[i].author);
        printf("\n");
    }
}
void add()
{
    printf("enter the book details\n");
    printf("enter the name\n");
    gets(b[3].name);
    printf("enter the author name\n");
    gets(b[3].author);
    count = count + 1;
}
void displayauthor()
{
    char a[20];
    int i;
    printf("enter the author name\n");
    fflush(stdin);
    gets(a);
    for (i = 0; i < count; i++)
    {
        if (b[i].author == a)
        {
            printf("%s", b[i].name);
        }
    }
}
void displaybook()
{
    char title[20];
    int i, f;
    printf("enter the tile\n");
    scanf("%s", &title);
    for (i = 0; i < count; i++)
    {
        f = strcmp(b[i].name, title);
        if (f == 1)
        {
            printf("%d\n", b[i].no);
        }
        else
        {
            printf("book not available of the entered title\n");
        }
    }
}
void displaytotal()
{
    printf("total number of books in the library are %d", count);
}
void issue()
{
    char title[20];
    int i;
    printf("to issue a book enter the name of the book\n");
    gets(title);
    for (i = 0; i < count; i++)
    {
        if (title == b[i].name)
        {
            printf("book issued\n");
        }
        else
        {
            printf("book not available in the library\n");
        }
    }
    count--;
}
int main()
{
    strcpy(b[0].name, "A Christmas Tale");
    strcpy(b[0].author, "Germino Silton");
    b[0].no = 1;
    strcpy(b[1].name, "The subtle art of not giving ");
    strcpy(b[1].author, "Mark Manson");
    b[1].no = 1;
    strcpy(b[2].name, "Atomic Habits");
    strcpy(b[2].author, "James clear");
    b[2].no = 1;

    int i, b;
    printf(" THE LIBRARY MENU:\n");
    printf("1 - Display book information\n");
    printf("2 - Add a new book\n");
    printf("3 - Display all the books in the library of a particular author\n");
    printf("4 - Display the number of books of a particular title\n");
    printf("5 - Display the total number of books in the library\n");
    printf("6 - Issue a book\n");
    scanf("%d", &i);
    switch (i)
    {
    case 1:
        display(b);
        break;
    case 2:
        add(b);
        break;
    case 3:
        displayauthor(b);
        break;
    case 4:
        displaybook(b);
        break;
    case 5:
        displaytotal(b);
        break;
    case 6:
        issue(b);
        break;
        return 0;
    }
}
