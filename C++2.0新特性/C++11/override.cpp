#include <iostream>

class Base
{
public:
	Base() {};
	virtual void func() {};
};

class Derived :public Base
{
	//virtual void func(int) override {}; //Error
	//virtual void Derived::func(int) marked override, but dose not override
};

//override�����麯���������virtual void func(int)ʵ���ϲ��Ǹ�����麯��
//��Ϊ����ǩ����һ���������һ���µ��麯��
//��������������override�Ļ�����ᱨ����ʾ�����˱���������ȷʵҪ��д��
//����д���ˣ�û����д�����Ǿͱ�����

//���Լ���override���ã����߱��������ú���ʱ��д�ģ�������ֲ�����д�ģ��뱨����ʾ
//����Ԥ����д������������Ŀ�����

int main()
{

}

