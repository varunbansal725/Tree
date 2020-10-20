#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "stack.h"

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

void InOrder(struct Node *p) {
    if(p) {
        InOrder(p->lchild);
        printf("%d ", p->data);
        InOrder(p->rchild);
    }
}

void PostOrder(struct Node *p) {
    if(p) {
        PostOrder(p->lchild);
        PostOrder(p->rchild);
        printf("%d ", p->data);
    }
}

void LevelOrder(struct Node *p) {
    struct Queue q;
    create(&q, 50);
    printf("%d ", p->data);
    enqueue(&q, p);
    while(!isEmpty(q)) {
        p=dequeue(&q);
        if(p->lchild!=NULL) {
            printf("%d ", p->lchild->data);
            enqueue(&q, p->lchild);
        }
        if(p->rchild!=NULL) {
            printf("%d ", p->rchild->data);
            enqueue(&q, p->rchild);
        }
    }
}

void IPreOrder(struct Node *p) {
    struct Stack stack;
    stack_create(&stack);
    while(p!=NULL || !stack_empty(stack)) {
        if(p) {
            printf("%d ", p->data);
            push(&stack, p);
            p=p->lchild;
        }
        else {
            p=pop(&stack);
            p=p->rchild;
        }
    }
}

void IInOrder(struct Node *p) {
    struct Stack stack;
    stack_create(&stack);
    while(p!=NULL || !stack_empty(stack)) {
        if(p) {
            push(&stack, p);

            p=p->lchild;
        }
        else {
            p=pop(&stack);
            printf("%d ", p->data);
            p=p->rchild;
        }
    }
}

int height(struct Node *p) {
    int x,y;
    if(p!=NULL) {
        x=height(p->lchild);
        y=height(p->rchild);
        if(x > y)
            return x+1;
        else
            return y+1;
    }
    return 0;
}

int nodes(struct Node *p) {
    int x,y;
    if(p!=NULL) {
        x=nodes(p->lchild);
        y=nodes(p->rchild);
        return x+y+1;
    }
    return 0;
}

int sum_of_nodes(struct Node *p) {
    int x,y;
    if(p!=NULL) {
        x=sum_of_nodes(p->lchild);
        y=sum_of_nodes(p->rchild);
        return x+y+p->data;
    }
    return 0;
}

void main()
{
    tree_create();
    printf("\nPreOrder Traversal: ");
    PreOrder(root);
    printf("\nInOrder Traversal: ");
    InOrder(root);
    printf("\nPostOrder Traversal: ");
    PostOrder(root);
    printf("\nIterative PreOrder traversal: ");
    IPreOrder(root);
    printf("\nIterative InOrder traversal: ");
    IInOrder(root);
    printf("\nHeight of tree are: %d", height(root));
    printf("\nSum of nodes in the tree are: %d", sum_of_nodes(root));
    printf("\nNumber of nodes in the tree are: %d", nodes(root));

}
