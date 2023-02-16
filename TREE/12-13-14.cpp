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
    int hd;
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
            return 0;
        }
        else
        {
            return (max(height(root->left), height(root->right)) + 1);
        }
    }
}
void topbottomverticaltraversal(struct node *root)
{
    queue<struct node *> q;
    int h = height(root);
    vector<int> hasht[2 * h + 1];
    q.push(root);
    root->hd = 0;
    hasht[root->hd + h].push_back(root->data); //+h so that we dont get any -ve indecies
    while (q.size() != 0)
    {
        struct node *x;
        x = q.front();
        q.pop();
        if (x->left != NULL)
        {
            x->left->hd = x->hd - 1;
            q.push(x->left);
            hasht[x->left->hd + h].push_back(x->left->data);
        }
        if (x->right != NULL)
        {
            x->right->hd = x->hd + 1;
            q.push(x->right);
            hasht[x->right->hd + h].push_back(x->right->data);
        }
    }
    cout << "TOP VIEW OF TREE IS: " << endl;
    for (int i = 0; i < (2 * h) + 1; i++)
    {
        if (hasht[i].size() != 0)
        {
            cout << hasht[i][0] << " ";
        }
    }
     cout << endl;
    cout << "BOTTOM VIEW IS :- " << endl;
    for (int i = 0; i < (2 * h) + 1; i++)
    {
        if (hasht[i].size() != 0)
        {
            cout << hasht[i][(hasht[i].size()) - 1] << " ";
        }
    }
    cout<<endl;
    cout << "VERTICAL TRAVERSAL:- " << endl;
    for (int i = 0; i < (2 * h) + 1; i++)
    {
        if (hasht[i].size() != 0)
        {
            for (int j = 0; j < hasht[i].size(); j++)
            {
                cout << hasht[i][j] << " ";
            }
        }
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

    topbottomverticaltraversal(root);
    return 0;
}