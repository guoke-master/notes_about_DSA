#ifndef _LINK_LIST_H_
#define _LINK_LIST_H_

#ifdef __cplusplus
extern "C"{
#endif

typedef void LINK_LIST;				// 链式线性表的类型
typedef struct LINK_LIST_NODE		// 节点类型
{
	struct LINK_LIST_NODE* next;
}LINK_LIST_NODE;

/* 创建链式线性表，返回线性表的地址 */
LINK_LIST* LinkList_Create();

/* 销毁链式线性表的空间 */
void LinkList_Destroy(LINK_LIST* list);

/* 清空链式线性表的元素 */
void LinkList_Clear(LINK_LIST* list);

/* 获取链式线性表中元素的个数 */
int LinkList_Length(LINK_LIST* list);

/* 在下标为pos的位置插入元素node */
int LinkList_Insert(LINK_LIST* list, LINK_LIST_NODE* node, int pos);

/* 获取线性表中下标为pos的元素的地址 */
LINK_LIST_NODE* LinkList_Get(LINK_LIST* list, int pos);

/* 删除链式线性表中下标为pos的节点 */
LINK_LIST_NODE* LinkList_Delete(LINK_LIST* list, int pos);


#ifdef __cplusplus
}
#endif

#endif
