//对于不要求左值且可以交换参数次序地运算符
//最好使用非成员的形式(包括友元和普通函数)的重载运算符函数实现
#include <iostream>

class complex
{
private:
	double r, i;
public:
	complex(double R = 0, double I = 0) :r(R), i(I) {};
	void display();
	//如果是通过友元方式实现运算符重载，那么对于二元运算符应该定义完全所需两个参数
	//相对地，如果是类运算符方式，那么其相当于覆盖了运算原来地二元方式，变为类似一元类操作符
	friend complex operator + (complex a, complex b);
	friend complex operator - (complex a, complex b);
	friend complex operator * (complex a, complex b);
	friend complex operator / (complex a, complex b);
	friend complex operator + (complex a, double b);
	friend complex operator + (double b, complex a);
};

void complex::display()
{
	std::cout << r << "+" << i <<"i" << std::endl;
}

complex operator + (complex a, complex b)
{
	return complex(a.r + b.r, a.i + b.i);
}

complex operator-(complex a, complex b)
{
	return complex(a.r - b.r, a.i - b.i);
}

complex operator*(complex a, complex b)
{
	return complex(a.r * b.r - a.i * b.i, a.r * b.i + a.i * b.r);
}

complex operator/(complex a, complex b)
{
	double mom = 1 / (b.r * b.r + b.i * b.i);
	return complex(mom * (a.r * b.r + a.i * b.i), mom * (a.i * b.r - a.r * b.i));
}

complex operator + (complex a, double b)
{
	return complex(a.r + b, a.i);
}

complex operator + (double b, complex a)
{
	return complex(a.r + b, a.i);
}

int main()
{
	complex c1(1, 2), c2(3, 4), c3, c4, c5, c6;
	complex a, b(5, 6);
	a = b + 2;//ok,函数中自动将2转为complex类型，期间调用complex构造函数，R赋值为2，I为默认的0
	a = 2 + b;//OK,因为实现了对+的可交换重载
	c3 = c1 + c2; c3.display();
	c4 = c1 - c2; c4.display();
	c5 = c1 * c2; c5.display();
	c6 = c1 / c2; c6.display();

	system("pause");
	return 0;
}