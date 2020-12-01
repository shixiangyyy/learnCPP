#include <iostream>
using namespace std;

class A
{
	int a;
public:
	A(int i) :a(i) { cout << "A constructed: " << a << endl; }
};

class B :public A
{
	int b;
public:
	B(int i) :A(i), b(i) { cout << "B constructed: " << b << endl; }
};

class C :public B
{
	int c;
public:
	C(int i) :B(i), c(i) { cout << "C constructed: " << c << endl; }
};

int main()
{
	C c(9);
	// A B C

	system("pause");
	return 0;
}