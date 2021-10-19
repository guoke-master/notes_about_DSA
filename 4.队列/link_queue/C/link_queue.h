#ifndef _LINK_QUEUE_H_
#define _LINK_QUEUE_H_

#ifdef __cplusplus
extern "C"{
#endif

// 对外展示的队列类型
typedef void LINK_QUEUE;
// 对外展示的队列元素类型
typedef void LINK_QUEUE_NODE;

/* 创建队列 */
LINK_QUEUE* LinkQueue_Create();

/* 销毁队列 */
void LinkQueue_Destroy(LINK_QUEUE* queue);

/* 清空队列 */
void LinkQueue_Clear(LINK_QUEUE* queue);

/* 入队列 */
void LinkQueue_Append(LINK_QUEUE* queue, LINK_QUEUE_NODE* item);

/* 出队列 */
LINK_QUEUE_NODE* LinkQueue_Retrieve(LINK_QUEUE* queue);

/* 获取队列顶部元素 */
LINK_QUEUE_NODE* LinkQueue_Header(LINK_QUEUE* queue);

/* 获取队列中元素的个数 */
int LinkQueue_Length(LINK_QUEUE* queue);

#ifdef __cplusplus
}
#endif

#endif
