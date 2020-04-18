#include "stack.h"
#include <limits.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

stack *init_stack(int size, STACK_ERR *err)
{
	if (size <= 0) {
		fprintf(stderr, "Invalig argument: size\n");
		if (err != NULL)
			*err = EINVARG;
		return NULL;
	}

	stack *cstack = (stack *)malloc(sizeof(stack));
	if (cstack == NULL) {
		fprintf(stderr, "Not enough memory\n");
		if (err != NULL)
			*err = EMALLOC;
		return NULL;
	}

	cstack->arr = (int *)malloc(sizeof(int) * size);
	if (cstack->arr == NULL) {
		fprintf(stderr, "Not enough memory\n");
		if (err != NULL)
			*err = EMALLOC;
		return NULL;
	}

	cstack->size = size;
	cstack->current_size = 0;
	*err = ESUCCESS;
	return cstack;
}

void remove_stack(stack *stack, STACK_ERR *err)
{
	if (stack == NULL) {
		fprintf(stderr, "Invalig argument: stack\n");
		if (err != NULL)
			*err = EINVARG;
		return;
	}
	if (stack->arr)
		free(stack->arr);
	free(stack);
	*err = ESUCCESS;
}

int pop(stack *stack, STACK_ERR *err)
{
	if (stack == NULL) {
		fprintf(stderr, "Invalig argument: stack\n");
		if (err != NULL)
			*err = EINVARG;
		return INT_MAX;
	}
	if (stack->current_size == 0) {
		fprintf(stderr, "Stack is empty\n");
		if (err != NULL)
			*err = EEMPTY;
		return INT_MAX;
	}

	*err = ESUCCESS;
	return stack->arr[--stack->current_size];
}

void push(stack *stack, int val, STACK_ERR *err)
{
	if (stack == NULL) {
		fprintf(stderr, "Invalig argument: stack\n");
		if (err != NULL)
			*err = EINVARG;
		return;
	}

	if (stack->current_size == stack->size) {
		fprintf(stderr, "Stack is full\n");
		if (err != NULL)
			*err = EFULL;
		return;
	}

	*err = ESUCCESS;
	stack->arr[stack->current_size++] = val;
}

