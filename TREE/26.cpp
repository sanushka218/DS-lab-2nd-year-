#include <iostream>
#include <queue>
#include <vector>
#include <stdlib.h>
using namespace std;
struct node
{
    int data;
    struct node *left;
    struct node *right;
    int level;
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

        return a;

    else
        return b;
}
int height(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            return 1;
        }
        else
        {
            return (max(height(root->left), height(root->right)) +1);
        }
    }
}
int diameter(struct node *root)
{
    int d1,d2,d3;
    if (root==NULL)
    {
        return 0;
    }
    else {
        d1= height(root->left)+height(root->right)+1;
        d2= diameter(root->left);
        d3= diameter(root->right);
        return(max(max(d1,d2),d3));
    }
}
int main()
{
    struct node *root;
    root = NULL;
    root = makenode(40);
    root->left = makenode(20);
    root->right = makenode(60);
    root->left->left = makenode(30);
    root->left->right = makenode(10);
    root->right->left = makenode(25);
    root->right->right = makenode(55);
    root->left->right->left = makenode(100);
    root->left->right->right = makenode(67);
    root->right->right->left = makenode(50);
    cout<<diameter(root)<<endl;
    return 0;
}