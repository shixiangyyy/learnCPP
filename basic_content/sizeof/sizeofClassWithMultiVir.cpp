#include <iostream>
using namespace std;

//对于包含虚函数的类，不管有多少个虚函数，都只有一个虚指针，vptr的大小，64位系统为8个字节

class A
{
	virtual void fun() {};
	virtual void fun1() {};
	virtual void fun2() {};
	virtual void fun3() {};
};

int main()
{
	A a;
	cout << "Size of A class: " << sizeof(A) << endl;
	cout << "Size of A class object: " << sizeof(a) << endl;
	system("pause");
	return 0;
}