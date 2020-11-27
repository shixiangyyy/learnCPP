#include <iostream>
#include <stdio.h>
using namespace std;

//����ָ��
typedef void(*Fun)();

class Base
{
public:
	Base() {};
	virtual void fun1()
	{
		cout << "Base::fun1()" << endl;
	};
	virtual void fun2()
	{
		cout << "Base::fun2()" << endl;
	}
	virtual void fun3() {};
	virtual ~Base() {};
};

class Derived :public Base
{
public:
	Derived() {};
	void fun1()
	{
		cout << "Derived::fun1()" << endl;
	};
	void fun2()
	{
		cout << "Derived::fun2()" << endl;
	};
	virtual ~Derived() {};
};

//��ȡvptr��ַ��func��ַ��vptrָ��һ���ڴ棬��ŵ����麯���ĵ�ַ��Ҳ����vtable
Fun getAddr(void* obj, unsigned int offset)
{
	cout << "===================" << endl;
	//�ֶ�ȡ��obj����ǰ8���ֽڣ�ǰ�˸��ֽ���64ϵͳ�ھ���vptrָ��ĵ�ַ
	//Ҫȡ��ǰ8���ֽڣ���Ҫ��objָ��תΪ8�ֽ����ݵ�unsigned long long, unsigned long�ĸ��ֽ�
	void* vptr_addr = (void*)*(unsigned long long*)obj; //�������������
	cout << "vptr address: " << vptr_addr << endl;
	//��ͨ��vptrָ�����vtable����Ϊvptrָ��vtable�׵�ַ����˼���ƫ�������ǵ��������ĵ�ַ
	void* func_addr = (void*)*((unsigned long long*)vptr_addr + offset); //ע�����
	cout << "func address: " << func_addr << endl;
	return (Fun)(func_addr);
}

int main()
{
	Base bobj;
	Derived dobj;
	Base* bptr = new Derived();
	Base& brefb = bobj; //��������ָ��������
	Base& brefd = dobj; //��������ָ�����������

	cout << "�������ֱ�ӵ��ã�" << endl;
	bobj.fun1();
	cout << "�������õ��û���ʵ����" << endl;
	brefb.fun1();
	cout << "����ָ��ָ��������ʵ���������麯����" << endl;
	bptr->fun1();
	cout << "��������ָ����������󲢵����麯����" << endl;
	brefd.fun1();

	//�ֶ���ʽ����vptr��vtable
	Fun f1 = getAddr(bptr, 0); //f1�Ǻ���ָ��
	(*f1)();
	Fun f2 = getAddr(bptr, 1); 
	(*f2)();
	delete bptr;

	system("pause");
	return 0;
}