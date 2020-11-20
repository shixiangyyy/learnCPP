#include <iostream>
using namespace std;

//c++中显式类型转换和隐式类型转换，隐式：由编译器自动决定转换的类型
struct A
{
	A(int){}
	operator bool() const { return true; } //允许if(a),赋能布尔判断
};

struct B
{
	//explicit修饰构造函数，可以防止隐式转换和复制初始化
	explicit B(int) {}
	//explicit修饰转换函数，可以防止隐式转换，但是按语境转换除外
	//bool是个类
	//其他转化函数：operator A(){}
	explicit operator bool() const { return true; }
};

void doA(A a){}
void doB(B b){}

int main()
{
	//A series
	A a1(1); //OK,直接初始化
	A a2 = 1; //OK，复制初始化
	A a3{ 1 }; //OK，直接列表初始化
	A a4 = { 1 }; //OK，复制列表初始化
	A a5 = (A)1; //OK，允许static_cast的显示转换
	doA(1); //OK，允许从int到A的隐式转换
	if (a1); //OK，使用转换函数A::operator bool()的从A到bool的隐式转换
	bool a6(a1); //OK，使用转换函数A::operator bool()的从A到bool的隐式转换
	bool a7 = a1; //OK，使用转换函数A::operator bool()的从A到bool的隐式转换
	bool a8 = static_cast<bool>(a1); //OK,static_cast的直接初始化

	//B series
	B b1(1); //OK，直接初始化
	//B b2 = 1; //error，被explicit修饰构造函数的对象不可以进行复制初始化
	B b3{ 1 }; //OK，直接列表初始化
	//B b4 = { 1 }; //error，被explicit修饰构造函数的对象不可以进行复制列表初始化
	B b5 = (B)1; //OK，允许static_cast的显示转换
	//doB(1); //error，被explic修改构造函数的对象不可以从int到B的隐式转换
	if (b1); //OK,被explicit修饰转换函数B::operator bool()的对象可以从B到bool按语境转换
	bool b6(b1); //OK，被explicit修饰转换函数B::operator bool()的对象可以从B到bool按语境转换
	//bool b7 = b1; //error,被explicit修饰转换函数B::operator bool()的对象不可以隐式转换
	bool b8 = static_cast<bool>(b1); //可以用static_cast进行显示转换并直接初始化

	return 0;
}