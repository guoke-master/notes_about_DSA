#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "circular_list.h"


/* 约瑟夫问题：N个人围成一圈，由第一个人从1开始报数，报M的人会被淘汰，然后从后一个人重新开始报数，重复以上过程，求出淘汰的人的顺序 */


/* 业务结构，包含一个节点域和一个整形域 */
typedef struct VALUE
{
	CIRCULAR_LIST_NODE* circular_node;
	int value;
}VALUE;


int main(void)
{
	int i = 0;
	int number_of_people = 16;			// 16个人围成一圈
	int death_number = 3;				// 报数为3的人死亡
	VALUE* v = NULL;
	CIRCULAR_LIST* circular_list = NULL;

	// 创建循环链表
	circular_list = CircularList_Create();
	if (circular_list == NULL)
	{
		printf("func main(): circular_list == NULL\n");
		return -1;
	}

	// 设置随机数种子
	srand((unsigned int)time(NULL));

	// 随机生成16个人的value
	for (i = 0; i < number_of_people; ++i)
	{
		v = (VALUE*)malloc(sizeof(VALUE));
		v->circular_node = NULL;
		v->value = rand()%100;			// 随机生成[0,100)的value值

		// 使用头插法插入循环链表
		CircularList_Insert(circular_list, (CIRCULAR_LIST_NODE*)v, 0);
	}

	// 打印循环链表（人围成的圈的顺序）
	for (i = 0; i < CircularList_Length(circular_list); ++i)
	{
		v = (VALUE*)CircularList_Get(circular_list, i);
		printf("%d ",v->value);
	}
	printf("\n");

	// 重置游标，使其指向第一个节点
	CircularList_ResetSlider(circular_list);

	// 报数，并开始淘汰
	while (CircularList_Length(circular_list) > 0)
	{
		// 报数，开始之后第1个人和第death_number个人中间隔着（death_number - 1）跳
		for (i = 0; i < (death_number - 1); ++i)
		{
			CircularList_SliderNext(circular_list);
		}

		// 此时游标刚好指向淘汰的人，通过游标得到这个人的信息，并将这个人踢出游戏
		v = (VALUE*)CircularList_Current(circular_list);
		CircularList_SliderNext(circular_list);			// 删除之前先将游标移动到下一个开始的位置
		CircularList_DeleteNode(circular_list, (CIRCULAR_LIST_NODE*)v);

		// 处理淘汰的节点：1. 输出； 2. 销毁空间（循环链表的库不负责销毁）
		printf("%d\n",v->value);
		if(v != NULL)
		{
			free(v);
			v = NULL;
		}
	}


	// 销毁循环链表
	CircularList_Destroy(circular_list);

	printf("Hello world!\n");
	return 0;
}
