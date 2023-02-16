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
void leftviewtraversal(struct node *root)
{
    queue<struct node *> q;
    int h = height(root);
    cout<<h<<endl;
    vector<int>hasht[h];
    q.push(root);
    root->level = 0;
    hasht[root->level].push_back(root->data);
    while (q.size() != 0)
    {
        struct node *x;
        x = q.front();
        q.pop();
        if (x->left != NULL)
        {
            x->left->level = x->level + 1;
            q.push(x->left);
            hasht[x->left->level].push_back(x->left->data);
        }
        if (x->right != NULL)
        {
            x->right->level = x->level + 1;
            q.push(x->right);
            hasht[x->right->level].push_back(x->right->data);
        }
    }
    cout << "LEFT VIEW OF TREE:- " << endl;
    for (int i = 0; i < h; i++)
    {
        cout << hasht[i][0] << "  ";
    }
    cout << endl;
    cout << "RIGHT VIEW IS:- " <<endl;
    for (int i = 0; i < h; i++)
    {
        int x;
        x= hasht[i].size();
        cout << hasht[i][x-1] <<" ";
    }
    cout << endl;
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
    leftviewtraversal(root);
    return 0;
}