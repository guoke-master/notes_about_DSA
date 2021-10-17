#ifndef _LINK_STACK_H_
#define _LINK_STACK_H_

#ifdef __cplusplus
extern "C"{
#endif

// 对外显示的栈的类型
typedef void LINK_STACK;
// 对外展示的栈的元素的类型
typedef void LINK_STACK_NODE;

// 对外接口
/* 创建栈 */
LINK_STACK* LinkStack_Create();

/* 销毁栈 */
void LinkStack_Destroy(LINK_STACK* stack);

/* 清空栈 */
void LinkStack_Clear(LINK_STACK* stack);

/* 压栈 */
void LinkStack_Push(LINK_STACK* stack, LINK_STACK_NODE* item);

/* 出栈 */
LINK_STACK_NODE* LinkStack_Pop(LINK_STACK* stack);

/* 获取栈顶元素 */
LINK_STACK_NODE* LinkStack_Top(LINK_STACK* stack);

/* 获取栈中元素个数 */
int LinkStack_Size(LINK_STACK* stack);

#ifdef __cplusplus
}
#endif

#endif
