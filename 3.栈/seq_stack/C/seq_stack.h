#ifndef _SEQ_STACK_H_
#define _SEQ_STACK_H_

#ifdef __cplusplus
extern "C"{
#endif

// 对外的栈的类型
typedef void SEQ_STACK;
// 对外栈元素的类型
typedef void SEQ_STACK_NODE;

// 接口函数

/* 创建栈 */
SEQ_STACK* SeqStack_Create(int capacity);

/* 销毁栈 */
void SeqStack_Destroy(SEQ_STACK* stack);

/* 清空栈 */
void SeqStack_Clear(SEQ_STACK* stack);

/* 压栈 */
void SeqStack_Push(SEQ_STACK* stack, SEQ_STACK_NODE* item);

/* 出栈 */
SEQ_STACK_NODE* SeqStack_Pop(SEQ_STACK* stack);

/* 获取栈顶元素 */
SEQ_STACK_NODE* SeqStack_Top(SEQ_STACK* stack);

/* 获取栈元素个数 */
int SeqStack_Size(SEQ_STACK* stack);

/* 获取栈容量 */
int SeqStack_Capacity(SEQ_STACK* stack);



#ifdef __cplusplus
}
#endif

#endif
