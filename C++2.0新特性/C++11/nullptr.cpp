#include <iostream>
using namespace std;

void f(int i)
{
	cout << "void f(int) called." << endl;
}

void f(void* p)
{
	cout << "void f(void*) called." << endl;
}

int main()
{
	f(0);

//#ifndef  __cplusplus
//#define NULL ((void*)0)
//#else
//#define NULL 0
//#endif // ! __cplusplus

	//C�����н�NULL����Ϊ��ָ�룬��C++�н�NULL����Ϊ0
	//������ΪC++��ǿ���͵أ�void*�ǲ�����ʽת��Ϊ����ָ�����͵�

	if (NULL == 0) cout << "NULL==0" << endl;
	//f(NULL); //ambiguous����֪��������һ��
	////��Ϊc++�н�NULL����Ϊ0��������C�����еĿ�ָ�룬��˵�������
	f(nullptr);
	nullptr_t n1;
	f(n1);

	system("pause");
	return 0;
}