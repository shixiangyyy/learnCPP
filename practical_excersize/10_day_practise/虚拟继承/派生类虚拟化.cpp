#include <iostream>
using namespace std;

class A
{
public:
	int a;
	A(int i) :a(i) { cout << "Virtual base A: " << a << endl; }
};

class B :virtual public A
{
public:
	B(int i) :A(i) { cout << "Virtual base B: " << endl; }
};

class C :virtual public A
{
	int c;
public:
	C(int i) :A(i), c(i) { cout << "Virtual base C: " << endl; }
};

class ABC :virtual public C, virtual public B
{
public:
	//虚基类由最终派生类初始化，此处必须对A进行初始化
	ABC(int i, int j, int k) :C(i), B(j), A(k) { cout << "Contructing ABC: " << endl; }
};

int main()
{
	/*Virtual base A : 3
	Virtual base C :
	Virtual base B :
	Contructing ABC :*/
	//可见虚基类A的构造只调用了一次
	ABC abc(1, 2, 3);
	//构造顺序A C B ABC
	system("pause");
	return 0;
}
