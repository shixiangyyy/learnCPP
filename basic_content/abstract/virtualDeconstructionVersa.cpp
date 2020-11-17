#include <iostream>
using namespace std;

//一般来说，一个类中如果定义了虚函数，那么其析构函数也应该定义为虚函数
class base
{
public:
	base()
	{
		cout << "Base" << endl;
	}
	virtual ~base()
	{
		cout << "~Base" << endl;
	}
};

class der:public base
{
public:
	der()
	{
		cout << "Derived" << endl;
	}
	~der()
	{
		cout << "~der" << endl;
	}
};

class der1 :public der
{
public:
	der1()
	{
		cout << "der1" << endl;
	}
	~der1()
	{
		cout << "~der1" << endl;
	}
};

int main()
{
	base* b = new der;
	der* Der1 = new der1;
	delete b;
	delete Der1;

	return 0;
}