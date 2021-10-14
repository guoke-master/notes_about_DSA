#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "link_list.h"

// 链表内部实现结构体
// 记录链表状态的头结点
typedef struct TAG_LINK_LIST
{
	LINK_LIST_NODE header;		// 指向链表第一个节点指针域的指针
	unsigned int length;		// 链表节点个数
}TAG_LINK_LIST;


/* 创建链式线性表，返回线性表的地址 */
LINK_LIST* LinkList_Create()
{
	TAG_LINK_LIST* list = NULL;

	// 申请头结点空间
	list = (TAG_LINK_LIST*)malloc(sizeof(TAG_LINK_LIST));
	if( list == NULL)
	{
		printf("func LinkList_Create() err: list == NULL\n");
		return NULL;
	}

	// 初始化链表数据
	memset(list, 0, sizeof(TAG_LINK_LIST));	
	// list->header.next = NULL;
	// list->length = 0;
		
	return list;
}


/* 销毁链式线性表的空间 */
void LinkList_Destroy(LINK_LIST* list)
{
	TAG_LINK_LIST* link_list = NULL;

	// 输入检查
	if(list == NULL)
	{
		printf("func LinkList_Destroy() err: list == NULL\n");
		return;
	}

	// 将LINK_LIST类型指针转换为TAG_LINK_LIST类型的指针
	link_list = (TAG_LINK_LIST*)list;	
	
	// 释放空间，防止生成野指针
	if (link_list != NULL)
	{
		free(link_list);
		link_list = NULL;
	}
}


/* 清空链式线性表的元素 */
void LinkList_Clear(LINK_LIST* list)
{
	TAG_LINK_LIST* link_list = NULL;

	// 检查输入
	if (list == NULL)
	{
		printf("func LinkList_Clear() err: list == NULL\n");
		return;
	}

	// 将传进来的地址转换为头结点结构指针类型
	link_list = (TAG_LINK_LIST*)list;
	
	// 清空线性表
	link_list->length = 0;
	link_list->header.next = NULL;
}


/* 获取链式线性表中元素的个数 */
int LinkList_Length(LINK_LIST* list)
{
	TAG_LINK_LIST* link_list = NULL;

	// 检查输入
	if (list == NULL)
	{
		printf("func LinkList_Length() err: list == NULL\n");
		return -1;
	}

	// 将传进来的地址转换为头结点结构指针类型
	link_list = (TAG_LINK_LIST*)list;

	// 返回线性表长度
	return link_list->length;
}


/* 在下标为pos的位置插入元素node */
int LinkList_Insert(LINK_LIST* list, LINK_LIST_NODE* node, int pos)
{
	int i = 0;
	TAG_LINK_LIST* link_list = NULL;
	LINK_LIST_NODE* current_ptr = NULL;

	// 检查输入
	if (list == NULL || node == NULL || pos < 0)
	{
		printf("func LinkList_Insert() err: list == NULL || node == NULL || pos < 0\n");
		return -1;
	}

	// 将传进来的地址转换为头结点结构指针类型
	link_list = (TAG_LINK_LIST*)list;
	current_ptr = (LINK_LIST_NODE*)link_list;
	
	// 容错检查：当pos >= link_list->length时，采用尾插法
	if (pos >= link_list->length)
	{
		pos = link_list->length;
	}
	
	// 辅助指针跳转到下标为pos-1的位置
	for (i = 0; i < pos; ++i)
	{
		current_ptr = current_ptr->next;
	}

	// 将节点插入pos位置
	node->next = current_ptr->next;
	current_ptr->next = node;

	// 节点数加一
	link_list->length++;

	// 返回插入节点的位置
	return pos;
}


/* 获取线性表中下标为pos的元素的地址 */
LINK_LIST_NODE* LinkList_Get(LINK_LIST* list, int pos)
{
	int i = 0;
	TAG_LINK_LIST* link_list = NULL;
	LINK_LIST_NODE* current_ptr = NULL;

	// 检查输入
	if (list == NULL || pos < 0)
	{
		printf("func LinkList_Get() err: list == NULL || pos < 0\n");
		return NULL;
	}

	// 将传进来的地址转换为头结点结构指针类型
	link_list = (TAG_LINK_LIST*)list;
	current_ptr = (LINK_LIST_NODE*)link_list;

	// 判断节点位置是否合理
	if (pos >= link_list->length)
	{
		printf("func LinkList_Get() err: pos >= link_list->length\n");
		return NULL;
	}
	
	// 辅助指针跳转到下标为pos-1的位置
	for (i = 0; i < pos; ++i)
	{
		current_ptr = current_ptr->next;
	}

	return current_ptr->next;
}


/* 删除链式线性表中下标为pos的节点 */
LINK_LIST_NODE* LinkList_Delete(LINK_LIST* list, int pos)
{
	int i = 0;
	TAG_LINK_LIST* link_list = NULL;
	LINK_LIST_NODE* current_ptr = NULL;
	LINK_LIST_NODE* deleted_node = NULL;

	// 检查输入
	if (list == NULL || pos < 0)
	{
		printf("func LinkList_Delete() err: list == NULL || pos < 0\n");
		return NULL;
	}

	// 将传进来的地址转换为头结点结构指针类型
	link_list = (TAG_LINK_LIST*)list;
	current_ptr = (LINK_LIST_NODE*)link_list;

	// 判断节点位置是否合理
	if (pos >= link_list->length)
	{
		printf("func LinkList_Delete() err: pos >= link_list->length\n");
		return NULL;
	}
	
	// 辅助指针跳转到下标为pos-1的位置
	for (i = 0; i < pos; ++i)
	{
		current_ptr = current_ptr->next;
	}

	// 删除借点
	deleted_node = current_ptr->next;
	current_ptr->next = deleted_node->next;

	// 减少节点数
	link_list->length--;
	return deleted_node;
}

