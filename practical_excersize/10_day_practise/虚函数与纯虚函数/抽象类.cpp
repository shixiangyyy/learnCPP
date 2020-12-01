#include <iostream>
using namespace std;

class Figure
{
protected:
	int x, y;
public:
	void set(int x, int y) { this->x = x; this->y = y; }
	virtual void area() = 0;
};

class Triangle :public Figure
{
public:
	void area() { cout << x*y / 2 << endl; }
};

class Rectangle :public Figure
{
public:
	void area() { cout << x*y << endl; }
};

int main()
{
	Figure *fptr = NULL;

	Triangle tri;
	tri.set(10, 10);
	fptr = &tri;
	fptr->area();//50

	Rectangle rec;
	rec.set(10, 10);
	fptr = &rec;
	fptr->area();//100

	//定义抽象类的引用
	Figure &fref = tri;
	fref.set(20, 20);
	fref.area();//200

	system("pause");
	return 0;
}