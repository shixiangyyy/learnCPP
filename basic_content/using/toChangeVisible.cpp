#include <iostream>
using namespace std;

class Base
{
public:
	int base;
	virtual ~Base(){}
protected:
	int getBase() const
	{
		cout << base << endl;
		cout << "Base::getBase..." << endl;
		return 0;
	}
};

class Derived :private Base
{
public:
	//原本不使用using的话，base和getBase成员都是private类型
	//不能被der对象访问
	using Base::base;
	using Base::getBase;
	virtual ~Derived(){}
};

int main()
{
	Derived der;
	der.base = 10;
	der.getBase();
	system("pause");
	return 0;
}