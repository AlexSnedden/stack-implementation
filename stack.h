/*
 * Just a stack implmentation for fun and learning.
 * No size restriction beyond available memory, and 
 * can hold arbitrary data types.
 */
#include <stdio.h>
#include <stdlib.h>

struct stack_element {
        void *data;
        struct stack_element *prev;
};
struct stack {
        struct stack_element *top;
};
struct stack *new_stack() {
        struct stack *ret = (struct stack*)malloc(sizeof(struct stack));
        ret->top = (struct stack_element*)malloc(sizeof(struct stack_element));
        ret->top->prev = NULL;
        return ret;
};
// returns top element and pops it off stack
void *pop(struct stack *_stack) {
        if(!_stack->top->prev) return NULL;
        void *ret = _stack->top->data;
        free(_stack->top);
        _stack->top = _stack->top->prev;
        return ret;
}
// returns top element but doesn't pop it off stack
void *read(struct stack *_stack) {
        return _stack->top->data;
}
void push(struct stack *_stack, void *data) {
        struct stack_element *new = (struct stack_element*)malloc(sizeof(struct stack_element));
        new->prev = _stack->top;
        new->data = data;
        _stack->top = new;
}
