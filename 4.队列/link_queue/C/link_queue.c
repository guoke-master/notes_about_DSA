#include <stdio.h>
#include <stdlib.h>
#include "link_list.h"
#include "link_queue.h"

// 使用链表时构建的结构体
typedef struct TAG_LINK_QUEUE
{
	LINK_LIST_NODE node;
	LINK_QUEUE_NODE* item;
}TAG_LINK_QUEUE;


/* 创建队列 */
// 相当于创建链表
// O(1)
LINK_QUEUE* LinkQueue_Create()
{
	LINK_LIST* link_list = NULL;

	// 创建一个链表
	link_list = LinkList_Create();		// O(1)
	if (link_list == NULL)
	{
		printf("func LinkQueue_Create() err: link_list == NULL\n");
		return NULL;
	}
	return (LINK_QUEUE*)link_list;
}


/* 销毁队列 */
// 相当于销毁链表
// O(n)
void LinkQueue_Destroy(LINK_QUEUE* queue)
{
	LINK_LIST* link_list = NULL;

	// 输入检查
	if (queue == NULL)
	{
		printf("func LinkQueue_Destroy() err: queue == NULL\n");
		return;
	}

	// 将LINK_QUEUE类型的地址转换为LINK_LIST的地址
	link_list = (LINK_LIST*)queue;

	// 清空队列
	// O(n)
	LinkQueue_Clear(queue);

	// 销毁链表
	// O(1)
	LinkList_Destroy(link_list);
}


/* 清空队列 */
// 相当于清空链表
// O(n)
void LinkQueue_Clear(LINK_QUEUE* queue)
{
	LINK_LIST* link_list = NULL;
	TAG_LINK_QUEUE* tmp_node = NULL;

	// 检查输入
	if (queue == NULL)
	{
		printf("func LinkQueue_Clear() err: queue == NULL\n");
		return;
	}

	// 将LINK_QUEUE类型的地址转换为LINK_LIST的地址
	link_list = (LINK_LIST*)queue;

	// 逐个删除并释放每个节点空间
	// O(n)
	while (LinkQueue_Length(link_list) > 0)
	{
		tmp_node = (TAG_LINK_QUEUE*)LinkList_Delete(link_list, 0);
		if (tmp_node == NULL)
		{
			printf("func LinkQueue_Clear() err: tmp_node == NULL\n");
			return;
		}

		free(tmp_node);
		tmp_node = NULL;
	}
}


/* 入队列 */
// 相当于向线性表的尾部添加元素
// O(n)
void LinkQueue_Append(LINK_QUEUE* queue, LINK_QUEUE_NODE* item)
{
	LINK_LIST* link_list = NULL;
	int insert_pos = 0;
	TAG_LINK_QUEUE* insert_node = NULL;

	// 输入检查
	if (queue == NULL || item == NULL)
	{
		printf("func LinkQueue_Append() err: queue == NULL || item == NULL\n");
		return;
	}

	// 将LINK_QUEUE类型的地址转换为LINK_LIST的地址
	link_list = (LINK_LIST*)queue;

	// 构造链表节点
	insert_node = (TAG_LINK_QUEUE*)malloc(sizeof(TAG_LINK_QUEUE));
	if (insert_node == NULL)
	{
		printf("func LinkQueue_Append() err: insert_node == NULL\n");
		return;
	}
	insert_node->node.next = NULL;
	insert_node->item = item;

	// 向链表尾部添加元素
	insert_pos = LinkList_Insert(link_list, (LINK_LIST_NODE*)insert_node, LinkList_Length(link_list));		// O(n)
	if (insert_pos < 0)
	{
		printf("func LinkQueue_Append() err: insert_pos < 0\n");
		return;
	}
}


/* 出队列 */
// 相当于删除链表0号节点
// O(1)
LINK_QUEUE_NODE* LinkQueue_Retrieve(LINK_QUEUE* queue)
{
	LINK_LIST* link_list = NULL;
	TAG_LINK_QUEUE* deleted_node = NULL;
	LINK_QUEUE_NODE* ret_item = NULL;

	
	// 输入检查
	if (queue == NULL)
	{
		printf("func LinkQueue_Retrieve() err: queue == NULL\n");
		return NULL;
	}

	// 将LINK_QUEUE类型的地址转换为LINK_LIST的地址
	link_list = (LINK_LIST*)queue;

	// 删除链表0号节点
	deleted_node = (TAG_LINK_QUEUE*)LinkList_Delete(link_list, 0);		// O(1)
	if (deleted_node == NULL)
	{
		printf("func LinkQueue_Retrieve() err: deleted_node == NULL\n");
		return NULL;
	}
	ret_item = deleted_node->item;

	// 释放链表节点空间
	free(deleted_node);
	deleted_node = NULL;

	return ret_item;
}


/* 获取队列顶部元素 */
// 相当于获取链表0号元素
// O(1)
LINK_QUEUE_NODE* LinkQueue_Header(LINK_QUEUE* queue)
{
	LINK_LIST* link_list = NULL;
	TAG_LINK_QUEUE* link_list_node = NULL;

	// 输入检查
	if (queue == NULL)
	{
		printf("func LinkQueue_Header() err: queue == NULL\n");
		return NULL;
	}

	// 将LINK_QUEUE类型的地址转换为LINK_LIST的地址
	link_list = (LINK_LIST*)queue;

	// 获取链表0号元素
	link_list_node = (TAG_LINK_QUEUE*)LinkList_Get(link_list, 0);		// 平均复杂度O(n)，获取0号元素复杂度O(1)
	if (link_list_node == NULL)
	{
		printf("func LinkQueue_Header() err: link_list_node == NULL\n");
		return NULL;
	}

	return link_list_node->item;
}


/* 获取队列中元素的个数 */
// 相当于获取链表元素个数
// O(1)
int LinkQueue_Length(LINK_QUEUE* queue)
{
	LINK_LIST* link_list = NULL;
	int list_length = 0;

	// 输入检查
	if (queue == NULL)
	{
		printf("func LinkQueue_Length() err: queue == NULL\n");
		return -1;
	}

	// 将LINK_QUEUE类型的地址转换为LINK_LIST的地址
	link_list = (LINK_LIST*)queue;

	// 获取链表长度
	list_length = LinkList_Length(link_list);		// O(1)
	if (list_length < 0)
	{
		printf("func LinkQueue_Length() err: list_length < 0\n");
		return -2;
	}

	return list_length;
}
