#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

struct Stack {
    int size;
    int top;
    struct Stack **S;
};

void stack_create(struct Stack *st) {
    int x;

    st->size=50;
    st->top=-1;
    st->S=(struct Stack **)malloc(st->size*sizeof(struct Stack *));
};

void push(struct Stack *stack, struct Node * element) {
    if(stack_full(stack))
        printf("stack full");
    else {
        stack->top++;
        stack->S[stack->top]=element;
    }
}

struct Node * pop(struct Stack *stack) {
    struct Node *x=NULL;
    if(stack_empty(stack))
        printf("stack empty");
    else {
        x=stack->S[stack->top];
        stack->top--;
    }
    return x;
}


int stack_empty(struct Stack stack) {
    if(stack.top==-1)
        return 1;
    else
        return 0;
}

int stack_full(struct Stack stack) {
    if(stack.top==stack.size-1)
        return 1;
    else
        return 0;
}




#endif // STACK_H_INCLUDED
