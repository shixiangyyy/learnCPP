#include <iostream>
using namespace std;

//c++����ʽ����ת������ʽ����ת������ʽ���ɱ������Զ�����ת��������
struct A
{
	A(int){}
	operator bool() const { return true; } //����if(a),���ܲ����ж�
};

struct B
{
	//explicit���ι��캯�������Է�ֹ��ʽת���͸��Ƴ�ʼ��
	explicit B(int) {}
	//explicit����ת�����������Է�ֹ��ʽת�������ǰ��ﾳת������
	//bool�Ǹ���
	//����ת��������operator A(){}
	explicit operator bool() const { return true; }
};

void doA(A a){}
void doB(B b){}

int main()
{
	//A series
	A a1(1); //OK,ֱ�ӳ�ʼ��
	A a2 = 1; //OK�����Ƴ�ʼ��
	A a3{ 1 }; //OK��ֱ���б��ʼ��
	A a4 = { 1 }; //OK�������б��ʼ��
	A a5 = (A)1; //OK������static_cast����ʾת��
	doA(1); //OK�������int��A����ʽת��
	if (a1); //OK��ʹ��ת������A::operator bool()�Ĵ�A��bool����ʽת��
	bool a6(a1); //OK��ʹ��ת������A::operator bool()�Ĵ�A��bool����ʽת��
	bool a7 = a1; //OK��ʹ��ת������A::operator bool()�Ĵ�A��bool����ʽת��
	bool a8 = static_cast<bool>(a1); //OK,static_cast��ֱ�ӳ�ʼ��

	//B series
	B b1(1); //OK��ֱ�ӳ�ʼ��
	//B b2 = 1; //error����explicit���ι��캯���Ķ��󲻿��Խ��и��Ƴ�ʼ��
	B b3{ 1 }; //OK��ֱ���б��ʼ��
	//B b4 = { 1 }; //error����explicit���ι��캯���Ķ��󲻿��Խ��и����б��ʼ��
	B b5 = (B)1; //OK������static_cast����ʾת��
	//doB(1); //error����explic�޸Ĺ��캯���Ķ��󲻿��Դ�int��B����ʽת��
	if (b1); //OK,��explicit����ת������B::operator bool()�Ķ�����Դ�B��bool���ﾳת��
	bool b6(b1); //OK����explicit����ת������B::operator bool()�Ķ�����Դ�B��bool���ﾳת��
	//bool b7 = b1; //error,��explicit����ת������B::operator bool()�Ķ��󲻿�����ʽת��
	bool b8 = static_cast<bool>(b1); //������static_cast������ʾת����ֱ�ӳ�ʼ��

	return 0;
}