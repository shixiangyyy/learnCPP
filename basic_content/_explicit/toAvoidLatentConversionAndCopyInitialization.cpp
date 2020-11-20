#include <iostream>
using namespace std;

//https://blog.csdn.net/qq_35524916/article/details/58178072
//c++中，具有一个参数(或者除了第一个参数以外，其他参数都有默认值的多参数)的构造函数承担两种角色：
//1、构造
//2、作为一个默认而且隐含的类型转换操作符
//比如：aaa=xxx，假如xxx恰好是aaa单参数构造函数的形参类型，则编译器将自动调用该构造器并创建一个aaa的对象
//所以：
//有时候如果不需要该功能而避免造成混淆，使用explicit关键字对构造函数进行修饰
//以避免其作为类型转换操作符被隐含使用
class Test1
{
private:
	int n;
public:
	Test1(int num):n(num){}
};

//使用explicit修饰单参数构造函数，以避免隐式转换与复制初始化
class Test2
{
private:
	int n;
public:
	explicit Test2(int num):n(num){}
};

int main()
{
	Test1 t1 = 12; //OK,Test1类没有用explicit修饰单参数构造函数，可以隐式转换
	Test2 t2(13);//OK,直接初始化
	//Test2 t3 = 14;//error,无法从14 int类型隐式转化，并初始化t3

	return 0;
}