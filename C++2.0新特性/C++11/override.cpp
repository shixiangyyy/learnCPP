#include <iostream>

class Base
{
public:
	Base() {};
	virtual void func() {};
};

class Derived :public Base
{
	//virtual void func(int) override {}; //Error
	//virtual void Derived::func(int) marked override, but dose not override
};

//override用于虚函数，上面的virtual void func(int)实际上不是父类的虚函数
//因为函数签名不一样，因此是一个新的虚函数
//那如果像下面加上override的话，则会报错，表示告诉了编译器，我确实要重写，
//但是写错了，没有重写，于是就报错了

//所以加上override作用：告诉编译器，该函数时重写的，如果发现不是重写的，请报错提示
//用以预警重写函数发生错误的可能性

int main()
{

}

