#include <stdio.h>
#include <stdlib.h>
struct node
{
    char data;
    struct node *left;
    struct node *right;
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
void preordertraversal(struct node *root)
{
    if (root != NULL)
    {
        printf("%c\t", root->data);
        preordertraversal(root->left);
        preordertraversal(root->right);
    }
}
void inordertraversal(struct node *root)
{
    if (root != NULL)
    {
        inordertraversal(root->left);
        printf("%c\t", root->data);
        inordertraversal(root->right);
    }
}
void postordertraversal(struct node *root)
{
    if (root != NULL)
    {
        postordertraversal(root->left);
        postordertraversal(root->right);
        printf("%c\t", root->data);
    }
}
int main()
{
    struct node *root;
    root = NULL;
    root= makenode('A');
    root->left = makenode('B');
    root->right = makenode('C');
    root->left->left = makenode('T');
    root->right->left = makenode('M');
    root->right->right = makenode('P');
    root->right->left->right = makenode('X');

    printf("PREORDER-   ");
    preordertraversal(root);
    printf("\n");
    printf("INORDER-   ");
    inordertraversal(root);
    printf("\n");
    printf("INORDER-   ");
    postordertraversal(root);
    printf("\n");
    return 0;
}
