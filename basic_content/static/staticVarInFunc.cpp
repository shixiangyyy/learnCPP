#include <iostream>
using namespace std;

//当变量声明为static时，空间将在程序的声明周期内分配
//即使多次调用该函数，静态变量的空间也只分配一次
//适用于需要维持函数状态的场合
void demo()
{
	static int i = 0;
	cout << i++ << endl;
}

int main()
{
	for (int i = 0; i <= 5; i++)
		demo();
	system("pause");
	return 0;
}