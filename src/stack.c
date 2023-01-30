#include "stack.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

struct Stack_t {
    int data[STACK_SIZE];
    int top;
};


Stack* createStack() {
    Stack* stack = malloc(sizeof(Stack));
    stack->top = -1;
    return stack;
}

void deleteStack(Stack* stack) {
    assert(stack);
    free(stack);
}

void stack_push(Stack* stack, int value) {
    assert(stack);
    stack->top++;
    stack->data[stack->top] = value;
}

int stack_pop(Stack* stack, int *value) {
    assert(stack);
    if(stack->top < 0) return -1;
    *value = stack->data[stack->top];
    stack->top--;
    return 0;
}

int stack_peek(Stack* stack) {
    assert(stack);
    return stack->data[stack->top];
}

int stack_size(Stack* stack) {
    assert(stack);
    return stack->top + 1;
}

bool stack_isEmpty(Stack* stack) {
    assert(stack);
    return (stack->top<0)?1:0;
}

void stack_display(Stack* stack) {
    assert(stack);
    for(int i=0; i<(stack->top+1); ++i) {
        printf("%d ", stack->data[i]);
    }
    printf("\n");
}