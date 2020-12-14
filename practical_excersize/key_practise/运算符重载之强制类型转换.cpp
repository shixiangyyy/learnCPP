//设计类Circle, 设计该类的类型转换函数，当circle对象转换成int型时
//返回圆的半径；当转换成double类型时，返回圆的周长；
//当将Circle转化成float型时，就返回圆的面积
#include <iostream>
using namespace std;

class Circle
{
private:
	double x, y, r;
public:
	Circle(double x, double y, double r) :x(x), y(y), r(r) {};
	//运算符重载，强制类型转换
	operator int() { return int(r); }
	operator double() { return double(2 * r * 3.14); }
	operator float() { return float(3.14 * r * r); }
};

int main()
{
	Circle c(2.4, 3.4, 2.5);
	int r = c;
	double length = c;
	float area = c;
	double len = (double)c;

	cout << r << endl;
	cout << length << endl;
	cout << len << endl;
	cout << area << endl;

	system("pause");
	return 0;
}