#include <iostream>
using namespace std;

class A
{
public:
	virtual ~A() { cout << "A::~A().\n"; }
};

class B :public A
{
	char* buf;
public:
	B(int i) { buf = new char[i]; }
	~B()
	{
		delete[] buf;
		cout << "B::~B().\n";
	}
};

int main()
{
	A* a = new B(10);
	delete a; //���������������е���(��virtual)
	//����virtual�Ļ�ֻ����A

	system("pause");
	return 0;
}