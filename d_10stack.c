/*
** 用动态分配数组实现堆栈模块， 使它可以最多处理10个不同的堆栈
*/

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>
#include "d_10stack.h"

#define N_STACKS 10

typedef struct {
	STACK_TYPE *stack; //存储值的数组
	size_t size; //数组大小
	int top_element; //指向栈顶元素
} StackInfo;

StackInfo stacks[N_STACKS]; //实际的堆栈

void create_stack(size_t stk, size_t size) {
	assert(stk < N_STACKS);
	assert(stacks[stk].size == 0);
	stacks[stk].size = size;
	stacks[stk].stack = (STACK_TYPE *)malloc(size * sizeof(STACK_TYPE));
	assert(stacks[stk].stack != NULL);
	stacks[stk].top_element = -1;
}

void destroy_stack(size_t stk) {
	assert(stk < N_STACKS);
	assert(stacks[stk].size > 0);
	stacks[stk].size = 0;
	free(stacks[stk].stack);
	stacks[stk].stack = NULL;
}

void push(size_t stk, STACK_TYPE value) {
	assert(!is_full(stk));
	stacks[stk].top_element += 1;
	stacks[stk].stack[stacks[stk].top_element] = value;
}

void pop(size_t stk) {
	assert(!is_empty(stk));
	stacks[stk].top_element -= 1;
}

STACK_TYPE top(size_t stk) {
	assert(!is_empty(stk));
	return stacks[stk].stack[stacks[stk].top_element];
}

int is_empty(size_t stk) {
	assert(stk < N_STACKS);
	assert(stacks[stk].size > 0);
	return stacks[stk].top_element == -1;
}

int is_full(size_t stk) {
	assert(stk < N_STACKS);
	assert(stacks[stk].size > 0);
	return stacks[stk].top_element == stacks[stk].size - 1;
}
