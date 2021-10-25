#include <iostream>
#include "link_list.h"

using namespace std;


/* NODE构造函数 */
template <typename T>
NODE<T>::NODE(){next = NULL;}


/* NODE构造函数 */
template <typename T>
NODE<T>::NODE(const T& data){this->data = data; next = NULL;}


/* NODE拷贝构造函数 */
template <typename T>
NODE<T>::NODE(const NODE<T>& n)
{
	data = n.data;		// T类型重载的等号操作
	next = n.next;		// 全部拷贝
}

/* 构造函数 */
template <typename T>
LINK_LIST<T>::LINK_LIST()
{
	// 为头结点申请空间并初始化
	header = new NODE<T>;
	if (header == NULL)
	{
		cout << "constructor LINK_LIST() err: header == NULL" << endl;
	}
	header->next = NULL;

	length = 0;
}


/* 复制构造函数 */
template <typename T>
LINK_LIST<T>::LINK_LIST(const LINK_LIST<T>& list)
{
	// 释放旧空间
	if (header != NULL)
	{
		// 释放申请的NODE节点
		NODE<T>* tmp = NULL;
		while (header->next != NULL)
		{
			tmp = header->next;
			header->next = tmp->next;
			delete tmp;
		}
	}

	// 申请新空间并复制数据
	NODE<T>* current_ptr = list.header;
	NODE<T>* tail_ptr = this->header;
	while(current_ptr->next != NULL)
	{
		tail_ptr->next = new NODE<T>(*(current_ptr->next));		// 调用NODE节点的拷贝构造函数
		current_ptr = current_ptr->next;
		tail_ptr = tail_ptr->next;
	}

	this->length = list.length;
}


/* 析构函数 */
template <typename T>
LINK_LIST<T>::~LINK_LIST()
{
	if (header != NULL)
	{
		// 释放申请的NODE节点
		NODE<T>* tmp = NULL;
		while (header->next != NULL)
		{
			tmp = header->next;
			header->next = tmp->next;
			delete tmp;
		}
		
		// 释放头结点
		delete header;
		header = NULL;
	}
}


/* 清空链表 */
template <typename T>
int LINK_LIST<T>::Clear()
{
	// 清空所有节点并释放空间
	NODE<T>* tmp = this->header;
	while (header->next != NULL)
	{
		tmp = header->next;
		header->next = tmp->next;

		// 释放节点空间
		delete tmp;
	}

	// 释放头结点
	if (this->header != NULL)
	{
		delete this->header;
		this->header = NULL;
	}

	return 0;
}


/* 获取链表长度 */
template <typename T>
int LINK_LIST<T>:: GetLength()
{
	return this->length;
}


/* 插入数据节点 */
template <typename T>
int LINK_LIST<T>::Insert(const T& in_data, int pos)
{
	// 检查位置
	if (pos < 0 || pos > length)
	{
		cout << "func Insert() err: pos < 0 || pos > length" << endl;
		return -1;
	}

	// 移动辅助指针到pos-1位置
	NODE<T>* current_ptr = header;
	for(int i = 0; i < pos; ++i)
	{
		current_ptr = current_ptr->next;
	}

	// 申请空间并插入节点
	NODE<T>* insert_node = new NODE<T>(in_data);
	insert_node->next = current_ptr->next;
	current_ptr->next = insert_node;
	
	length++;

	// 返回插入位置
	return pos;
}


/* 获取某一位置节点 */
template <typename T>
int LINK_LIST<T>::GetNode(int pos, T& out_data)
{
	// 参数检查
	if (pos < 0 || pos > length - 1)
	{
		cout << "func LINK_LIST<T>::GetNode() err: pos < 0 || pos > length - 1" << endl;
		return -1;
	}

	// 将辅助指针移动到pos-1的位置
	NODE<T>* current_ptr = this->header;
	for (int i = 0; i < pos; ++i)
	{
		current_ptr = current_ptr->next;
	}

	// 将pos位置的数据传出去
	out_data = current_ptr->next->data;

	return pos;
}


/* 删除节点 */
template <typename T>
int LINK_LIST<T>::DeleteNode(int pos, T& out_data)
{
	// 参数检查
	if (pos < 0 || pos > length - 1)
	{
		cout << "func LINK_LIST<T>::DeleteNode() err: pos < 0 || pos > length -1" << endl;
		return -1;
	}

	// 将辅助指针移动到pos-1的位置
	NODE<T>* current_ptr = this->header;
	for (int i = 0; i < pos; ++i)
	{
		current_ptr = current_ptr->next;
	}
	
	// 缓存即将删除的节点
	NODE<T>* deleted_node = current_ptr->next;

	// 将pos位置的数据传出去
	out_data = deleted_node->data;

	// 删除节点
	current_ptr->next = deleted_node->next;
	this->length--;

	// 释放节点空间
	delete deleted_node;

	return pos;
}
