#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "seq_stack.h"
#include "seq_list.h"


/* 创建栈 */
// 相当如创建一个线性表
// O(1)
SEQ_STACK* SeqStack_Create(int capacity)
{
	SEQ_LIST* seq_list = NULL;

	// 输入检查
	if (capacity <= 0)
	{
		printf("func SeqStack_Create() err: capacity <= 0\n");
		return NULL;
	}

	// 栈的本质是线性表，创建线性表
	seq_list = SeqList_Create(capacity);	// O(1)
	if (seq_list == NULL)
	{
		printf("func SeqStack_Create() err: seq_list == NULL\n");
		return NULL;
	}
	return seq_list;
}


/* 销毁栈 */
// 相当于销毁一个线性表
// O(1)
void SeqStack_Destroy(SEQ_STACK* stack)
{
	SEQ_LIST* seq_list = NULL;

	// 检查输入
	if (stack == NULL)
	{
		printf("func SeqStack_Destroy() err: stack == NULL\n");
		return;
	}

	// 将SEQ_STACK类型的地址转变为SEQ_LIST类型的地址
	seq_list = (SEQ_LIST*)stack;

	// 销毁线性表
	SeqList_Destroy(seq_list);		// O(1)
}


/* 清空栈 */
// 相当于清空一个线性表
// O(1)
void SeqStack_Clear(SEQ_STACK* stack)
{
	SEQ_LIST* seq_list = NULL;

	// 检查输入
	if (stack == NULL)
	{
		printf("func SeqStack_Clear() err: stark == NULL\n");
		return;
	}

	// 将SEQ_STACK类型的地址转变为SEQ_LIST类型的地址
	seq_list = (SEQ_LIST*)stack;

	// 清空线性表
	SeqList_Clear(seq_list);	// O(1)
}


/* 压栈 */
// 相当于在线性表尾部插入一个元素
// O(1)
void SeqStack_Push(SEQ_STACK* stack, SEQ_STACK_NODE* item)
{
	SEQ_LIST* seq_list = NULL;
	int insert_pos = 0;

	// 输入检查
	if (stack == NULL || item == NULL)
	{
		printf("func SeqStack_Push() err: stack == NULL || item == NULL\n");
		return ;
	}

	// 将SEQ_STACK类型的地址转变为SEQ_LIST类型的地址
	seq_list = (SEQ_LIST*)stack;

	// 向线性表尾部添加元素
	insert_pos = SeqList_Insert(seq_list, (SEQ_LIST_NODE*)item, SeqList_Length(seq_list));		// 插入平均复杂度是O(n)，向尾部插入复杂度是O(1)
	if (insert_pos < 0)
	{
		printf("func SeqStack_Push() err: insert_pos < 0\n");
		return;
	}
}

/* 出栈 */
// 相当于在线性表尾部删除一个元素
// O(1)
SEQ_STACK_NODE* SeqStack_Pop(SEQ_STACK* stack)
{
	SEQ_LIST* seq_list = NULL;
	SEQ_LIST_NODE* deleted_node = NULL;

	// 输入检查
	if (stack == NULL)
	{
		printf("func SeqStack_Pop() err: stack == NULL\n");
		return NULL;
	}

	// 将SEQ_STACK类型的地址转变为SEQ_LIST类型的地址
	seq_list = (SEQ_LIST*)stack;

	// 删除线性表尾部元素
	deleted_node = SeqList_Delete(seq_list, SeqList_Length(seq_list) - 1);		// 删除平均复杂度是O(n)，删除尾部元素复杂度是O(1)
	if (deleted_node == NULL)
	{
		printf("func SeqStack_Pop() err: deleted_node == NULL\n");
		return NULL;
	}
	
	return (SEQ_STACK_NODE*)deleted_node;
}

/* 获取栈顶元素 */
// 相当于获取线性表尾部元素
// O(1)
SEQ_STACK_NODE* SeqStack_Top(SEQ_STACK* stack)
{
	SEQ_LIST* seq_list = NULL;
	SEQ_LIST_NODE* ret_node = NULL;

	// 输入检查
	if (stack == NULL)
	{
		printf("func SeqStack_Top() err: stack == NULL\n");
		return NULL;
	}

	// 将SEQ_STACK类型的地址转变为SEQ_LIST类型的地址
	seq_list = (SEQ_LIST*)stack;

	// 获取线性表尾部元素
	ret_node = SeqList_Get(seq_list, SeqList_Length(seq_list) - 1);		// O(1)
	if (ret_node == NULL)
	{
		printf("func SeqStack_Top() err: ret_node == NULL\n");
		return NULL;
	}

	return (SEQ_LIST_NODE*)ret_node;
}


/* 获取栈元素个数 */
// 相当于获取线性表元素个数
// O(1)
int SeqStack_Size(SEQ_STACK* stack)
{
	SEQ_LIST* seq_list = NULL;
	int seq_stack_size = 0;

	// 检查输入
	if (stack == NULL)
	{
		printf("func SeqStack_Size() err: stack == NULL\n");
		return -1;
	}

	// 将SEQ_STACK类型的地址转变为SEQ_LIST类型的地址
	seq_list = (SEQ_LIST*)stack;

	// 获取栈元素个数
	seq_stack_size = SeqList_Length(seq_list);		// O(1)
	if (seq_stack_size < 0)
	{
		printf("func SeqStack_Size() err: seq_stack_size < 0\n");
		return -2;
	}

	return seq_stack_size;
}

/* 获取栈容量 */
// 相当于获取线性表容量
// O(1)
int SeqStack_Capacity(SEQ_STACK* stack)
{
	SEQ_LIST* seq_list = NULL;
	int seq_stack_capacity = 0;

	// 检查输入
	if (stack == NULL)
	{
		printf("func SeqStack_Capacity() err: stack == NULL\n");
		return -1;
	}

	// 将SEQ_STACK类型的地址转变为SEQ_LIST类型的地址
	seq_list = (SEQ_LIST*)stack;

	// 获取栈容量
	seq_stack_capacity = SeqList_Capacity(seq_list);		// O(1)
	if (seq_stack_capacity < 0)
	{
		printf("func SeqStack_Capacity() err: seq_stack_capacity < 0\n");
		return -2;
	}

	return seq_stack_capacity;
}
