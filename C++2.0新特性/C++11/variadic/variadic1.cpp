#include <iostream>
using namespace std;

void printx(){}

//模板特化的版本
template <typename T, typename...Args>
void printx(const T& firstArg, const Args&...args)
{
	cout << firstArg << endl;
	printx(args...);
}

//泛化版，泛化版可以接收任意参数
//当存在上面的特化版本的模板的时候，下面的泛化模板将永远不被调用
template <typename T, typename...Args>
void printx(const Args&...args)
{
	printx(args...);
}

int main()
{
	printx("hello world!", 2, 434, 5, 5, 5, 's', 'x');
	system("pause");
	return 0;
}