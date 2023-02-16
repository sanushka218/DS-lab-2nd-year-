#include<iostream>
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
void inordertraversal(struct node *root2)
{
    if (root2 != NULL)
    {
        inordertraversal(root2->left);
        cout<<root2->data<<" ";
        inordertraversal(root2->right);
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

    return 0;
}
