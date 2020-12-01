#include <iostream>
using namespace std;

class A
{
public:
	void fun() { cout << "A" << endl; }
};

class B:public A
{
public:
	virtual void fun() { cout << "B\n"; }
};

class C :public B
{
public:
	void fun() { cout << "C\n"; }
};

class D :public C
{
public:
	void fun() { cout << "D\n"; }
};

int main()
{
	A a, *pa;
	B b, *pb;
	C c, *pc;
	D d;

	pa = &b; pa->fun(); //A,此时还不是虚函数
	pb = &c; pb->fun(); //C，从B中开始为虚函数，后续也为虚函数
	pb = &d; pb->fun(); //D，从B中开始为虚函数，后续也为虚函数
	//注意隔代也可以将地址赋值
	pc = &d; pc->fun(); //D，从B中开始为虚函数，后续也为虚函数

	system("pause");
	return 0;
}