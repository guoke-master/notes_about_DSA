#ifndef _LINK_LIST_H_
#define _LINK_LIST_H_

/* 节点类 */
template <typename T>
class NODE
{
public:
	T data;
	NODE<T>* next;

public:
	NODE();
	NODE(const T& data);
	NODE(const NODE& n);
};


/* 链表类 */
template <typename T>
class LINK_LIST
{
private:
	int length;
	NODE<T>* header;

public:
	LINK_LIST();
	LINK_LIST(const LINK_LIST& list);
	~LINK_LIST();

public:
	/* 清空链表 */
	int Clear();

	/* 获取链表长度 */
	int GetLength();

	/* 插入数据节点 */
	int Insert(const T& in_data, int pos);

	/* 获取某一位置的节点 */
	int GetNode(int pos, T& out_data);

	/* 删除节点 */
	int DeleteNode(int pos, T& out_data);
};

#endif
