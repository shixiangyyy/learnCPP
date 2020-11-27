#include <iostream>
using namespace std;

//a.在C++的类的成员函数中，允许直接访问该类对象的私有成员变量
//b.在类的成员函数中可以访问同类型实例的私有变量
//c.在拷贝构造函数中，可以直接访问另一个同类对象(引用)的私有成员
//d.类的成员函数可以直接访问作为其参数的同类型对象的私有成员
class Application
{
public:
	static void f(Application a);
	void g(Application a);
private:
	int x;
};

void Application::f(Application a)
{
	//静态成员函数只能直接引用属于该类的静态数据成员或者静态成员函数
	//或者通过具体的对象引用对象的成员
	//cout << x << end; //error，对x的引用是错误的
	cout << a.x << endl; //默认0
}

void Application::g(Application a)
{
	cout << a.x << endl; //对象的私有成员，在该对象所属类的函数中可以引用
}

int main()
{
	Application a;
	//cout << a.x << endl; //此处a对象的x私有成员不能访问，但是在上述f函数的定义中可以访问

	Application::f(a);
	a.g(Application());

	system("pause");
	return 0;
}