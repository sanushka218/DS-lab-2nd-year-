#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *makenode(int x)
{
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    p->data = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}
int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
        return b;
}
int maxpathsum(struct node *root)
{
    if (root==NULL)
    {
        return 0;
    }
    else 
    if (root->left==NULL && root->right==NULL)
    {
        return root->data;
    }
    else 
    return(root->data+ max(maxpathsum(root->left), maxpathsum(root->right))); 
}
int main()
{
    struct node *root;
    root = NULL;
    root = makenode(7);
    root->left = makenode(6);
    root->right = makenode(9);
    root->left->left = makenode(4);
    root->left->right= makenode(2);
    root->right->left = makenode(3);
    root->right->right = makenode(1);
    root->right->left->right= makenode(2);

    printf("the maximum path is : %d\n", maxpathsum(root));
    return 0;
}