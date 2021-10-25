#include <iostream>
#include <string.h>
#include "link_list.cpp"

using namespace std;

// TEACHER类型
class TEACHER
{
private:
	int age;
	char name[32];
public:
	TEACHER(){age = 0;	strcpy(name, "张三");}
	TEACHER(int _age, const char* _name){age = _age;	strcpy(name, _name);}

public:
	void Print(){cout << "age = " << age << "\tname = " << name;}

public:
	// 重载类型的等号操作符
	TEACHER& operator=(const TEACHER& t)
	{
		this->age = t.age;
		strcpy(this->name, t.name);
		return *this;
	}
};


int main(void)
{
	TEACHER t1(23, "张三"), t2(24, "李四"), t3(25, "王五");

	t1.Print();
	cout << endl;
	t2.Print();
	cout << endl;
	t3.Print();
	cout << endl;
	
	// 生成一个线性表对象
	LINK_LIST<TEACHER> link_list;

	// 插入数据
	link_list.Insert(t1, 0);
	cout << "length = " << link_list.GetLength() << endl;
	link_list.Insert(t2, 0);
	cout << "length = " << link_list.GetLength() << endl;
	link_list.Insert(t3, 0);
	cout << "length = " << link_list.GetLength() << endl;

	// 获取并删除数据
	TEACHER tmp;

	while(link_list.GetLength() > 0)
	{
		link_list.GetNode(0, tmp);
		cout << "删除第0号元素：";
		tmp.Print();
		link_list.DeleteNode(0, tmp);
		cout << "\tlength = " << link_list.GetLength() << endl;
	}

	cout<<"Hello world!"<<endl;
	return 0;
}
