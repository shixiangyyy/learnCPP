#include <iostream>
using namespace std;

//虚函数是动态绑定的，默认参数是静态绑定的。默认参数的使用看的是指针或者应用本身的类型，而不是对象的类型
class Base
{
public:
	virtual void fun(int x = 10)
	{
		cout << "Base::fun() x = " << x << endl;
	}
};

class Derived :public Base
{
public:
	virtual void fun(int x = 20)
	{
		cout << "Derived:fun() x = " << x << endl;
	}
};

int main()
{
	//虚函数是动态绑定的，但是虚函数的参数的默认参数是静态绑定的
	//看的是指针本身的类型，而不是所指向对象的类型
	Derived d1;
	Base* ptr = &d1;  //Derived:fun() x = 10
	ptr->fun();
	system("pause");
	return 0;
}