#ifndef _STACK_H_
#define _STACK_H_

typedef struct stack {
	int size;
	int current_size;
	int *arr;
} stack;

typedef enum {
	ESUCCESS = 0,
	EMALLOC,
	EFULL,
	EEMPTY,
	EINVARG
} STACK_ERR;

stack *init_stack(int size, STACK_ERR *err);

void remove_stack(stack *stack, STACK_ERR *err);

int pop(stack *stack, STACK_ERR *err);

void push(stack *stack, int val, STACK_ERR *err);

#endif	// _STACK_H_
