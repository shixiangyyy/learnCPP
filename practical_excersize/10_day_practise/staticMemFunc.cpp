#include <iostream>
using namespace std;

class Application
{
private:
	static int global;
public:
	static void f();
	static void g();
};

//一次初始化，全局生效
int Application::global = 0;//类的静态成员函数只能通过这种方式定义

void Application::f()
{
	cout << "Application::f()" << endl;
	global = 5;
}

void Application::g()
{
	cout << "Application::g()" << endl;
	cout << "global = " << global << endl;
}

int main()
{
	Application::f();
	Application::g();

	system("pause");
	return 0;
}