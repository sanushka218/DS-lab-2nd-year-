#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct queue{
    struct node *front;
    struct node *rear;
}*q;
struct node *getnode()
{
    struct node *p;
    p=(struct node*)malloc(sizeof(struct node));
    return p;
}
void initializeq(struct queue *q)
{
    q->front=NULL;
    q->rear=NULL;
}
void insert(struct queue *q, int x)
{
    struct node *ptr;
    ptr=getnode();
    ptr->data=x;
    if (q->front==NULL)
    {
        q->front=ptr;
        q->rear=ptr;
    }
    else{
        q->rear->next=ptr;
        q->rear=ptr;
        q->rear->next=NULL;
    }
}
void delete(struct queue *q)
{
    struct node *ptr;
    if (q->front==NULL)
    {
        printf("underflow\n");
    }
    else{
      ptr=q->front;
      q->front=q->front->next;
      free(ptr);
    }
}
void display(struct queue *q)
{
    struct node *ptr;
    ptr=q->front;
    while (ptr!=q->rear)
    {
        printf("%d\t", ptr->data);
        ptr=ptr->next;
    }
    printf("%d",ptr->data);
}
int main()
{
    q=(struct queue *)malloc(sizeof(struct queue));
    initializeq(q);
    insert(q,1);
    insert(q,2);
    insert(q,3);
    insert(q,4);
    insert(q,5);
    display(q);printf("\n");
    insert(q,99);
    delete(q);
    display(q); printf("\n");
    return 0;
}
