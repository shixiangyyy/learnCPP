#include <iostream>
using namespace std;

//�麯���Ƕ�̬�󶨵ģ�Ĭ�ϲ����Ǿ�̬�󶨵ġ�Ĭ�ϲ�����ʹ�ÿ�����ָ�����Ӧ�ñ�������ͣ������Ƕ��������
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
	//�麯���Ƕ�̬�󶨵ģ������麯���Ĳ�����Ĭ�ϲ����Ǿ�̬�󶨵�
	//������ָ�뱾������ͣ���������ָ����������
	Derived d1;
	Base* ptr = &d1;  //Derived:fun() x = 10
	ptr->fun();
	system("pause");
	return 0;
}