#ifndef _CIRCULAR_LIST_H_
#define _CIRCULAR_LIST_H_

#ifdef __cplusplus
extern "C"{
#endif


typedef void CIRCULAR_LIST;					// 循环链表类型
typedef struct CIRCULAR_LIST_NODE			// 循环链表节点类型
{
	struct CIRCULAR_LIST_NODE* next;
}CIRCULAR_LIST_NODE;


/* 创建循环链表，返回循环链表的地址 */
CIRCULAR_LIST* CircularList_Create();

/* 销毁循环链表的空间 */
void CircularList_Destroy(CIRCULAR_LIST* list);


/* 清空循环链表的元素 */
void CircularList_Clear(CIRCULAR_LIST* list);


/* 获取循环链表中元素的个数 */
int CircularList_Length(CIRCULAR_LIST* list);


/* 获取循环链表中下标为pos的元素的地址 */
CIRCULAR_LIST_NODE* CircularList_Get(CIRCULAR_LIST* list, int pos);


/* 在下标为pos的位置插入元素node，返回实际插入的位置 */
int CircularList_Insert(CIRCULAR_LIST* list, CIRCULAR_LIST_NODE* node, int pos);


/* 删除循环链表中下标为pos的节点 */
CIRCULAR_LIST_NODE* CircularList_Delete(CIRCULAR_LIST* list, int pos);


/* 删除循环链表中的节点node */
CIRCULAR_LIST_NODE* CircularList_DeleteNode(CIRCULAR_LIST* list, CIRCULAR_LIST_NODE* node);


/* 重置游标 */
CIRCULAR_LIST_NODE* CircularList_ResetSlider(CIRCULAR_LIST* list);


/* 获取当前游标指向的节点 */
CIRCULAR_LIST_NODE* CircularList_Current(CIRCULAR_LIST* list);


/* 返回当前游标指向的节点，并且游标向前移动一步 */
CIRCULAR_LIST_NODE* CircularList_SliderNext(CIRCULAR_LIST* list);

#ifdef __cplusplus
}
#endif

#endif
