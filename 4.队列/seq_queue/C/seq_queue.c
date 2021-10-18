#include <stdio.h>
#include <stdlib.h>
#include "seq_queue.h"
#include "seq_list.h"

/* 创建队列 */
// 相当于创建线性表
// O(1)
SEQ_QUEUE* SeqQueue_Create(int capacity)
{
	SEQ_LIST* seq_list = NULL;
	
	// 输入检查
	if (capacity <= 0)
	{
		printf("func SeqQueue_Create() err: capacity <= 0\n");
		return NULL;
	}

	// 创建一个线性表
	seq_list =SeqList_Create(capacity);		// O(1)
	if (seq_list == NULL)
	{
		printf("func SeqQueue_Create() err: seq_list == NULL\n");
		return NULL;
	}
	return (SEQ_QUEUE*)seq_list;
}


/* 销毁队列 */
// 相当于销毁一个线性表
// O(1)
void SeqQueue_Destroy(SEQ_QUEUE* queue)
{
	SEQ_LIST* seq_list = NULL;

	// 输入检查
	if (queue == NULL)
	{
		printf("func SeqQueue_Destroy() err: queue == NULL\n");
		return;
	}

	// 将SEQ_QUEUE类型的地址转换为SEQ_LIST类型的地址
	seq_list = (SEQ_LIST*)queue;

	// 销毁线性表空间
	SeqList_Destroy(seq_list);		// O(1)
}


/* 清空队列 */
// 相当于清空链表
// O(1)
void SeqQueue_Clear(SEQ_QUEUE* queue)
{
	SEQ_LIST* seq_list = NULL;

	// 输入检查
	if (queue == NULL)
	{
		printf("func SeqQueue_Clear() err: queue == NULL\n");
		return;
	}

	// 将SEQ_QUEUE类型的地址转换为SEQ_LIST类型的地址
	seq_list = (SEQ_LIST*)queue;

	// 清空链表
	SeqList_Clear(seq_list);		// O(1)
}


/* 入队列 */
// 相当于在线性表尾部插入一个元素
// O(1)
void SeqQueue_Append(SEQ_QUEUE* queue, SEQ_QUEUE_NODE* item)
{
	SEQ_LIST* seq_list = NULL;
	int insert_pos = 0;

	// 输入检查
	if (queue == NULL || item == NULL)
	{
		printf("func SeqQueue_Append() err: queue == NULL || item == NULL\n");
		return;
	}

	// 将SEQ_QUEUE类型的地址转换为SEQ_LIST类型的地址
	seq_list = (SEQ_LIST*)queue;
	
	// 在线性表尾部插入一个元素
	insert_pos = SeqList_Insert(seq_list, (SEQ_LIST_NODE*)item, SeqList_Length(seq_list));		// O(1)
	if (insert_pos < 0)
	{
		printf("func SeqQueue_Append() err: insert_pos < 0\n");
		return;
	}
}


/* 出队列 */
// 相当于删除线性表头部元素
// O(n)
SEQ_QUEUE_NODE* SeqQueue_Retrieve(SEQ_QUEUE* queue)
{
	SEQ_LIST* seq_list = NULL;
	SEQ_LIST_NODE* seq_list_node = NULL;

	// 输入检查
	if (queue == NULL)
	{
		printf("func SeqQueue_Retrieve() err: queue == NULL\n");
		return NULL;
	}

	// 将SEQ_QUEUE类型的地址转换为SEQ_LIST类型的地址
	seq_list = (SEQ_LIST*)queue;
	
	// 删除线性表0号元素
	seq_list_node = SeqList_Delete(seq_list, 0);		// O(n)
	if (seq_list_node == NULL)
	{
		printf("func SeqQueue_Retrieve() err: seq_list_node == NULL\n");
		return NULL;
	}
	return (SEQ_QUEUE_NODE*)seq_list_node;
}


/* 获取队列头元素 */
// 相当于获取线性表0号元素
// O(1)
SEQ_QUEUE_NODE* SeqQueue_Header(SEQ_QUEUE* queue)
{
	SEQ_LIST* seq_list = NULL;
	SEQ_LIST_NODE* seq_list_node = NULL;

	// 输入检查
	if (queue == NULL)
	{
		printf("func SeqQueue_Header() err: queue == NULL\n");
		return NULL;
	}

	// 将SEQ_QUEUE类型的地址转换为SEQ_LIST类型的地址
	seq_list = (SEQ_LIST*)queue;

	// 获取线性表0号元素
	seq_list_node = SeqList_Get(seq_list, 0);		// O(1)
	if (seq_list_node == NULL)
	{
		printf("func SeqQueue_Header() err: seq_list_node == NULL\n");
		return NULL;
	}
	
	return (SEQ_QUEUE_NODE*)seq_list_node;
}


/* 获取队列元素个数 */
// 相当于获取线性表元素个数
// O(1)
int SeqQueue_Length(SEQ_QUEUE* queue)
{
	SEQ_LIST* seq_list = NULL;
	int seq_list_length = 0;

	// 输入检查
	if (queue == NULL)
	{
		printf("func SeqQueue_Length() err: queue == NULL\n");
		return -1;
	}
	
	// 将SEQ_QUEUE类型的地址转换为SEQ_LIST类型的地址
	seq_list = (SEQ_LIST*)queue;

	// 获取线性表长度
	seq_list_length = SeqList_Length(seq_list);			// O(1)
	if (seq_list_length < 0)
	{
		printf("func SeqQueue_Length() err: seq_list_length < 0\n");
		return -2;
	}
	
	return seq_list_length;
}


/* 获取队列容量 */
// 相当于获取线性表容量
// O(1)
int SeqQueue_Capacity(SEQ_QUEUE* queue)
{
	SEQ_LIST* seq_list = NULL;
	int seq_list_capacity = 0;

	// 输入检查
	if (queue == NULL)
	{
		printf("func SeqQueue_Capacity() err: queue == NULL\n");
		return -1;
	}

	// 将SEQ_QUEUE类型的地址转换为SEQ_LIST类型的地址
	seq_list = (SEQ_LIST*)queue;
	
	// 获取线性表容量
	seq_list_capacity = SeqList_Capacity(seq_list);			// O(1)
	if (seq_list_capacity < 0)
	{
		printf("func SeqQueue_Capacity() err: seq_list_capacity < 0\n");
		return -2;
	}

	return seq_list_capacity;
}
