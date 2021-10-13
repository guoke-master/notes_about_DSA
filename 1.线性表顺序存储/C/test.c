#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "seq_list.h"

/* 老师结构体 */
typedef struct TEACHER
{
	int age;
	char name[64];
}TEACHER;

/* 打印老师结构体信息函数 */
void PrintTeacher(TEACHER *t)
{
	printf("name = %s, age = %d",t->name, t->age);
}

int main(void)
{
	SEQ_LIST* teacher_list = NULL, *int_list = NULL;		// 线性表实体
	int teacher_list_capacity = 0, int_list_capacity = 0;
	int teacher_list_length = 0, int_list_length = 0;
	int teacher_list_insert_pos = 0, int_list_insert_pos = 0;
	int i = 0;

	int a = 4, b = 23, c = 45, d = 100;
	
	TEACHER t1, t2, t3, *t;
	t1.age = 31;
	strcpy(t1.name,"张三");
	t2.age = 32;
	strcpy(t2.name,"李四");
	t3.age = 33;
	strcpy(t3.name,"王五");

	/*********************** TEACHER类型的顺序线性表 *********************/
	teacher_list = SeqList_Create(10);
	if (teacher_list == NULL)
	{
		printf("func main() err: teacher_list == NULL\n");
		return -1;
	}

	teacher_list_insert_pos = SeqList_Insert(teacher_list, (SEQ_LIST_NODE*)(&t1), 0);		// 头插法插入元素（省略执行结果检查）
	teacher_list_insert_pos = SeqList_Insert(teacher_list, (SEQ_LIST_NODE*)(&t2), 0);		// 头插法插入元素
	teacher_list_insert_pos = SeqList_Insert(teacher_list, (SEQ_LIST_NODE*)(&t3), 0);		// 头插法插入元素
	
	/* 获取teacher线性表中容量 */
	teacher_list_capacity = SeqList_Capacity(teacher_list);					// 省略执行结果检查
	printf("teacher_list_capacity = %d\n",teacher_list_capacity);

	/* 获取teacher线性表中元素个数 */
	teacher_list_length = SeqList_Length(teacher_list);
	printf("teacher_list_length = %d\n",teacher_list_length);

	for (i = 0; i < teacher_list_length; i++)
	{
		t = SeqList_Get(teacher_list, 0);		// 获取元素（省略执行结果检查）
		printf("获取元素：");
		PrintTeacher(t);
		printf("\n");

		t = SeqList_Delete(teacher_list, 0);	// 删除元素（省略执行结果检查）
		printf("删除元素：");
		PrintTeacher(t);
		printf("\n");
	}

	SeqList_Destroy(teacher_list);				// 销毁线性表


	/*********************** int类型的顺序线性表 *********************/
	int_list = SeqList_Create(20);
	if (int_list == NULL)
	{
		printf("func main() err: int_list == NULL\n");
		return -1;
	}

	int_list_insert_pos = SeqList_Insert(int_list, (SEQ_LIST_NODE*)(&a), 0);	// 头插法
	int_list_insert_pos = SeqList_Insert(int_list, (SEQ_LIST_NODE*)(&b), 0);	// 头插法
	int_list_insert_pos = SeqList_Insert(int_list, (SEQ_LIST_NODE*)(&c), 0);	// 头插法
	int_list_insert_pos = SeqList_Insert(int_list, (SEQ_LIST_NODE*)(&d), 0);	// 头插法

	int_list_capacity = SeqList_Capacity(int_list);	//获取线性表容量
	printf("int_list_capacity = %d\n", int_list_capacity);
	int_list_length = SeqList_Length(int_list);		//获取线性表元素个数
	printf("int_list_length = %d\n", int_list_length);

	for (i = 0; i < int_list_length; ++i)
	{
		printf("获取元素：%d\n", *(int*)(SeqList_Get(int_list, 0)));
		printf("删除元素：%d\n", *(int*)(SeqList_Delete(int_list, 0)));
	}

	SeqList_Destroy(int_list);
	

	
	printf("Hello world!\n");

	return 0;
}
