#include <iostream>
using namespace std;

//注意字节对齐
//普通单继承，继承就是基类+派生类自身的大小
//虚单继承，派生类继承基类vptr

class A
{
public:
	char a;
	int b;
};

//此时B按照顺序：
//char a
//int b
//short a
//long b
//根据字节对齐规则4+4+8+8=24//但是实际结果并不是这样的
//类的数据成员按照声明顺序加入内存，与访问权限无关，只看声明顺序
class B :public A
{
public:
	short a;
	long b;
};

class C
{
	A a;
	char c;
};

class A1
{
	virtual void fun(){}
};

class C1 :public A1
{

};

int main()
{
	cout << "A: " << sizeof(A) << endl; //8
	cout << "B: " << sizeof(B) << endl; //24？16？应该时16，因为是64位系统
	cout << "C: " << sizeof(C) << endl; //12
	cout << "A1: " << sizeof(A1) << endl; //8
	cout << "C1: " << sizeof(C1) << endl; //8
	//X86: 8 16 12 4 4
	//X64: 8 16 12 8 8 
	system("pause");
	return 0;
}