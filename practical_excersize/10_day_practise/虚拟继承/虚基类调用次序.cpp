#include <iostream>
using namespace std;

class A
{
	int a;
public:
	A() { cout << "A constructed." << endl; }
};

class B
{
	int b;
public:
	B() { cout << "B constructed." << endl; }
};

class B1 :virtual public A, virtual public B 
{
public:
	B1(int i) { cout << "B1 constructed." << endl; }
};

class B2 :public A, virtual public B
{
public:
	B2(int i) { cout << "B2 constructed." << endl; }
};

class D :public B1, public B2
{
public:
	D(int m, int n):B2(m), B1(n) { cout << "D constructed." << endl; }
};

int main()
{
	//A B B1 A B2 D
	D d(1,2);

	system("pause");
	return 0;
}