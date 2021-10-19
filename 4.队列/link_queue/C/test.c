#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "link_queue.h"


int main(void)
{
	LINK_QUEUE* link_queue = NULL;
	int i = 0;
	int* item = NULL;
	int queue_length = 0;

	// 创建队列
	printf("创造队列\n");
	link_queue = LinkQueue_Create();
	if (link_queue == NULL)
	{
		printf("func main() err: link_queue == NULL\n");
		return -1;
	}

	// 设置随机数种子
	srand((unsigned int)time(NULL));

	// 入队列
	printf("入队列\n");
	for (i = 0; i < 5; ++i)
	{
		// 构造节点
		item = (int*)malloc(sizeof(int));
		*item = rand()%100;

		// 入队列
		LinkQueue_Append(link_queue, (LINK_QUEUE_NODE*)item);

		// 打印信息
		queue_length = LinkQueue_Length(link_queue);
		if (queue_length < 0)
		{
			printf("func main() err: queue_length < 0\n");
			return -2;
		}
		printf("length = %2d\titem = %2d\n",queue_length, *item);
	}

	// 出队列
	printf("出队列\n");
	queue_length = LinkQueue_Length(link_queue);
	while (LinkQueue_Length(link_queue) > 0)
	{
		item = (int*)LinkQueue_Header(link_queue);
		if (item == NULL)
		{
			printf("func main() err: item == NULL\n");
			return -3;
		}

		queue_length = LinkQueue_Length(link_queue);
	
		printf("length = %2d\titem = %2d\n",queue_length, *item);
		
		// 出队列
		item = (int*)LinkQueue_Retrieve(link_queue);
		if (item == NULL)
		{
			printf("func main() err: item == NULL\n");
			return -4;
		}

		// 销毁自己申请的空间
		free(item);
		item = NULL;
	}

	// 销毁队列
	LinkQueue_Destroy(link_queue);


	printf("Hello world!\n");
	return 0;
}
