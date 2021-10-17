#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "seq_list.h"

/* 用来实现顺序线性表的一个结构体 */
typedef struct TAG_SEQ_LIST
{
	unsigned int	length;			// 顺序线性表的元素个数
	unsigned int	capacity;		// 顺序线性表的容量
	SEQ_LIST_NODE**	node;			// 指向线性表节点的指针
}TAG_SEQ_LIST;


/* 创建顺序线性表，返回顺序线性表的地址 */
// O(1)
SEQ_LIST* SeqList_Create(int capacity)
{
	TAG_SEQ_LIST* seq_list = NULL;		// 线性表指针

	/* 检查输入参数 */
	if (capacity <= 0)
	{
		printf("func SeqList_Create() err: capacity < 0\n");
		return NULL;
	}

	/* 申请结构体空间 */
	seq_list = (TAG_SEQ_LIST*)malloc(sizeof(TAG_SEQ_LIST));
	if (seq_list == NULL)
	{
		printf("func SeqList_Create() err: seq_list == NULL\n");
		return NULL;
	}
	memset(seq_list, 0, sizeof(TAG_SEQ_LIST));		// 给申请的空间赋初值

	/* 根据参数申请线性表空间大小 */
	seq_list->node = (SEQ_LIST_NODE**)malloc(sizeof(SEQ_LIST_NODE*) * capacity);
	if(seq_list->node == NULL)
	{
		printf("func SeqList_Create() err: seq_list->node == NULL\n");
		free(seq_list);
		return NULL;
	}
	memset(seq_list->node, 0, sizeof(SEQ_LIST_NODE*) * capacity);

	/* 根据参数给结构赋值 */
	seq_list->capacity = capacity;
	seq_list->length = 0;
	
	return seq_list;
}


/* 销毁顺序线性表的空间 */
// O(1)
void SeqList_Destroy(SEQ_LIST* list)
{
	TAG_SEQ_LIST* seq_list = NULL;

	/* 检查输入参数 */
	if (list == NULL)
	{
		printf("func SeqList_Destroy() err: list == NULL\n");
		return;
	}

	seq_list = (TAG_SEQ_LIST*)list;			// 将传来的线性表地址强制类型转化为结构体地址

	if(seq_list->node != NULL)
	{
		free(seq_list->node);
		seq_list->node = NULL;
	}

	free(seq_list);
	seq_list = NULL;

	return;
}


/* 清空顺序线性表的元素 */
// O(1)
void SeqList_Clear(SEQ_LIST* list)
{
	TAG_SEQ_LIST* seq_list = NULL;
	
	/* 检查输入参数 */
	if (list == NULL)
	{
		printf("func SeqList_Clear() err: list == NULL\n");
		return ;
	}

	seq_list = (TAG_SEQ_LIST*)list;			// 将传来的线性表地址强制类型转化为结构体地址

	seq_list->length = 0;
	return;
}


/* 获取顺序线性表中元素的个数 */
// O(1)
int SeqList_Length(SEQ_LIST* list)
{
	TAG_SEQ_LIST* seq_list = NULL;
	
	/* 检查输入参数 */
	if (list == NULL)
	{
		printf("func SeqList_Length() err: list == NULL\n");
		return -1;
	}

	seq_list = (TAG_SEQ_LIST*)list;			// 将传来的线性表地址强制类型转化为结构体地址

	return seq_list->length;
}


/* 获取顺序线性表的最大容量 */
// O(1)
int SeqList_Capacity(SEQ_LIST* list)
{
	TAG_SEQ_LIST* seq_list = NULL;
	
	/* 检查输入参数 */
	if (list == NULL)
	{
		printf("func SeqList_Capacity() err: list == NULL\n");
		return -1;
	}

	seq_list = (TAG_SEQ_LIST*)list;			// 将传来的线性表地址强制类型转化为结构体地址
	return seq_list->capacity;
}


/* 在下标为pos的位置插入元素 */
// O(n)
int SeqList_Insert(SEQ_LIST* list, SEQ_LIST_NODE* node, int pos)
{
	TAG_SEQ_LIST* seq_list = NULL;
	int i = 0;
	int ret = 0;		// 错误码
	
	/* 检查输入参数 */
	if (list == NULL || node == NULL || pos < 0)
	{
		ret = -1;
		printf("func SeqList_Insert() err: list == NULL || node == NULL || pos < 0\n");
		return ret;
	}

	seq_list = (TAG_SEQ_LIST*)list;			// 将传来的线性表地址强制类型转化为结构体地址

	/* 判满 */
	if (seq_list->length >= seq_list->capacity)
	{
		ret = -2;
		printf("func SeqList_Insert() err: seq_list->length >= seq_list->capacity\n");
		return ret;
	}

	/* 容错处理：当插入位置大于线性表的length时，不报错而是进行修正，采用尾插法 */
	if (pos > seq_list->length)
	{
		pos = seq_list->length;
	}

	/* 插入点pos位置后面的元素后移 */
	for (i = seq_list->length; i > pos; --i)
	{
		seq_list->node[i] = seq_list->node[i - 1];
	}
	
	/* 插入元素 */
	seq_list->node[pos] = node;
	seq_list->length++;

	return pos;			// 返回实际插入位置
}


/* 获取顺序线性表中下标为pos的元素的地址 */
// O(1)
SEQ_LIST_NODE* SeqList_Get(SEQ_LIST* list, int pos)
{
	TAG_SEQ_LIST* seq_list = NULL;
	
	/* 检查输入参数 */
	if (list == NULL || pos < 0)
	{
		printf("func SeqList_Get() err: list == NULL || pos < 0\n");
		return NULL;
	}

	seq_list = (TAG_SEQ_LIST*)list;			// 将传来的线性表地址强制类型转化为结构体地址
	
	/* 判断位置pos的合法性 */
	if (pos >= seq_list->length)
	{
		printf("func SeqList_Get() err: pos >= seq_list->length\n");
		return NULL;
	}

	return seq_list->node[pos];
}


/* 删除顺序线性表中下标为pos的节点 */
// O(n)
SEQ_LIST_NODE* SeqList_Delete(SEQ_LIST* list, int pos)
{
	TAG_SEQ_LIST* seq_list = NULL;
	SEQ_LIST_NODE* deleted_node = NULL;
	int i = 0;
	
	/* 检查输入参数 */
	if (list == NULL || pos < 0)
	{
		printf("func SeqList_Delete() err: list == NULL || pos < 0\n");
		return NULL;
	}

	seq_list = (TAG_SEQ_LIST*)list;			// 将传来的线性表地址强制类型转化为结构体地址
	
	/* 判空 */
	if (seq_list->length <= 0)
	{
		printf("func SeqList_Delete() err: seq_list->length <= 0\n");
		return NULL;
	}

	/* 判断pos位置的合法性 */
	if (pos >= seq_list->length)
	{
		printf("func SeqList_Delete() err: pos >= seq_list->length\n");
		return NULL;
	}

	/* 缓存pos位置元素 */
	deleted_node = seq_list->node[pos];

	/* pos位置后面的元素前移 */
	for (i = pos + 1; i < seq_list->length; ++i)
	{
		seq_list->node[i - 1] = seq_list->node[i];
	}
	seq_list->length--;

	return deleted_node;
}
