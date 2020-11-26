#include <iostream>
using namespace std;

//union是一种节省空间的特殊的类
//默认访问控制为public
//可以有析构函数和构造函数
//由于联合里面的成员共享内存，因此不能含有静态、引用类型成员
//联合里面不能有带有构造、析构、拷贝构造函数的类，因为他们共享内存，编译器无法保证这些对象不被破坏，也无法保证离开时正确调用析构函数
//不能包含类
//不能继承与被继承
//不能含有虚函数
//无名union在定义所在的作用域可以直接访问union成员
//无名联合不可以包含protected成员或者private成员
//全局无名联合必须是静态static的，否则就必须放在匿名名字空间中
//无名联合不使用点运算符，所以包含在无名联合内的数据必须是数据，而不允许成员函数，也不能包含私有、保护的成员

union UnionTest
{
	//默认public
	int i;
	UnionTest() :i(10) { print(i); };
	~UnionTest() {};
private:
	void print(int i) { cout << i << endl; };
};

//全局无名联合，必须是static
//编译器:namespace-scope anonymous aggregates（集合） must be static
static union
{
	int i;
	double d;
};

int main()
{
	UnionTest ut;

	//局部无名联合
	union
	{
		//具有main函数的作用域，不能冲突
		int i;
		double d;
	};

	cout << ut.i << endl;

	//全局无名联合
	::i = 20;
	cout << ::i << endl;

	//局部无名联合
	i = 30;
	cout << i << endl;

	system("pause");
	return 0;
}