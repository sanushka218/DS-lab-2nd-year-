#include <iostream>
#include <stack>
using namespace std;
struct node
{
    char data;
    struct node *left;
    struct node *right;
    // struct node *next;
};
struct node *makenode(char x)
{
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    p->data = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}
int pred(char a, char b)
{
    if (a == '#' || a == '*' || a == '/' || a == '%')
    {
        if (b == "#")
        {
            return 0;
        }
        else
            return 1;
    }
    else
    {
        if (a == '+' || a == '-')
        {
            if (b == '+' || b == '-')
            {
                return 1;
            }
            else
                return 0;
        }
    }
}
struct node *buildexptree(char exp[])
{
    struct node *x, *y, *sy;
    // struct node *start=NULL, *p, *q;
    stack<struct node *> opd, opt;
    int i;
    char symb, k, op;
    while (exp[i] != '\0')
    {
        symb = exp[i];
        i++;
        if (symb >= 'a' && symb <= 'z')
        {
            x = makenode(symb);
            // x->next=start;
            // start=x;
            push(opd, x);
        }
        else
        {
            k = (opt.top())->data;
            while (!opt.empty() && pred(k, symb))
            {
                op = (opt.top())->data;
                opt.pop();
                y = makenode(op);
                y->right = opd.top();
                opd.pop();
                y->left = opd.top();
                opd.pop();
                opd.push(y);
            }
            sy->data = symb;
            opt.push(sy);
        }
    }
    while (!opt.empty)
    {
        op = (opt.top())->data;
        opt.pop();
        y = makenode(op);
        y->right = opd.top();
        opd.pop();
        y->left = opd.top();
        opd.pop();
        opd.push(y);
    }
    return (opd.top);
}
void preordertraversal(struct node *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        preordertraversal(root->left);
        preordertraversal(root->right);
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
    char exp[20];
    scanf("%s", exp);
    root = buildexptree(exp);
    cout << "INFIX->"
         << " ";
    inordertraversal(root);
    cout << endl;
    cout << "PREFIX:-"
         << " ";
    preordertraversal(root);
    cout << endl;
}