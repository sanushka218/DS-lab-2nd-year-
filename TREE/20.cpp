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
void mirrorimageoftree(struct node *root)
{
    struct node *temp = NULL;
    if (root == NULL)
    {
        return;
    }
    else
    {
        mirrorimageoftree(root->left);
        mirrorimageoftree(root->right);
        temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
}
void inordertraversal(struct node *root)
{
    if (root != NULL)
    {
        inordertraversal(root->left);
        cout << root->data << " ";
        inordertraversal(root->right);
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
    cout << "ORIGINAL TREE-> ";
    inordertraversal(root);
    cout << endl;
    mirrorimageoftree(root);
    cout << "MIRROR IMAGE-> ";
    inordertraversal(root);
    cout << endl;
    return 0;
}