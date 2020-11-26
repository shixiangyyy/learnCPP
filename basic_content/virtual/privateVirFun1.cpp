//虚函数可以被私有化，但是需要注意一些细节：
//基类指针指向继承类对象，则调用的是继承类的函数；
//如果要在main函数里面调用虚函数，而指针又指向基类的话，则需要在基类里面声明main为友元
//或者将基类访问控制设为public，将派生类设置为private或者public也可
#include <iostream>
using namespace std;

class Base
{
public:
	virtual void fun() { cout << "Base virtual function." << endl; }
	//friend int main();//必须将main函数定义为base的友元，不然报错无法访问fun
};

class Derived : public Base
{
public:
	void fun() { cout << "Derived virtual function." << endl; }
};

int main()
{
	Base* ptr = new Derived;
	ptr->fun();//指针指向的是基类，所以调用函数时，虽然时虚函数，但是基类虚函数的private访问控制还是会使得编译器报错

	system("pause");
	return 0;
}