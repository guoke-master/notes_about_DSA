#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "link_list.h"

typedef struct TEACHER{
	LINK_LIST_NODE node;	// 老师节点的第一个域，这个域的地址和整个老师节点的地址是一样的
	int age;
	char name[64];
}TEACHER;

int main(void)
{
	int length = 0;
	int ret = 0;
	int i = 0;

	TEACHER t1, t2, t3, t4;
	TEACHER* tmp;
	t1.age = 23;
	strcpy(t1.name, "张三");
	t2.age = 24;
	strcpy(t2.name, "李四");
	t3.age = 25;
	strcpy(t3.name, "王五");
	t4.age = 26;
	strcpy(t4.name, "赵六");

	// 创建一个线性表
	LINK_LIST* list = NULL;
	list = LinkList_Create();
	if(list == NULL)
	{
		printf("func main() err: list == NULL\n");
		return 1;
	}
	
	// 获取线性表长度
	length = LinkList_Length(list);
	printf("插入节点之前链表长度：%d\n",length);

	// 头插法插入节点
	ret = LinkList_Insert(list,(LINK_LIST_NODE*)(&t1),0);
	printf("插入节点：length = %d\n",LinkList_Length(list));
	ret = LinkList_Insert(list,(LINK_LIST_NODE*)(&t2),0);
	printf("插入节点：length = %d\n",LinkList_Length(list));
	ret = LinkList_Insert(list,(LINK_LIST_NODE*)(&t3),0);
	printf("插入节点：length = %d\n",LinkList_Length(list));
	ret = LinkList_Insert(list,(LINK_LIST_NODE*)(&t4),0);
	printf("插入节点：length = %d\n",LinkList_Length(list));

	// 遍历
	for (i = 0; i < LinkList_Length(list); ++i)
	{
		tmp = (TEACHER*)LinkList_Get(list, i);
		printf("第%d个节点：age = %d, name = %s\n", i, tmp->age, tmp->name);
	}

	// 删除节点
	while (LinkList_Length(list) > 0)
	{
		LinkList_Delete(list, 0);
		printf("删除节点：length = %d\n",LinkList_Length(list));
	}
		
	// 销毁线性表空间
	if(list != NULL)
	{
		LinkList_Destroy(list);
		list = NULL;
	}

	printf("Hello world!\n");
	return 0;
}
