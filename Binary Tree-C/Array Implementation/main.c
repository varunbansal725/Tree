#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

struct Node *root=NULL;

void tree_create() {
    struct Node *p, *t;
    struct Queue queue;
    create(&queue, 100);
    int x, y, z;
    printf("Enter value of root node: ");
    scanf("%d", &x);
    root=(struct Node *)malloc(sizeof(struct Node));
    root->data=x;
    root->lchild=root->rchild=NULL;
    enqueue(&queue, root);
    while(!isEmpty(queue)) {
        p=dequeue(&queue);
        printf("Enter value for left child of %d: ", p->data);
        scanf("%d", &y);
        if(y!=-1) {
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=y;
        t->lchild=t->rchild=NULL;
        p->lchild=t;
        enqueue(&queue, t);

        }
        printf("Enter value for right child of %d: ", p->data);
        scanf("%d", &z);
        if(z!=-1) {
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=z;
        t->lchild=t->rchild=NULL;
        p->rchild=t;
        enqueue(&queue, t);
        }
    }
}

void PreOrder(struct Node *p) {
    if(p) {
        printf("%d ", p->data);
        PreOrder(p->lchild);
        PreOrder(p->rchild);
    }
}


void main()
{
    tree_create();
    PreOrder(root);
}
