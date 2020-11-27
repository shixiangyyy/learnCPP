#include <iostream>
using namespace std;

class Point
{
public:
	Point(Point& p);
	Point(int xx = 0, int yy = 0) :x(xx), y(yy) { countP++; };
	int getX() { return x; }
	int getY() { return y; }
	void getC() { cout << "Object ID = " << countP << endl; }
private:
	int x, y;
	static int countP;
};

Point::Point(Point& p)
{
	x = p.x;
	y = p.y;
	countP++;
}

//static成员必须在类外显示声明
int Point::countP = 0;

int main()
{
	Point A(1, 2);
	cout << "Point A, " << A.getX() << ", " << A.getY() << endl;
	Point B(A);
	cout << "Point B, " << B.getX() << ", " << B.getY() << endl;
	B.getC();

	system("pause");
	return 0;
}