#include "stack.h"
#include <stdio.h>

int main()
{
	stack *stack = NULL;
	STACK_ERR err;

	stack = init_stack(-1, &err);
	if (err != EINVARG)
		fprintf(stdout, "Test_1\t->\tFAILED\n");
	else
		fprintf(stdout, "Test_1\t->\tPASSED\n");

	stack = init_stack(5, &err);
	if (stack == NULL)
		fprintf(stdout, "Test_2\t->\tFAILED\n");
	else
		fprintf(stdout, "Test_2\t->\tPASSED\n");

	push(NULL, 1, &err);
	if (err != EINVARG)
		fprintf(stdout, "Test_3\t->\tFAILED\n");
	else
		fprintf(stdout, "Test_3\t->\tPASSED\n");

	pop(NULL, &err);
	if (err != EINVARG)
		fprintf(stdout, "Test_4\t->\tFAILED\n");
	else
		fprintf(stdout, "Test_4\t->\tPASSED\n");

	pop(stack, &err);
	if (err != EEMPTY)
		fprintf(stdout, "Test_5\t->\tFAILED\n");
	else
		fprintf(stdout, "Test_5\t->\tPASSED\n");

	push(stack, 1, &err);
	if (err != ESUCCESS)
		fprintf(stdout, "Test_6\t->\tFAILED\n");
	else
		fprintf(stdout, "Test_6\t->\tPASSED\n");

	push(stack, 2, &err);
	if (err != ESUCCESS)
		fprintf(stdout, "Test_7\t->\tFAILED\n");
	else
		fprintf(stdout, "Test_7\t->\tPASSED\n");

	push(stack, 3, &err);
	if (err != ESUCCESS)
		fprintf(stdout, "Test_8\t->\tFAILED\n");
	else
		fprintf(stdout, "Test_8\t->\tPASSED\n");

	push(stack, 4, &err);
	if (err != ESUCCESS)
		fprintf(stdout, "Test_9\t->\tFAILED\n");
	else
		fprintf(stdout, "Test_9\t->\tPASSED\n");

	push(stack, 5, &err);
	if (err != ESUCCESS)
		fprintf(stdout, "Test_10\t->\tFAILED\n");
	else
		fprintf(stdout, "Test_10\t->\tPASSED\n");

	push(stack, 6, &err);
	if (err != EFULL)
		fprintf(stdout, "Test_11\t->\tFAILED\n");
	else
		fprintf(stdout, "Test_11\t->\tPASSED\n");

	if (pop(stack, &err) != 5 && err != ESUCCESS)
		fprintf(stdout, "Test_12\t->\tFAILED\n");
	else
		fprintf(stdout, "Test_12\t->\tPASSED\n");

	if (pop(stack, &err) != 4 && err != ESUCCESS)
		fprintf(stdout, "Test_13\t->\tFAILED\n");
	else
		fprintf(stdout, "Test_13\t->\tPASSED\n");

	if (pop(stack, &err) != 3 && err != ESUCCESS)
		fprintf(stdout, "Test_14\t->\tFAILED\n");
	else
		fprintf(stdout, "Test_14\t->\tPASSED\n");

	remove_stack(NULL, &err);
	if (err != EINVARG)
		fprintf(stdout, "Test_15\t->\tFAILED\n");
	else
		fprintf(stdout, "Test_15\t->\tPASSED\n");

	remove_stack(stack, &err);
	if (err != ESUCCESS)
		fprintf(stdout, "Test_16\t->\tFAILED\n");
	else
		fprintf(stdout, "Test_16\t->\tPASSED\n");

	return 0;
}
