#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "seq_stack.h"

#define CAPACITY 100

int main(void)
{
	int i = 0;
	SEQ_STACK* stack = NULL;
	int* item = NULL;
	int stack_size = 0, stack_capacity = 0;
	int* top = NULL;

	// 设置一个随机数种子
	srand((unsigned int)time(NULL));

	// 创建一个栈
	stack = SeqStack_Create(CAPACITY);
	if (stack == NULL)
	{
		printf("func main() err: stack == NULL\n");
		return -1;
	}

	// 入栈
	printf("入栈开始：\n");
	for (i = 0; i < 5; ++i)
	{
		item = (int*)malloc(sizeof(int));
		*item = rand() % 100;
		SeqStack_Push(stack, (SEQ_STACK_NODE*)item);
		stack_size = SeqStack_Size(stack);
		stack_capacity = SeqStack_Capacity(stack);
		top = (int*)SeqStack_Top(stack);

		printf("capacity = %d\tsize = %d\tstack top = %d\n", stack_capacity, stack_size, *top);
	}

	// 出栈
	printf("\n出栈开始:\n");
	while(SeqStack_Size(stack) > 0)
	{
		top = (int*)SeqStack_Pop(stack);
		stack_size = SeqStack_Size(stack);
		stack_capacity = SeqStack_Capacity(stack);
		printf("出栈：%d\tcapacity = %d\tsize = %d\n", *top, stack_capacity, stack_size);
		if (top != NULL)
		{
			free(top);
			top = NULL;
		}
	}

	// 释放栈空间
	SeqStack_Destroy(stack);	

	printf("Hello world!\n");
	return 0;
}
