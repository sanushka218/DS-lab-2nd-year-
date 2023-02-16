#include <iostream>
#include <stdlib.h>
using namespace std;
struct node
{
    int data;
    struct node *left;
    struct node *right;
    struct node *father;
};
struct node *makenode(int x)
{
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    p->data = x;
    p->left = NULL;
    p->right = NULL;
    p->father = NULL;
    return p;
}
struct node *bstinsert(struct node *root, int x)
{
    struct node *temp;
    if (root == NULL)
    {
        root = makenode(x);
    }
    else if (x < root->data)
    {
        temp = bstinsert(root->left, x);
        root->left = temp;
        temp->father = root;
    }
    else
    {
        temp = bstinsert(root->right, x);
        root->right = temp;
        temp->father = root;
    }
    return root;
}
struct node *bstsearch(struct node *root, int x)
{
    while (root != NULL)
    {
        if (root->data == x)
        {
            return root;
        }
        else
        {
            if (x < root->data)
            {
                root = root->left;
            }
            else
                root = root->right;
        }
    }
    return NULL;
}
struct node *minnode(struct node *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return (root);
}
struct node *maxnode(struct node *root)
{
    while (root->right != NULL)
    {
        root = root->right;
    }
    return (root);
}
struct node *successor(struct node *p)
{
    struct node *q;
    if (p->right != NULL)
    {
        return minnode(p->right);
    }
    else
    {
        q = p->father;
        while (q != NULL && q->right == p)
        {
            p = q;
            q = q->father;
        }
        return q;
    }
}
struct node *predecessor(struct node *p)
{
    struct node *q;
    if (p->left!=NULL)
    {
        return maxnode(p->left);
    }
    else{
        q=p->father;
        while (q!=NULL && q->left==p)
        {
            p=q;
            q=q->father;
        }
        return q; 
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
    struct node *root, *temp1, *temp2;
    root = NULL;
    int x, y;
    root = bstinsert(root, 100);
    root = bstinsert(root, 90);
    root = bstinsert(root, 125);
    root = bstinsert(root, 80);
    root = bstinsert(root, 110);
    root = bstinsert(root, 95);
    root = bstinsert(root, 130);
    root = bstinsert(root, 70);
    root = bstinsert(root, 92);
    root = bstinsert(root, 97);
    root = bstinsert(root, 127);
    root = bstinsert(root, 132);
    cout << "INORDER TRAVERSAL ";
    inordertraversal(root);
    cout << endl;
    cout << "MAX ELEMENT OF TREE-> " << (maxnode(root))->data << endl;
    cout << "MIN ELEMENT OF TREE-> " << (minnode(root))->data << endl;
    cout << "enter whose successor you want to find" << endl;
    cin >> x;
    temp1 = successor(bstsearch(root, x));
    if (temp1 == NULL)
    {
        cout << "THERE IS NO SUCCESSOR" << endl;
    }
    else
    {
        cout << "THE SUCCESSOR OF " << x << " is " << temp1->data << endl;
    }
    cout<<"enter whose predecessor you want to find "<<endl;
    cin>>y;
    temp2= predecessor(bstsearch(root,y));
    if (temp2==NULL)
    {
        cout<<"THERE IS NO PREDECESSOR"<<endl;
    }
    else{
        cout<<"THE PREDECESSOR OF "<<y<<" is "<<temp2->data<<endl;
    }

    return 0;
}
