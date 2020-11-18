//使用C语言实现CPP类似多态性
//使用struct封装函数成员，并通过函数指针实现父类子类的函数成员的差异化
#include <stdio.h>

typedef void (*pf)();//定义一个函数指针

typedef struct _A
{
	pf a;
}A;//父类

typedef struct _B
{
	A b;
}B;//子类

void FunA()
{
	printf("%s\n", "Base A::fun()");
}

void FunB()
{
	printf("%s\n", "Derived B::fun()");
}

int main()
{
	A a;
	B b;
	a.a = FunA;
	b.b.a = FunB;

	//类似CPP虚函数实现的通过父类指针调用子类函数
	A *pa = &a;
	pa->a();
	pa = (A*)&b;
	pa->a();
	return 0;
}