#include <iostream>

//::冒号范围解析运算符
//:: 全局作用域符，表示作用域为全局命名空间
//class::name：表示类作用域范围
//namespace::name：表示命名空间内部作用域范围

int count = 1;

class A
{
public:
	static int count;
};

int A::count = 2;

int main()
{
	::count = 0;
	A::count = 5;
	std::cout << "Global count: " << ::count << std::endl;
	std::cout << A::count << std::endl;

	system("pause");
	return 0;
}