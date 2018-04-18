/*
** 处理最多10个不同堆栈的模块接口
** 其中的函数要接受一个参数：需要使用的堆栈的索引
*/

#include <stdlib.h>
#define STACK_TYPE int //堆栈中存的值的类型

void push(size_t stack, STACK_TYPE value);

void pop(size_t stack);

STACK_TYPE top(size_t stack);

int is_empty(size_t stack);

int is_full(size_t stack);
