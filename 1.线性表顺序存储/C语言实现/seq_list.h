#ifndef _SEQ_LIST_H_
#define _SEQ_LIST_H_

#ifdef __cplusplus
extern "C"{
#endif


typedef void SEQ_LIST;			// 顺序线性表
typedef void SEQ_LIST_NODE;		// 线性表的节点类型

/* 创建顺序线性表，返回顺序线性表的地址 */
SEQ_LIST* SeqList_Create(unsigned int capacity);

/* 销毁顺序线性表的空间 */
void SeqList_Destroy(SEQ_LIST* list);

/* 清空顺序线性表的元素 */
void SeqList_Clear(SEQ_LIST* list);

/* 获取顺序线性表中元素的个数 */
int SeqList_Length(SEQ_LIST* list);

/* 获取顺序线性表的最大容量 */
int SeqList_Capacity(SEQ_LIST* list);

/* 在下标为pos的位置插入元素 */
int SeqList_Insert(SEQ_LIST* list, SEQ_LIST_NODE* node, unsigned int pos);

/* 获取顺序线性表中下标为pos的元素的地址 */
SEQ_LIST_NODE* SeqList_Get(SEQ_LIST* list, unsigned int pos);

/* 删除顺序线性表中下标为pos的节点 */
SEQ_LIST_NODE* SeqList_Delete(SEQ_LIST* list, unsigned int pos);

#ifdef __cplusplus
}
#endif

#endif
