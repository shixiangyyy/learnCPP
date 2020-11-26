#include <iostream>
using namespace std;

class Base
{
public:
	Base()
	{
		cout << "Base constructed!" << endl;
	}
	virtual ~Base()
	{
		cout << "Base destructed!" << endl;
	}
};

class Derived :public Base
{
public:
	Derived()
	{
		cout << "Derived constructed!" << endl;
	}
	virtual ~Derived()
	{
		cout << "Derived destructed!" << endl;
	}
};

int main()
{
	Derived* dptr = new Derived();
	Base* bptr = dptr;
	//析构函数不改写为虚函数时，删除bptr将只调用Base的析构函数
	//析构函数改写为虚函数时，删除bptr将先后调用Derived和Base的析构函数
	delete bptr;

	system("pause");
	return 0;
}