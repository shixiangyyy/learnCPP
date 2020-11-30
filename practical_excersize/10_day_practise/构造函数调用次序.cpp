#include <iostream>
using namespace std;

class A
{
	int x;
public:
	A(int i = 0) :x(i) { cout << "A constructed: " << x << endl; }
};

class B
{
	int y;
public:
	B(int i = 0) :y(i) { cout << "B constructed: " << y << endl; }
};

class C
{
	int z;
public:
	C(int i = 0) :z(i) { cout << "C constructed: "<< z << endl; }
};

class D :public B, public C
{
public:
	A a1, a2;
	B* b1 = new B(10);
	C c1, c2;
	D(int i = 0, int b = 7, int c = 8) :m(i), a1(2), c2(3), c1(4), a2(5), C(c), B(b) 
	{ 
		cout << "D constructed：" << m << endl; 
	}
private:
	int m;
};

int main()
{
	D d(0, 7, 8);
	//7 8 2 5 2 5 4 3 0
	//基类(声明的继承顺序)->成员对象声明顺序->自己的成员
	system("pause");
	return 0;
}