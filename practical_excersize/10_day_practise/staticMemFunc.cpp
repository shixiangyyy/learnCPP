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

//һ�γ�ʼ����ȫ����Ч
int Application::global = 0;//��ľ�̬��Ա����ֻ��ͨ�����ַ�ʽ����

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