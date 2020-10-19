#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

struct Node {
    int data;
    struct Node *lchild;
    struct Node *rchild;
};

struct Queue {
    int size;
    int front;
    int rear;
    struct Node **Q;
};

void create(struct Queue *queue, int size) {
    queue->front=queue->rear=0;
    queue->size=size;
    queue->Q=(struct Node **)malloc(queue->size*sizeof(struct Node *));
}

void enqueue(struct Queue *queue, struct Node * element) {
    if((queue->rear+1)%queue->size==queue->front)
        printf("Queue Full");
    else {
        queue->rear=(queue->rear+1)%queue->size;
        queue->Q[queue->rear]=element;
    }
}

struct Node * dequeue(struct Queue *queue) {
    struct Node* x=NULL;
    if(queue->rear==queue->front) {
        printf("Queue empty");
        return;
    }
    else {
        queue->front=(queue->front+1)%queue->size;
        x=queue->Q[queue->front];
    }
    return x;
}

int isEmpty(struct Queue queue) {
    if(queue.rear==queue.front)
        return 1;
    else
        return 0;
}

int isFull(struct Queue queue) {
    if((queue.rear+1)%queue.size==queue.front)
        return 1;
    else
        return 0;
}


#endif // QUEUE_H_INCLUDED
