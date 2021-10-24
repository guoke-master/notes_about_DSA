#ifndef _SEQ_LIST_H_
#define _SEQ_LIST_H_

template <typename T>
class SEQ_LIST
{
private:
	int length;
	int capacity;
	T* space;

public:
	SEQ_LIST(int capacity);
	SEQ_LIST(const SEQ_LIST& seq_list);
	~SEQ_LIST(void);

public:
	// 获取线性表长度
	int GetLength();

	// 获取线性表容量
	int GetCapacity();

	// 插入元素
	int Insert(const T& item, int pos);

	// 获取某个位置的元素
	int GetNode(int pos, T& out);

	// 删除某个位置的元素
	int DeleteNode(int pos, T& out);

	// 清空链表
	int Clear();
};

#endif
