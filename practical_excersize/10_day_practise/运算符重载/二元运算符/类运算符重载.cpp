//以类成员的形式重载运算符，参数比实际参数少一个
//第一个参数是以this指针隐式传递的
#include <iostream>
using namespace std;

class complex
{
private:
	double r, i;
public:
	complex(double R = 0, double I = 0) :r(R), i(I) {};
	void display();
	complex operator + (complex b);
	complex operator - (complex b);
	complex operator * (complex b);
	complex operator / (complex b);
};

void complex::display()
{
	cout << r << "+" << i << "i" << endl;
}

complex complex::operator+(complex b)
{
	return complex(r + b.r, i + b.i);
}

complex complex::operator-(complex b)
{
	return complex(r - b.r, i - b.i);
}

complex complex::operator*(complex b)
{
	return complex(r * b.r - i * b.i, r * b.i + i * b.r);
}

complex complex::operator/(complex b)
{
	double mom = 1 / (b.r * b.r + b.i * b.i);
	return complex(mom * (r * b.r + i * b.i), mom * (i * b.r - r * b.i));
}

int main()
{
	complex c1(1, 2), c2(3, 4), c3, c4, c5, c6;
	complex a, b(5, 6);
	a = b + 2;//ok,函数中自动将2转为complex类型，期间调用complex构造函数，R赋值为2，I为默认的0
	//a = 2 + b;//error,不能转化
	c3 = c1 + c2; c3.display();
	c4 = c1 - c2; c4.display();
	c5 = c1 * c2; c5.display();
	c6 = c1 / c2; c6.display();

	system("pause");
	return 0;
}