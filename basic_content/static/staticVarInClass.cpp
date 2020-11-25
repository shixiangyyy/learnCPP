#include <iostream>
using namespace std;

//类中的静态变量由对象共享，对于不同的对象，不能有相同静态变量的多个副本
//也正是因为这个原因，静态变量不能用构造函数初始化
class Apple
{
public:
	static int i;
	Apple()
	{
		//Do nothing
	};
};

int Apple::i = 3;//初始化方式

int main()
{
	Apple obj1;
	Apple obj2;
	obj1.i = 1;
	obj2.i = 2;
	cout << obj1.i << endl;

	system("pause");
	return 0;
}