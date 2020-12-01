#include <iostream>
using namespace std;

class A
{
public:
	void fun() { cout << "A" << endl; }
};

class B:public A
{
public:
	virtual void fun() { cout << "B\n"; }
};

class C :public B
{
public:
	void fun() { cout << "C\n"; }
};

class D :public C
{
public:
	void fun() { cout << "D\n"; }
};

int main()
{
	A a, *pa;
	B b, *pb;
	C c, *pc;
	D d;

	pa = &b; pa->fun(); //A,��ʱ�������麯��
	pb = &c; pb->fun(); //C����B�п�ʼΪ�麯��������ҲΪ�麯��
	pb = &d; pb->fun(); //D����B�п�ʼΪ�麯��������ҲΪ�麯��
	//ע�����Ҳ���Խ���ַ��ֵ
	pc = &d; pc->fun(); //D����B�п�ʼΪ�麯��������ҲΪ�麯��

	system("pause");
	return 0;
}