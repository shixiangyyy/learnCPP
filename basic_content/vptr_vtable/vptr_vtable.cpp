#include <iostream>
#include <stdio.h>
using namespace std;

//函数指针
typedef void(*Fun)();

class Base
{
public:
	Base() {};
	virtual void fun1()
	{
		cout << "Base::fun1()" << endl;
	};
	virtual void fun2()
	{
		cout << "Base::fun2()" << endl;
	}
	virtual void fun3() {};
	virtual ~Base() {};
};

class Derived :public Base
{
public:
	Derived() {};
	void fun1()
	{
		cout << "Derived::fun1()" << endl;
	};
	void fun2()
	{
		cout << "Derived::fun2()" << endl;
	};
	virtual ~Derived() {};
};

//获取vptr地址与func地址，vptr指向一块内存，存放的是虚函数的地址，也就是vtable
Fun getAddr(void* obj, unsigned int offset)
{
	cout << "===================" << endl;
	//手动取出obj对象前8个字节，前八个字节在64系统内就是vptr指针的地址
	//要取出前8个字节，需要将obj指针转为8字节数据的unsigned long long, unsigned long四个字节
	void* vptr_addr = (void*)*(unsigned long long*)obj; //这里解析有问题
	cout << "vptr address: " << vptr_addr << endl;
	//再通过vptr指针访问vtable，因为vptr指向vtable首地址，因此加上偏移量就是单个函数的地址
	void* func_addr = (void*)*((unsigned long long*)vptr_addr + offset); //注意表述
	cout << "func address: " << func_addr << endl;
	return (Fun)(func_addr);
}

int main()
{
	Base bobj;
	Derived dobj;
	Base* bptr = new Derived();
	Base& brefb = bobj; //基类引用指向基类对象
	Base& brefd = dobj; //基类引用指向派生类对象

	cout << "基类对象直接调用：" << endl;
	bobj.fun1();
	cout << "基类引用调用基类实例：" << endl;
	brefb.fun1();
	cout << "基类指针指向派生类实例并调用虚函数：" << endl;
	bptr->fun1();
	cout << "基类引用指向派生类对象并调用虚函数：" << endl;
	brefd.fun1();

	//手动方式查找vptr和vtable
	Fun f1 = getAddr(bptr, 0); //f1是函数指针
	(*f1)();
	Fun f2 = getAddr(bptr, 1); 
	(*f2)();
	delete bptr;

	system("pause");
	return 0;
}