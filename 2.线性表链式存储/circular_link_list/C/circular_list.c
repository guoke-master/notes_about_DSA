#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "circular_list.h"


typedef struct TAG_CIRCULAR_LIST
{
	CIRCULAR_LIST_NODE header;
	CIRCULAR_LIST_NODE* slider;
	int length;
}TAG_CIRCULAR_LIST;


/* 创建循环链表，返回循环链表的地址 */
// O(1)
CIRCULAR_LIST* CircularList_Create()
{
	TAG_CIRCULAR_LIST* circular_list = NULL;

	// 申请头节点
	circular_list = (TAG_CIRCULAR_LIST*)malloc(sizeof(TAG_CIRCULAR_LIST));
	if(circular_list == NULL)
	{
		printf("func CircularList_Create() err: circular_list == NULL\n");
		return NULL;
	}

	// 给申请的空间赋一个初值
	memset(circular_list, 0, sizeof(TAG_CIRCULAR_LIST));

	return circular_list;
}


/* 销毁循环链表的空间 */
// O(1)
void CircularList_Destroy(CIRCULAR_LIST* list)
{
	TAG_CIRCULAR_LIST* circular_list = NULL;

	// 检查输入
	if (list == NULL)
	{
		printf("func CircularList_Destroy() err: list == NULL\n");
		return ;
	}

	// 将CIRCULAR_LIST_NODE类型的地址转换为TAG_CIRCULAR_LIST类型的地址
	circular_list = (TAG_CIRCULAR_LIST*)list;

	// 避免野指针
	if (circular_list != NULL)
	{
		free(circular_list);
		circular_list = NULL;
	}
		
	return;
}


/* 清空循环链表的元素 */
// O(1)
void CircularList_Clear(CIRCULAR_LIST* list)
{
	TAG_CIRCULAR_LIST* circular_list = NULL;

	// 检查输入
	if (list == NULL)
	{
		printf("func CircularList_Clear() err: list == NULL\n");
		return;
	}

	// 将CIRCULAR_LIST_NODE类型的地址转换为TAG_CIRCULAR_LIST类型的地址
	circular_list = (TAG_CIRCULAR_LIST*)list;

	// 清空链表
	memset(circular_list, 0, sizeof(TAG_CIRCULAR_LIST));
	
	return;
}


/* 获取循环链表中元素的个数 */
// O(1)
int CircularList_Length(CIRCULAR_LIST* list)
{
	TAG_CIRCULAR_LIST* circular_list = NULL;

	// 检查输入
	if (list == NULL)
	{
		printf("func CircularList_Length() err: list == NULL\n");
		return -1;
	}

	// 将CIRCULAR_LIST_NODE类型的地址转换为TAG_CIRCULAR_LIST类型的地址
	circular_list = (TAG_CIRCULAR_LIST*)list;

	return circular_list->length;
}


/* 获取循环链表中下标为pos的元素的地址 */
// O(n)
CIRCULAR_LIST_NODE* CircularList_Get(CIRCULAR_LIST* list, int pos)
{
	TAG_CIRCULAR_LIST* circular_list = NULL;
	CIRCULAR_LIST_NODE* current_ptr = NULL;
	int i = 0;

	// 检查输入
	if (list == NULL || pos < 0)
	{
		printf("func CircularList_Get() err: list == NULL || pos < 0\n");
		return NULL;
	}

	// 将CIRCULAR_LIST_NODE类型的地址转换为TAG_CIRCULAR_LIST类型的地址
	circular_list = (TAG_CIRCULAR_LIST*)list;
	
	// 检查位置合法性
	if (pos >= circular_list->length)
	{
		printf("func CircularList_Get() err: pos >= circular_list->length\n");
		return NULL;
	}

	// 将辅助指针移动到pos位置前一个位置
	current_ptr = (CIRCULAR_LIST_NODE*)circular_list;
	for (i = 0; i < pos; ++i)
	{
		current_ptr = current_ptr->next;
	}

	// 返回pos位置的地址
	return current_ptr->next;
}


/* 在下标为pos的位置插入元素node，返回实际插入的位置 */
// O(n)
int CircularList_Insert(CIRCULAR_LIST* list, CIRCULAR_LIST_NODE* node, int pos)
{
	TAG_CIRCULAR_LIST* circular_list = NULL;
	CIRCULAR_LIST_NODE* current_ptr = NULL;
	CIRCULAR_LIST_NODE* last_ptr = NULL;
	int i = 0;

	// 检查输入
	if (list == NULL || node == NULL || pos < 0)
	{
		printf("func CircularList_Insert() err: list == NULL || node == NULL || pos < 0\n");
		return -1;
	}

	// 将CIRCULAR_LIST_NODE类型的地址转换为TAG_CIRCULAR_LIST类型的地址
	circular_list = (TAG_CIRCULAR_LIST*)list;

	// 容错检查：当pos >= circular_list->length时，采用尾插法
	if (pos >= circular_list->length)
	{
		pos = circular_list->length;
	}

	// 将辅助指针变量跳转到pos-1位置
	current_ptr = (CIRCULAR_LIST_NODE*)circular_list;
	for (i = 0; i < pos; ++i)
	{
		current_ptr = current_ptr->next;
	}

	// 按照单向链表方式直接插入节点
	node->next = current_ptr->next;
	current_ptr->next = node;
	circular_list->length++;

	// 处理特殊情况
	// 如果此次插入之前循环链表没有节点，需要将链表最后一个节点指向第一个节点
	if (circular_list->length == 1)
	{
		node->next = node;
	}

	// 如果此次插入之前已经有了节点，并且在0号位置插入，正常插入之后最后一个节点指向的节点变成第2个节点，需要修正
	if (circular_list->length != 1 && current_ptr == (CIRCULAR_LIST_NODE*)circular_list)
	{
		// 获取最后一个节点
		last_ptr = (CIRCULAR_LIST_NODE*)circular_list;
		for(i = 0; i < circular_list->length; ++i)
		{
			last_ptr = last_ptr->next;
		}
		// 将最后一个节点指向第一个节点
		last_ptr->next = current_ptr->next;
	}

	return pos;
}


/* 删除循环链表中下标为pos的节点 */
// O(n)
CIRCULAR_LIST_NODE* CircularList_Delete(CIRCULAR_LIST* list, int pos)
{
	TAG_CIRCULAR_LIST* circular_list = NULL;
	CIRCULAR_LIST_NODE* deleted_node = NULL;

	CIRCULAR_LIST_NODE* current_ptr = NULL;
	CIRCULAR_LIST_NODE* last_ptr = NULL;
	int i = 0;

	// 检查输入
	if (list == NULL || pos < 0)
	{
		printf("func CircularList_Delete() err: list == NULL || pos < 0\n");
		return NULL;
	}

	// 将CIRCULAR_LIST_NODE类型的地址转换为TAG_CIRCULAR_LIST类型的地址
	circular_list = (TAG_CIRCULAR_LIST*)list;

	// 检查pos的合法性
	if (pos >= circular_list->length)
	{
		printf("func CircularList_Delete() err: pos >= circular_list->length\n");
		return NULL;
	}

	// 将current_ptr移动到pos-1的位置
	current_ptr = (CIRCULAR_LIST_NODE*)circular_list;
	for (i = 0; i < pos; ++i)
	{
		current_ptr = current_ptr->next;
	}

	// 按照单向链表的方式删除节点
	deleted_node = current_ptr->next;
	current_ptr->next = deleted_node->next;
	circular_list->length--;

	// 处理特殊情况
	// 如果此次删除之后循环链表中将没有节点，那么此次删除之后circular_list->header->next将指向被删除的元素，需要将其置零
	if (circular_list->length == 0)
	{
		current_ptr->next = NULL;
	}

	// 如果此次删除之后循环链表中还有节点，并且这次删除的是第一个节点，那么删除之后，最后一个节点指向的是一个已经删除的节点，需要修正
	if (circular_list->length > 0 && current_ptr == (CIRCULAR_LIST_NODE*)circular_list)
	{
		// 获取最后一个节点
		last_ptr = (CIRCULAR_LIST_NODE*)circular_list;
		for (i = 0; i < circular_list->length; ++i)
		{
			last_ptr = last_ptr->next;
		}

		// 将最后一个节点指向第一个节点
		last_ptr->next = current_ptr->next;
	}	
	return deleted_node;
}


/* 删除循环链表中的节点node */
// O(n)
CIRCULAR_LIST_NODE* CircularList_DeleteNode(CIRCULAR_LIST* list, CIRCULAR_LIST_NODE* node)
{
	TAG_CIRCULAR_LIST* circular_list = NULL;
	int i = 0;
	CIRCULAR_LIST_NODE* current_ptr = NULL;
	CIRCULAR_LIST_NODE* deleted_node = NULL;
	
	// 参数检查
	if (list == NULL || node == NULL)
	{
		printf("func CircularList_DeleteNode() err: list == NULL || node == NULL\n");
		return NULL;
	}

	// 将CIRCULAR_LIST_NODE类型的地址转换为TAG_CIRCULAR_LIST类型的地址
	circular_list = (TAG_CIRCULAR_LIST*)list;

	// 遍历循环链表，找到和node相同的节点就退出循环
	current_ptr = (CIRCULAR_LIST_NODE*)circular_list;
	for(i = 0; i < circular_list->length; ++i)
	{
		current_ptr = current_ptr->next;
		if (current_ptr == node)
		{
			deleted_node = current_ptr;
			break;
		}
	}

	// 如果查找不到node，报错；找到node之后删除
	if (i >= circular_list->length)
	{
		printf("func CircularList_DeleteNode() err: node is not in circular list\n");
		return NULL;
	}
	else if(i < circular_list->length)
	{
		CircularList_Delete(circular_list, i);
	}

	return deleted_node;
}


/* 重置游标，返回重置之后游标指向的节点 */
// O(1)
CIRCULAR_LIST_NODE* CircularList_ResetSlider(CIRCULAR_LIST* list)
{
	TAG_CIRCULAR_LIST* circular_list = NULL;

	// 参数检查
	if (list == NULL)
	{
		printf("func CircularList_ResetSlider() err: list == NULL\n");
		return NULL;
	}

	// 将CIRCULAR_LIST_NODE类型的地址转换为TAG_CIRCULAR_LIST类型的地址
	circular_list = (TAG_CIRCULAR_LIST*)list;

	// 重置slider
	circular_list->slider = circular_list->header.next;

	return circular_list->slider;
}


/* 获取当前游标指向的节点 */
// O(1)
CIRCULAR_LIST_NODE* CircularList_Current(CIRCULAR_LIST* list)
{
	TAG_CIRCULAR_LIST* circular_list = NULL;

	// 参数检查
	if (list == NULL)
	{
		printf("func CircularList_Current() err: list == NULL\n");
		return NULL;
	}

	// 将CIRCULAR_LIST_NODE类型的地址转换为TAG_CIRCULAR_LIST类型的地址
	circular_list = (TAG_CIRCULAR_LIST*)list;
	
	// 返回节点，使用者自己保证游标指向的正确性
	return circular_list->slider;
}


/* 返回当前游标指向的节点，并且游标向前移动一步 */
// O(1)
CIRCULAR_LIST_NODE* CircularList_SliderNext(CIRCULAR_LIST* list)
{
	TAG_CIRCULAR_LIST* circular_list = NULL;
	CIRCULAR_LIST_NODE* current_ptr = NULL;

	// 参数检查
	if (list == NULL)
	{
		printf("func CircularList_SliderNext() err: list == NULL\n");
		return NULL;
	}

	// 将CIRCULAR_LIST_NODE类型的地址转换为TAG_CIRCULAR_LIST类型的地址
	circular_list = (TAG_CIRCULAR_LIST*)list;

	// 记录当前游标位置
	current_ptr = circular_list->slider;

	// 如果循环列表没有节点，报错
	if (circular_list->length == 0)
	{
		printf("func CircularList_SliderNext() err: circular_list->length == 0\n");
		return NULL;
	}
	else
	{
		circular_list->slider = circular_list->slider->next;
	}
	return current_ptr;
}
