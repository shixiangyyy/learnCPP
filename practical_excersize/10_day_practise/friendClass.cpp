#include <iostream>
using namespace std;

class A
{
public:
	void display() { cout << x << endl; };
	friend class B;
private:
	int x;
};

class B
{
public:
	void Set(int i);
	void display();
private:
	A a;
};

void B::display()
{
	a.display();
}

void B::Set(int i)
{
	a.x = i; //B�п��Ե���A��˽�г�Ա
}

int main()
{
	B b;
	b.Set(10);
	b.display();

	system("pause");
	return 0;
}
