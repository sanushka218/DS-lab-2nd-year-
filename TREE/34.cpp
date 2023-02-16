#include<iostream>
#include<queue>
#include<vector>
using namespace std;
struct node{
    int data;
    int level;
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
void zigzagtraversal(struct node *root)
{
    queue<struct node *>q;
    int h= height(root);
    vector<int>ht[h+1];
    q.push(root);
    root->level=0;
    ht[root->level].push_back(root->data);
    while (q.size()!=0)
    {
        struct node *x;
        x= q.front();
        q.pop();
        if (x->left!=NULL)
        {
            x->left->level= x->level+1;
            q.push(x->left);
            ht[x->left->level].push_back(x->left->data);
        }
        if(x->right!=NULL)
        {
            x->right->level=x->level+1;
            q.push(x->right);
            ht[x->right->level].push_back(x->right->data);
        }
    }
    cout<<"ZIG-ZAG TRAVERSAL IS:-"<<endl;
    int flag=1;
    for(int i=0;i<=h;i++)
    {
        if (flag%2!=0)
        {
            for(int j=0;j<ht[i].size();j++)
            {
                cout<<ht[i][j]<<" ";
            }
        }
        else{
            for(int j= ht[i].size()-1;j>=0;j--)
            {
                cout<<ht[i][j]<<" ";
            }
        }
        flag++; 
    } 
}
int main()
{
    struct node *root;
    root=NULL;
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
    zigzagtraversal(root);
    return 0;
}