#include <iostream>
using namespace std;

//类的大小与普通数据成员有关，与成员函数或者静态成员无关
//即：普通成员函数、静态成员函数、静态数据成员、静态常量数据成员都不影响类的大小
//虚函数对类大小有关，这是由于虚函数表指针带来的影响
//虚继承对类大小有关，这是因为虚基表指针带来的影响
//空类的大小是一个特殊情况，空类的大小为1

class A
{
public:
	A() {};
	~A() {}; //如果定义为虚函数，则类大小为8
	static int a;
	static void fun3();
	void fun();
	void fun1();// 0， 1， 2个该函数并不影响类大小
};

int main()
{
	cout << sizeof(A) << endl; // 1,析构函数定义为虚函数则为8
	system("pause");
	return 0;
}