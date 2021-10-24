#include <iostream>
#include "seq_list.h"

using namespace std;

// 构造函数
template <typename T>
SEQ_LIST<T>::SEQ_LIST(int capacity)
{
	// 输入检查
	if (capacity <= 0)
	{
		cout << "constructor SEQ_LIST() err: capacity <= 0" << endl;
		return;
	}
	
	// 初始化参数
	this->capacity = capacity;
	this->length = 0;

	// 分配空间
	space = NULL;
	space = new T[capacity];
	if (space == NULL)
	{
		cout << "constructor SEQ_LIST() err: space == NULL" << endl;
		return;
	}
}


// 复制构造函数
template <typename T>
SEQ_LIST<T>::SEQ_LIST(const SEQ_LIST<T>& seq_list)
{
	// 释放旧空间，防止空间泄露
	if (this->space != NULL)
	{
		delete[] this->space;
		this->space = NULL;
	}

	// 申请新空间
	this->space = new T[seq_list->capacity];
	if (this->space == NULL)
	{
		cout << "copy constructor SEQ_LIST() err: space == NULL" << endl;
		return;
	}

	// 复制数据
	this->capacity = seq_list.capacity;
	this->length = seq_list.length;
	memcpy(this->space, seq_list.space, this->capacity * sizeof(T));
}


// 析构函数
template <typename T>
SEQ_LIST<T>::~SEQ_LIST(void)
{
	// 释放空间
	if (space != NULL)
	{
		delete[] space;
		space = NULL;
	}
}


/* 获取线性表长度 */
template <typename T>
int SEQ_LIST<T>::GetLength()
{
	return length;
}


/* 获取线性表容量 */
template <typename T>
int SEQ_LIST<T>::GetCapacity()
{
	return capacity;
}


/* 插入元素 */
template <typename T>
int SEQ_LIST<T>::Insert(const T& item, int pos)
{
	// 参数检查
	if (pos < 0 || pos > length)
	{
		cout << "func Insert() err: pos < 0 || pos > length" << endl;
		return -1;
	}

	// 插入
	for(int i = 0; i < length - pos; ++i)
	{
		space[length - i] = space[length - i - 1];
	}
	space[pos] = item;			// 类型需要支持等号操作

	// 长度+1
	length++;

	return pos;
}


/* 获取某个位置的元素 */
template <typename T>
int SEQ_LIST<T>::GetNode(int pos, T& out)
{
	// 参数检查
	if (pos < 0 || pos >= length)
	{
		cout << "func GetNode() err: pos < 0 || pos >= length" << endl;
		return -1;
	}

	// 获取节点值并返回给输出参数
	out = space[pos];

	return pos;
}


/* 删除某个位置的元素 */
template <typename T>
int SEQ_LIST<T>::DeleteNode(int pos, T& out)
{
	// 参数检查
	if (pos < 0 || pos >= length)
	{
		cout << "func DeleteNode() err: pos < 0 || pos >= length" << endl;
		return -1;
	}

	// 缓存删除节点
	out = space[pos];

	// 删除节点并将其后面的节点前移
	for(int i = 0; i < length - 1 - pos; ++i)
	{
		space[pos + i] = space[pos + i + 1];
	}

	// 长度-1
	length--;

	return pos;
}


/* 清空线性表 */
template <typename T>
int SEQ_LIST<T>::Clear()
{
	this->length = 0;
	return 0;
}
