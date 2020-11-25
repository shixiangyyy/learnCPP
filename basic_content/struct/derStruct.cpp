#include <iostream>
using namespace std;

struct Base
{
private:
	int v1;
	int v2;
public:
	int v3;
	virtual void print()
	{
		cout << "Hello world!" << endl;
	};
};

struct Derived :public Base
{
public:
	int v4;
	void print()
	{
		cout << "Hello world in derived!" << endl;
	}
};

int main()
{
	Base* bptr = new Derived();
	bptr->print(); //如果不加virtual修饰print函数，调用的是base的print函数
	//在print函数为虚函数的前提下，调用的是派生类的print函数
	system("pause");
	return 0;
}