#include <iostream>
using namespace std;
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
int identicaltree(struct node *root, struct node *root2)
{
    bool a, b;
    if (root == NULL && root2 == NULL)
    {
        return 1;
    }
    else if (root != NULL && root2 != NULL)
    {
        return (root->data == root2->data && identicaltree(root->left, root2->left) && identicaltree(root->right, root2->right));
    }
    return 0;
}
int main()
{
    int a;
    struct node *root, *root2;
    root = NULL;
    root2 = NULL;
    // CREATION OF TREE-1
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
    // CREATION OF TREE-2
    root2 = makenode(40);
    root2->left = makenode(20);
    root2->right = makenode(60);
    root2->left->left = makenode(30);
    root2->left->right = makenode(10);
    root2->right->left = makenode(25);
    root2->right->right = makenode(55);
    root2->left->right->left = makenode(100);
    root2->left->right->right = makenode(67);
    root2->right->right->left = makenode(50);

   a= identicaltree(root, root2);
   if (a==1)
   {
    printf("BOTH TREES ARE IDENTICAL\n");
   }
   else printf("TREES ARE NOT IDENTICAL\n");
   
    return 0;
}
