#include <iostream>
using namespace std;

//��������̳ж���麯������̳������麯����vptr

class A
{
public:
	virtual void fun() {};
};

class B
{
public:
	virtual void fun1() {};
};

class C
{
public:
	virtual void fun2() {};
};

class D :virtual public A, virtual public B, virtual public C
{
public:
	virtual void fun3() {};
};

int main()
{
	cout << sizeof(A) << " " << sizeof(B) << " " << sizeof(C) << " " << sizeof(D) << endl;
	// 8 8 8 24
	system("pause");
	return 0;
}