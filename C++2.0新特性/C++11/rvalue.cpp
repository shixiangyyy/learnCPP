#include <iostream>
#include <complex>
using namespace std;

int foo() { return 5; }

//rvalue references解决非必要的拷贝
//当赋值右手边是一个“右值”，左手边对象可以偷右手边对象
//而不需要重新分配内存，浅拷贝
class Foo
{
public:
	Foo() = default;
	Foo(const Foo& foo) = default;
	Foo(Foo&& foo)noexcept {};
};

//判定传入的是左值还是右值
void process(int& i) { cout << "左值传入" << endl; }
void process(int&& i) { cout << "右值传入" << endl; }

void UnPerfectForward(int&& i)
{
	cout << "forward(int&& i)" << endl;
	process(i);
}

void PerfectForward(int&& i)
{
	//因为临时变量i，所以需要将其显式类型转换为int&&类型
	cout << "forward(int&& i)" << endl;
	process(static_cast<int&&>(i));
}

//Lvalue:变量
//Rvalue:临时对象就是个右值，右值不可以放左边

int main()
{
	string s1("hello");
	string s2("world");
	s1 + s2 = s2;//ok
	string() = "ok";//ok
	//说明string类实现了右值功能，重载+时应该有返回左值
	cout << "s1+s2:" << s1 + s2 << endl;
	cout << "s1: " << s1 << endl;
	cout << "s2: " << s2 << endl;
	//类似的有complex类，不赘述

	int x = foo();
	//    int *p=&foo(); //error!  Rvalue不可以取地址
	//    foo()=7;  // error
	// Rvalue references
	//    vector<Foo> vec;
	//    vec.insert(vec.begin(), Foo());  // Rvalue references and Move Semantics
	//  原先是下面这个
	//  iterator insert(const_iterator __position, const value_type& __x);
	// 调用下面这个Move Semantics
	//  iterator insert(const_iterator __position, value_type&& __x) 
	//  { return emplace(__position, std::move(__x)); }
	// Foo()这个临时对象为右值交给insert的move assignment然后再交给Foo的move ctor

	int a = 1;
	process(a); //L
	process(1); //R
	process(move(a)); //R，通过move函数将左值转为右值
	UnPerfectForward(2); //L
	UnPerfectForward(move(a)); //L,因为产生了临时变量
	PerfectForward(2); //R
	PerfectForward(move(a)); //R

	system("pause");
	return 0;
}