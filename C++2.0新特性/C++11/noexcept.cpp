//noexcept()中可以加条件
//异常可以传递
//异常的回传机制：调用foo如果抛出异常，foo会接着向上抛出
//如果最上层没有处理该异常，那么会调用std::terminate()
//terminate()函数内部调用abort(),最终终止程序

//在使用vector、deque等容器的时候，C++2.0中存在的“move assignment”
//和“move copy”机制，如果移动构造和移动赋值没有加上noexcept
//则当发生注入vector增长重新分配空间时，将不会调用move ctor或者move
//assignment，则利用不到C++2.0移动构造和移动赋值的高效性
//因此往往在自定义数据类型后面加上noexcept，以告诉vector等容器模板
//该移动赋值或者移动构造不会抛出异常，请放心使用

#include <iostream>
#include <vector>
using namespace std;

void foo()noexcept(true){}

int main()
{
	foo();
	vector<int> vec;
	return 0;
}