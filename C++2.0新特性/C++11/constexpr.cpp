//C++11中的constexpr指定的函数和返回值都必须要保证是字面值
//而且必须有且只有一行return代码
//C++14中只要保证返回值和参数是字面值就行

//const & constexpr
//const不能代表常量，它仅仅是对变量的一个修饰
//告诉编译器该变量只能被初始化，不能被直接修改
//而这个变量的值，可以在运行时也可以在编译时指定
//constexpr可以用来修饰变量、函数、构造函数
//一旦以上任何元素被constexpr修饰
//那么等于是告诉编译器
//“请大胆的将我看成编译时就能得出常量值的表达式去进行优化”

//总结：
//对于修饰object来说
//const便没有区分编译期常量和运行期常量
//constexpr限定在了编译期常量，目的在于优化
//constexpr修饰的函数，其返回值不一定是编译期常量
//const修饰的是类型，而constexpr修饰的是算出值得程序段，在编译期执行

//constexpr修饰得函数，简单而言，如果传入得参数可以在编译期计算出来，
//那么这个函数就会产生编译时期得值
//但是，如果传入得参数不能在编译期计算出来，那么cosntexpr修饰得函数就和普通函数一样
#include <iostream>
#include <array>
using namespace std;

const int foo(int i)
{
	return i + 10;
}

//加上constexpr前缀，表示提醒编译器在编译期尽力确定调用该函数的值
//相当于一种优化
constexpr int foo_constexpr(int i)
{
	return i + 10;
}

int main()
{
	int i = 10;
	//error, the value of i is not usable in a constant expression
	//std::array<int, i + 10> arr2; //如果i替换为const int则通过
	//error, call to non-constexpr function "const int foo(int)"
	//std::array<int, foo(10)> arr; //array的长度定义必须编译期确定
	//OK，相当于array<int, 20>,编译期间编译器就尽量对此进行优化
	std::array<int, foo_constexpr(10)> arr1;
	
	//OK
	foo_constexpr(i);
	//OK
	foo_constexpr(10);

	return 0;
}

