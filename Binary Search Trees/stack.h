#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

struct Stack {
    int size;
    int top;
    int *s;
}*top=NULL;

void create_stack(struct Stack *stack, int size) {
    stack->size=20;
    stack->top=-1;
    stack->s=(struct Stack **)malloc((stack->size)*sizeof(struct stack *));
}

void push(struct Stack *stack, struct Node * element) {
    if(stack->top==stack->size-1) {
        printf("Stack Full");
    }
    else {
        stack->top++;
        stack->s[stack->top]=element;
    }
}

struct Node * pop(struct Stack *stack) {
    struct Node *x=NULL;
    if(stack->top==-1) {
        printf("Stack Empty");

    }
    else {
        x=stack->s[stack->top];
        stack->top--;
        return x;
    }

}

struct Node * stack_top(struct Stack *stack) {
    if(stack->top==-1)
        return -1;
    else
        return stack->s[stack->top];
}


int isEmpty(struct Stack stack) {
    if(stack.top==-1)
        return 1;
    else
        return 0;
}

#endif // STACK_H_INCLUDED
