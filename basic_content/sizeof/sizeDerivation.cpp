#include <iostream>
using namespace std;

//ע���ֽڶ���
//��ͨ���̳У��̳о��ǻ���+����������Ĵ�С
//�鵥�̳У�������̳л���vptr

class A
{
public:
	char a;
	int b;
};

//��ʱB����˳��
//char a
//int b
//short a
//long b
//�����ֽڶ������4+4+8+8=24//����ʵ�ʽ��������������
//������ݳ�Ա��������˳������ڴ棬�����Ȩ���޹أ�ֻ������˳��
class B :public A
{
public:
	short a;
	long b;
};

class C
{
	A a;
	char c;
};

class A1
{
	virtual void fun(){}
};

class C1 :public A1
{

};

int main()
{
	cout << "A: " << sizeof(A) << endl; //8
	cout << "B: " << sizeof(B) << endl; //24��16��Ӧ��ʱ16����Ϊ��64λϵͳ
	cout << "C: " << sizeof(C) << endl; //12
	cout << "A1: " << sizeof(A1) << endl; //8
	cout << "C1: " << sizeof(C1) << endl; //8
	//X86: 8 16 12 4 4
	//X64: 8 16 12 8 8 
	system("pause");
	return 0;
}