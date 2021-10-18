#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "seq_queue.h"

int main(void)
{
	SEQ_QUEUE* seq_queue = NULL;
	int i = 0;
	int* item = NULL;
	int queue_size = 0, queue_capacity = 0;

	// 创建队列
	printf("创建队列：\n");
	seq_queue = SeqQueue_Create(32);
	if (seq_queue == NULL)
	{
		printf("func main() err: seq_queue == NULL\n");
		return -1;
	}

	// 设置随机数种子
	srand((unsigned int)time(NULL));

	// 入队列
	printf("入队列\n");
	for (i = 0; i < 5; ++i)
	{
		// 构造入队列的元素
		item = (int*)malloc(sizeof(int));
		if (item == NULL)
		{
			printf(" func main() err: item == NULL\n");
			return -2;
		}
		*item = rand()%100;

		// 入队列
		SeqQueue_Append(seq_queue, item);
		
		// 读取信息
		queue_size = SeqQueue_Length(seq_queue);
		queue_capacity = SeqQueue_Capacity(seq_queue);

		printf("capacity = %2d\tsize = %2d\titem = %2d\n", queue_capacity, queue_size, *item); 
	}

	// 出队列
	printf("出队列\n");
	item = NULL;
	queue_size = 0;
	queue_capacity = 0;
	while (SeqQueue_Length(seq_queue) > 0)
	{
		// 读取信息
		item = (int*)SeqQueue_Header(seq_queue);
		if (item == NULL)
		{
			printf("func main() err: item == NULL\n");
			return -3;
		}
		
		queue_size = SeqQueue_Length(seq_queue);
		queue_capacity = SeqQueue_Capacity(seq_queue);
		printf("capacity = %2d\tsize = %2d\theader = %2d\n", queue_capacity, queue_size, *item); 

		// 出队列
		item = (int *)SeqQueue_Retrieve(seq_queue);
		if(item == NULL)
		{
			printf("func main() err: item == NULL\n");
			return -4;
		}

		// 销毁申请的空间
		free(item);
		item == NULL;
	}

	// 销毁队列
	SeqQueue_Destroy(seq_queue);

	printf("Hello world!\n");
	return 0;
}
