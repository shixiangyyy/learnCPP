#include <iostream>
#include <vector>
using namespace std;

//可以统一使用大括号进行变量初始化
//可以这么做的原因是，编译器看到大括号包括的列表状，
//变做出一个initializer_list<T>,
//它关联至一个array<T,n>
//调用函数时，该array内的元素可被编译器分解并逐一传递给函数
//但若函数参数是个initializer_list<T>
//调用者却不能给予数个T参数，然后以为它们会被自动转为一个initializer_list<T>
//即：默认大括号转为initializer_list<T>，但是原始的不要也是这种类型
int main()
{
	int values[]{ 1,2,3 };
	vector<int> v{ 2,3,3,45,53,45,2 };
	vector<string> cities{ "Beijing", "New york" };
	
	return 0;
}