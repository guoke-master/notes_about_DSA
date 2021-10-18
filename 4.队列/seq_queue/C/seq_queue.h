#ifndef _SEQ_QUEUE_H_
#define _SEQ_QUEUE_H_

#ifdef __cplusplus
extern "C"{
#endif

// 对外的队列类型
typedef void SEQ_QUEUE;
// 对外的队列的元素类型
typedef void SEQ_QUEUE_NODE;


/* 创建队列 */
SEQ_QUEUE* SeqQueue_Create(int capacity);

/* 销毁队列 */
void SeqQueue_Destroy(SEQ_QUEUE* queue);

/* 清空队列 */
void SeqQueue_Clear(SEQ_QUEUE* queue);

/* 入队列 */
void SeqQueue_Append(SEQ_QUEUE* queue, SEQ_QUEUE_NODE* item);

/* 出队列 */
SEQ_QUEUE_NODE* SeqQueue_Retrieve(SEQ_QUEUE* queue);

/* 获取队列头元素 */
SEQ_QUEUE_NODE* SeqQueue_Header(SEQ_QUEUE* queue);

/* 获取队列元素个数 */
int SeqQueue_Length(SEQ_QUEUE* queue);

/* 获取队列容量 */
int SeqQueue_Capacity(SEQ_QUEUE* queue);

#ifdef __cplusplus
}
#endif

#endif
