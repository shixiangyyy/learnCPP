#include <iostream>
using namespace std;
// c++2.0之前explicit只禁止"存在单一实参"转换
// c++2.0之后explicit可以进制"多个实参"转换
class Complex
{
private:
	int re, vt;
public:
	Complex(int r, int v = 0) :re(r), vt(v) {};
	//需要为const,否则cannot bind non-const lvalue reference of type Complex 
	//to an rvalue of type Complex
	Complex operator+(const Complex& cp)
	{
		return Complex(re + cp.re, vt + cp.vt);
	}
};

class Complex1
{
private:
	int re, vt;
public:
	explicit Complex1(int r, int v = 0) :re(r), vt(v) {};
	Complex1 operator+(const Complex1& cp)
	{
		return Complex1(re + cp.re, vt + cp.vt);
	}
};

class P
{
public:
	//1
	P(int a, int b) { cout << "P(int a, int b) \n"; }
	//2
	P(initializer_list<int>) { cout << "P(initializer_list<int>) \n"; }
	//3
	explicit P(int a, int b, int c)
	{
		cout << "explict P(int a, int b, int c) \n";
	}
};

void fp(const P&){}

int main()
{
	Complex cp1{ 12,5 };
	Complex cp2 = cp1 + 5;

	Complex1 cp3{ 12,5 };
	//Complex1 cp4 = cp3 + 5; //Error,无法隐式类型转换

	//全部OK，可能是编译器原因，有些本部被3允许的隐式类型转换被调用2
	P p1(77, 5);
	P p2{ 77,5 };
	P p3{ 77,5,42 };
	P p4 = { 77,5 };
	P p5 = { 77,44,2 }; //调用ctor2
	P p6(77, 5, 2234);

	fp({ 47,11 });
	fp({ 534,3252,2 });
	fp(P{ 57,23 });
	fp(P{ 423,24,2 });

	P p11{ 3412,324,2,22 };
	P p12 = { 234,2,2,4 };
	P p13{ 10 };

	return 0;
}