#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "link_stack.h"
#include "link_list.h"


// 使用链表结构时封装的数据节点
typedef struct TAG_LINK_STACK
{
	LINK_LIST_NODE node;
	LINK_STACK_NODE* item;
}TAG_LINK_STACK;

/* 创建栈 */
// 相当于创建一个链表
// O(1)
LINK_STACK* LinkStack_Create()
{
	LINK_LIST* link_list = NULL;

	// 创建一个链表
	link_list = LinkList_Create();
	if (link_list == NULL)
	{
		printf("func LinkStack_Create() err: link_list == NULL\n");
		return NULL;
	}
	return (LINK_STACK*)link_list;
}


/* 销毁栈 */
// 相当于销毁链表
// O(n)
void LinkStack_Destroy(LINK_STACK* stack)
{
	LINK_LIST* link_list = NULL;

	// 输入检查
	if (stack == NULL)
	{
		printf("func LinkStack_Destroy() err: stack == NULL\n");
		return;
	}
	
	// 将LINK_STACK类型的地址转换为LINK_LIST类型的地址
	link_list = (LINK_LIST*)stack;
	
	// 清空链表
	LinkStack_Clear(stack);

	// 销毁链表
	LinkList_Destroy(link_list);
}


/* 清空栈 */
// 相当于删除链表所有节点
// O(n)
void LinkStack_Clear(LINK_STACK* stack)
{
	LINK_LIST* link_list = NULL;
	TAG_LINK_STACK* deleted_node = NULL;

	// 输入检查
	if (stack == NULL)
	{
		printf("func LinkStack_Clear() err: stack == NULL\n");
		return;
	}

	// 将LINK_STACK类型的地址转换为LINK_LIST类型的地址
	link_list = (LINK_LIST*)stack;

	// 循环弹出元素
	while (LinkList_Length(link_list) > 0)
	{
		// 删除第0个元素
		deleted_node = (TAG_LINK_STACK*)LinkList_Delete(link_list, 0);
		if (deleted_node == NULL)
		{
			printf("func LinkStack_Clear() err: deleted_node == NULL\n");
			return;
		}

		// 销毁节点空间
		free(deleted_node);
	}
}


/* 压栈 */
// 相当于在链表头部插入节点
// O(1)
void LinkStack_Push(LINK_STACK* stack, LINK_STACK_NODE* item)
{
	LINK_LIST* link_list = NULL;
	TAG_LINK_STACK* link_list_node = NULL;
	int ret = 0;

	// 检查输入
	if (stack == NULL || item == NULL)
	{
		printf("func LinkStack_Push() err: stack == NULL || item == NULL\n");
		return;
	}

	// 将LINK_STACK类型的地址转换为LINK_LIST类型的地址
	link_list = (LINK_LIST*)stack;

	// 构造链表的节点
	link_list_node = (TAG_LINK_STACK*)malloc(sizeof(TAG_LINK_STACK));
	if (link_list_node == NULL)
	{
		printf("func LinkStack_Push() err: link_list_node == NULL\n");
		return;
	}
	memset(link_list_node, 0, sizeof(TAG_LINK_STACK));
	link_list_node->item = item;

	// 将构造的节点插入链表头部
	ret = LinkList_Insert(link_list, (LINK_LIST_NODE*)link_list_node, 0);		// 平均复杂度：O(n)	头插法复杂度O(1)
	if (ret != 0)
	{
		printf("func LinkStack_Push() err: ret != 0\n");
		// 释放已经申请的节点空间
		free(link_list_node);
		link_list_node = NULL;
		return;
	}
}


/* 出栈 */
// 相当于删除链表第一个元素
// O(1)
LINK_STACK_NODE* LinkStack_Pop(LINK_STACK* stack)
{
	LINK_LIST* link_list = NULL;
	TAG_LINK_STACK* link_list_node = NULL;
	LINK_STACK_NODE* ret_node = NULL;

	// 检查输入
	if (stack == NULL)
	{
		printf("func LinkStack_Pop() err: stack == NULL\n");
		return NULL;
	}

	// 将LINK_STACK类型的地址转换为LINK_LIST类型的地址
	link_list = (LINK_LIST*)stack;

	// 删除链表第一个元素
	link_list_node = (TAG_LINK_STACK*)LinkList_Delete(link_list, 0);		// 删除平均复杂度O(n),删除头部元素复杂度O(1)
	if (link_list_node == NULL)
	{
		printf("func LinkStack_Pop() err: link_list_node == NULL\n");
		return NULL;
	}

	// 释放节点空间
	ret_node = link_list_node->item;
	free(link_list_node);
	link_list_node = NULL;

	return ret_node;
}


/* 获取栈顶元素 */
// 相当于获取头部节点数据
// O(1)
LINK_STACK_NODE* LinkStack_Top(LINK_STACK* stack)
{
	LINK_LIST* link_list = NULL;
	TAG_LINK_STACK* link_list_node = NULL;

	// 检查输入
	if( stack == NULL)
	{
		printf("func LinkStack_Top() err: stack == NULL\n");
		return NULL;
	}

	// 将LINK_STACK类型的地址转换为LINK_LIST类型的地址
	link_list = (LINK_LIST*)stack;

	// 获取链表头部元素
	link_list_node = (TAG_LINK_STACK*)LinkList_Get(link_list, 0);		// 平均复杂度O(n)，获取头部元素复杂度O(1)
	if (link_list_node == NULL)
	{
		printf("func LinkStack_Top() err: link_list_node == NULL\n");
		return NULL;
	}

	return (LINK_STACK_NODE*)link_list_node->item;
}


/* 获取栈中元素个数 */
// 相当于获取链表元素个数
// O(1)
int LinkStack_Size(LINK_STACK* stack)
{
	LINK_LIST* link_list = NULL;
	int stack_size = 0;

	// 输入检查
	if (stack == NULL)
	{
		printf("func LinkStack_Size() err: stack == NULL\n");
		return -1;
	}

	// 将LINK_STACK类型的地址转换为LINK_LIST类型的地址
	link_list = (LINK_LIST*)stack;

	// 获取链表长度
	stack_size = LinkList_Length(link_list);		// O(1)
	if (stack_size < 0)
	{
		printf("func LinkStack_Size() err: stack_size < 0\n");
		return -2;
	}

	return stack_size;
}
