#include<iostream>
using namespace std;
struct node{
    char data;
    struct node *left;
    struct node *right;
};
struct node *makenode(char x)
{
    struct node *p;
    p=(struct node *)malloc(sizeof(struct node));
    p->data=x;
    p->left=NULL;
    p->right=NULL;
    return p;
}
struct node *buildtree(char in[], char pre[], int istart, int iend)
{
    int pindex=0;
    if(istart>iend)
    {
        return NULL;
    }
    struct node *temp;
    temp= makenode(pre[pindex]);
    if(istart==iend)
    {
        return temp;
    }
}
int main()
{
    
    return 0;
}
