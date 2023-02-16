#include<iostream>
using namespace std;
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
struct node *insertBST(struct node *root, int x)
{
    if (root == NULL)
    {
        return (getnode(x));
    }
    else if (x < root->data)
    {
        root->left = insertBST(root->left, x);
    }
    else
    {
        root->right = insertBST(root->right, x);
    }
    return root;
}
void inordertraversal(struct node *root)
{
    if (root != NULL)
    {
        inordertraversal(root->left);
        cout<<root->data<<" ";
        inordertraversal(root->right);
    }
}
int main()
{
    struct node *root;
    root=NULL;
    root=insertBST(root,100);
    root=insertBST(root,90);
    root=insertBST(root,125);
    root=insertBST(root,80);
    root=insertBST(root,95);
    root=insertBST(root,110);
    root=insertBST(root,130);
    root=insertBST(root,70);
    root=insertBST(root,92);
    root=insertBST(root,97);
    root=insertBST(root,127);
    root=insertBST(root,132);
    cout<<"THE INORDER TRAVERSAL OF CREATED TREE-> "<<endl;
    inordertraversal(root);
    return 0;
}