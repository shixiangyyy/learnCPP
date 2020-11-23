#include <iostream>
using namespace std;

//类的静态数据存放与编译器构建的全程序的global data member中
//它是类的一个数据成员，但是并不影响类的大小
//不管这个类产生了多少个实例，或者派生了多少新的类，静态数据成员只有一个实例
//静态数据成员，一旦声明，就已经存在
//存在字节对齐原则

class A
{
public:
	char b;
	virtual void fun() {};
	static int c;
	static int d;
	static int e;
};

int A::c = 1;
int A::d = 2;
int A::e = 3;

int main()
{
	cout << "This is a 64bit computer." << endl;
	A* a = new A();
	A f;
	a->b = 'a';
	cout << "A class size: " << sizeof(A) << endl; //16 &X64平台，X86平台为8，考虑字节对齐，所以64位8+8
	cout << "A object pointer a size: " << sizeof(a) << endl; //8 &X64平台，X86平台为4
	cout << "A object f size: " << sizeof(f) << endl;

	delete a;
	cout << A::c << " " << A::d << " " << A::e << endl;

	system("pause");//to check the existence of a
	return 0;
}