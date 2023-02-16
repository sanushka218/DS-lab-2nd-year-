#include<stdio.h>
#include<stdlib.h>
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
void createtree(struct node *root)
{
    int choice;
    int y;
    struct node *p;
    printf("is there a left node of %d\n", root->data);
    scanf("%d", &choice);
    if (choice==1)
    {
        printf("left node: ");
        scanf("%d", &y);
        p=makenode(y);
        root->left=p;
        createtree(p);
    }
    printf("is there a right node of %d\n", root->data);
    scanf("%d", &choice);
    if (choice==1)
    {
        printf("right node: ");
        scanf("%d", &y);
        p=makenode(y);
        root->right=p;
        createtree(p);
    }  
}
void preordertraversal(struct node *root)
{
    if (root != NULL)
    {
        printf("%d\t", root->data);
        preordertraversal(root->left);
        preordertraversal(root->right);
    }
}
void inordertraversal(struct node *root)
{
    if (root != NULL)
    {
        inordertraversal(root->left);
        printf("%d\t", root->data);
        inordertraversal(root->right);
    }
}
void postordertraversal(struct node *root)
{
    if (root != NULL)
    {
        postordertraversal(root->left);
        postordertraversal(root->right);
        printf("%d\t", root->data);
    }
}
int main()
{
    int x;
    struct node *root;
    root=NULL;
    printf("enter the value\n");
    scanf("%d", &x);
    root=makenode(x);
    createtree(root);

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
