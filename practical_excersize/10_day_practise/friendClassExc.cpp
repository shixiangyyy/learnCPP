#include <iostream>
using namespace std;

class A
{
public:
	friend class B;
	friend void fri();
	A(int x, int y):x(x), y(y) {};
private:
	void retX() { cout << x << endl; };
	static void retY() { cout << "y" << endl; };
	int x, y;
};

class B
{
public:
	B(int x, int y) :a(x, y) {};
	A a;
	//ͨ����Ԫ���ж������ȥ����A��˽�г�Ա
	void getX() { cout << "B:: "; a.retX(); };
	void getY() { cout << "B:: "; a.retY(); };
	//retY();//��Ԫ���в�����ֱ�ӷ���A��˽�г�Ա��������ʹ�ó�Ա����Ϊstatic����
};

void fri()
{
	A::retY();//����Ԫ������ͨ��ð�ŷ���,���ǽ����ھ�̬��Ա�������Է��ʷǾ�̬��Ա����������
	//A::retX();
}

int main()
{
	B b(3, 5);
	b.getX();
	b.getY();
	//b.a.getX();//a���󲻿��Է���private��Ա����ʹ�ö���������Ԫ�࣬Ҳֻ������Ԫ���ڷ���
	//b.a.getY();

	system("pause");
	return 0;
}