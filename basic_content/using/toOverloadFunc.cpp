#include <iostream>
using namespace std;

class Base
{
public:
	virtual ~Base(){}
	void func() { cout << "func()" << endl; }
	void func(int n)
	{
		cout << "Base::func(int)" << endl;
	}
};

class Derived1:private Base
{
public:
	virtual ~Derived1(){}
	void func(int n)
	{
		cout << "Derived1::func(int)" << endl;
	}
};

class Derived2:private Base
{
public:
	virtual ~Derived2(){}
	using Base::func;
	void func(int n)
	{
		cout << "Derived2::func(int)" << endl;
	}
};

int main()
{
	Derived1 der1;
	//der1.func();//error，Derived1中重载了func函数，又没有使用using确定其他func的可见性，因此其他func的重载版本不可见
	der1.func(1);
	Derived2 der2;
	der2.func();
	der2.func(1);
	system("pause");
	return 0;
}