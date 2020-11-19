#include <iostream>
#include <cassert>
using namespace std;

//类中使用const以提升程序健壮性的C++11例子
//const成员函数只能调用常成员，并且不能对任何成员变量进行修改
//普通成员函数可以任意调用普通或者常成员函数或者变量
//类的常对象只能调用类的常成员函数或者常对象
//因为不能对常对象本身进行修改，如果调用非常成员函数或者变量，将具有修改自身属性的危险
//鉴于此，如果考虑类的健壮性，可以考虑为部分函数重载const类型成员函数，以方便类的常对象进行调用
//非const对象可以访问任意成员函数
class Apple
{
private:
	int people[100];
public:
	Apple(int i);
	static int ap;
	static const int appleNum;//c++11可以直接定义处赋值，否则需要使用初始化列表
	void take(int num) const;
	int add(int num);
	int add(int num) const;
	int getCount() const;
};

int Apple::ap = 666;
const int Apple::appleNum = 10;

Apple::Apple(int i) {}

void Apple::take(int num) const
{
	cout << "Take " << num << " apples from the bag!" << endl;
}

int Apple::add(int num)
{
	take(num);
	return 0;
}

//重载add函数作为常成员函数，供常对象调用
int Apple::add(int num) const
{
	take(num);
	return 0;
}

int Apple::getCount() const
{
	take(1);
	add(10);
	return appleNum;
}

int main()
{
	Apple a(2);
	cout << a.getCount() << endl;
	cout << a.ap << endl;
	a.add(10);
	const Apple b(10);
	b.add(100);
	return 0;
}