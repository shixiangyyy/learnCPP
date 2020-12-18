#include <iostream>
using namespace std;

//final关键字用在两个地方
//第一个用在类，用于说明该类绝育，不能被继承，否则报错
class Base final
{
public:
	Base() {};
	virtual void func() {};
};

class Dericed :public Base{}; //Error,cannot derive from 'final'
//base "base" in derived type Derived
//意思是Base类作了绝育，不允许继承了

//第二个用在虚函数，表示该虚函数不能再被override了，再override会报错
class Base1
{
public:
	Base1() {};
	virtual void func()final {};
};

class Derived1 :public Base1
{
	virtual void func() {};//Error:overriding final function virtual void Base1::func()
};

int main()
{

}

