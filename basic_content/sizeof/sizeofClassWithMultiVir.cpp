#include <iostream>
using namespace std;

//���ڰ����麯�����࣬�����ж��ٸ��麯������ֻ��һ����ָ�룬vptr�Ĵ�С��64λϵͳΪ8���ֽ�

class A
{
	virtual void fun() {};
	virtual void fun1() {};
	virtual void fun2() {};
	virtual void fun3() {};
};

int main()
{
	A a;
	cout << "Size of A class: " << sizeof(A) << endl;
	cout << "Size of A class object: " << sizeof(a) << endl;
	system("pause");
	return 0;
}