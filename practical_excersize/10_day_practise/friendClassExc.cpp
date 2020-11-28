#include <iostream>
using namespace std;

class A
{
public:
	friend class B;
	friend void fri();
	A(int x, int y):x(x), y(y) {};
private:
	void retX() { cout << x << endl; };
	static void retY() { cout << "y" << endl; };
	int x, y;
};

class B
{
public:
	B(int x, int y) :a(x, y) {};
	A a;
	//通过友元类中定义对象去访问A的私有成员
	void getX() { cout << "B:: "; a.retX(); };
	void getY() { cout << "B:: "; a.retY(); };
	//retY();//友元类中不可以直接访问A的私有成员函数，即使该成员函数为static类型
};

void fri()
{
	A::retY();//在友元函数内通过冒号访问,但是仅限于静态成员，不可以访问非静态成员，比如下例
	//A::retX();
}

int main()
{
	B b(3, 5);
	b.getX();
	b.getY();
	//b.a.getX();//a对象不可以访问private成员，即使该对象属于友元类，也只能在友元类内访问
	//b.a.getY();

	system("pause");
	return 0;
}