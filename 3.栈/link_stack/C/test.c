#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "link_stack.h"

// 老师节点
typedef struct TEACHER
{
	int age;
	char name[32];
}TEACHER;


int main(void)
{
	LINK_STACK* link_stack = NULL;
	int size = 0;
	TEACHER t1, t2, t3;
	TEACHER* tmp = NULL;

	// 构造节点，注意声明周期声明者掌控
	t1.age = 23;
	strcpy(t1.name, "张三");
	t2.age = 24;
	strcpy(t2.name, "李四");
	t3.age = 25;
	strcpy(t3.name, "王五");

	// 创建栈
	printf("创建栈\n");
	link_stack = LinkStack_Create();
	if (link_stack == NULL)
	{
		printf("func main() err: link_stack == NULL\n");
		return -1;
	}

	// 入栈
	printf("入栈\n");
	LinkStack_Push(link_stack, (LINK_STACK_NODE*)&t1);
	LinkStack_Push(link_stack, (LINK_STACK_NODE*)&t2);
	LinkStack_Push(link_stack, (LINK_STACK_NODE*)&t3);
	
	// 获取栈元素个数
	size = LinkStack_Size(link_stack);

	// 出栈
	printf("出栈\n");
	size = LinkStack_Size(link_stack);
	while (size > 0)
	{
		printf("size = %d\t", size);
		tmp = (TEACHER*)LinkStack_Top(link_stack);
		if (tmp == NULL)
		{
			printf("func main() err: tmp == NULL\n");
			return -2;
		}
		printf("age = %d\t",tmp->age);
		printf("name = %s\n",tmp->name);
		LinkStack_Pop(link_stack);
		size = LinkStack_Size(link_stack);
	}
		
	// 销毁栈
	printf("销毁栈\n");
	LinkStack_Destroy(link_stack);

	printf("Hello world!\n");
	return 0;
}

