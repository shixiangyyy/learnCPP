//通常类成员函数都会被编译器考虑是否进行内联
//但是通过基类指针或则和引用调用的虚函数必定不能被内联
//当然，实体对象调用虚函数或者静态调用时可以被内联，虚析构函数的静态调用也一定会被内联展开
#include <iostream>
using namespace std;

class Base
{
public:
	inline virtual void who()
	{
		cout << "I'm Base.\n";
	}
	virtual ~Base() {};
};

class Derived :public Base
{
public:
	inline void who()//不写inline时隐式内联
	{
		cout << "I'm Derived.\n";
	}
};

int main()
{
	//最终是否内联取决于编译器
	//此处通过对象调用虚函数，需要注意的是这里的调用解析于编译时，因此可以使用内联
	Base b;
	b.who();//通过具体对象调用虚函数

					//此处通过指针调用虚函数，属于运行时多态，编译器无法确定使用哪个函数，所以不能内联
	Base* bptr = new Derived();
	bptr->who();
	delete bptr;//先派生类析构函数，再基类析构函数

	system("pause");
	return 0;
}