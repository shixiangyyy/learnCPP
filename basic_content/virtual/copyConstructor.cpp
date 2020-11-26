#include <iostream>
using namespace std;

//构造函数不可以为虚函数
//尽管虚函数表vtable是编译时创建，但是虚函数表指针vptr是在运行阶段实例化对象才产生的
//而实例化对象需要用到构造函数，而这时候vptr还没创建，因此构造函数不能是虚函数
//之所以使用虚函数，是为了在信息不健全的时候实现程序的多态运行
//如果类含有虚函数，那么编译器会在构造函数中添加代码来创建vptr,而访问vtable需要vptr
class Base
{
public:
};

class Derived :public Base
{
public:
	Derived()
	{
		cout << "Derived created!" << endl;
	}
	//Copy constructor
	Derived(Derived &rhs)
	{
		cout << "Derived created by deep copy!" << endl;
	}
	~Derived()
	{
		cout << "Derived destroyed." << endl;
	}
};

int main()
{
	Derived s1;
	Derived s2 = s1;

	//思考如何通过指向基类的指针进行派生类对象的初始化

	system("pause");
	return 0;
}