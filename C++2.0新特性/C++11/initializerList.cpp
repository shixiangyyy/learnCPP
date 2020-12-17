#include <iostream>
#include <algorithm>
using namespace std;

//在调用initializer_list私有构造之前
//编译器准备好array头与len，传递该构造
//指针只是指向array，只是浅拷贝
//如今所有容器都接受任意数量的值，insert或者assign

//The initializer_list object refers to the elements
//of this array without containing them:copying a 
//initializer_list object produces another object referring
//to the same underlying elements, but not to new copies of them

//注意上一段话说的refer to,指的指针形式的指向，而不是深拷贝数据复制

void print(int a, int b)
{
	cout << "print(int, int), a = " << a << ",b = " << b << endl;
}

template <typename T>
void print(initializer_list<T> vals)
{
	for (const auto p:vals) cout << p << "\n";
}

int main()
{
	int i; //没有初始化,但是输出为0，可能跟编译器有关
	int j{}; //c初始化为0
	int* p; //p数值未定义
	int* q{}; //默认定义为nullptr

	cout << i << endl; //0
	cout << j << endl; //0
	cout << p << endl; //0x8
	cout << q << endl; //0

	cout << max({ 1,2,3,4 }) << endl;
	print({ 's', 'i','x' });

	//当同时存在具体类型的函数以及参数为initializer_list类型的同名函数时
	//包含initializer_list的版本优先
	print(1, 2);
	print({ 1,2 });

	system("pause");
	return 0;
}