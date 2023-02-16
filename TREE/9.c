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
int main()
{
    struct node *root;
    root = NULL;
    root = makenode(1);
    root->left = makenode(2);
    root->right = makenode(3);
    root->left->left = makenode(4);
    root->left->right = makenode(5);
    root->right->left = makenode(6);
    root->right->right = makenode(7);
    root->left->left->left = makenode(8);
    root->left->left->right = makenode(9);
    root->left->right->left = makenode(10);
    root->left->right->right = makenode(11);
    root->right->left->left = makenode(12);
    root->right->left->right = makenode(13);

    
    return 0;
}
