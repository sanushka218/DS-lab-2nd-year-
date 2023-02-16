#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *getnode(int x)
{
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    p->data = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}
struct node *createBST(struct node *root, int x)
{
    if (root == NULL)
    {
        return (getnode(x));
    }
    else if (x < root->data)
    {
        root->left = createBST(root->left, x);
    }
    else
    {
        root->right = createBST(root->right, x);
    }
    return root;
}
void inordertraversal(struct node *root)
{
    if (root != NULL)
    {
        inordertraversal(root->left);
        printf("%d\t", root->data);
        inordertraversal(root->right);
    }
}
bool searchBST(struct node *root, int x)
{
    if (root == NULL)
    {
        return false;
    }
    else if (root->data == x)
    {
        return true;
    }
    else if (x < root->data)
    {
        searchBST(root->left, x);
    }
    else
    {
        searchBST(root->right, x);
    }
}
struct node *insertBST(struct node *root, int x)
{
    if (root == NULL)
    {
        return (getnode(x));
    }
    if (x < root->data)
    {
        root->left = insertBST(root->left, x);
    }
    else
    {
        root->right = insertBST(root->right, x);
    }
    return root;
}
int main()
{
    int x, y;
    struct node *root;
    root = NULL;
    root = createBST(root, 20);
    root = createBST(root, 15);
    root = createBST(root, 30);
    root = createBST(root, 40);
    root = createBST(root, 50);
    root = createBST(root, 12);
    root = createBST(root, 18);
    root = createBST(root, 35);
    root = createBST(root, 80);
    root = createBST(root, 7);
    printf("tree is:\n");
    inordertraversal(root);
    printf("\n");
    printf("enter the number u want to search\n");
    scanf("%d", &x);
    y = searchBST(root, x);
    printf("%d", y);
    printf("\n");
    printf("enter the element you want to insert\n");
    scanf("%d", &x);
    root = insertBST(root, x);
    inordertraversal(root);
    return 0;
}
