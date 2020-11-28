#include <iostream>
#include <cmath>
using namespace std;

class Point
{
public:
	Point(int x, int y):X(x), Y(y){};
	int getX(){ return X; };
	int getY(){ return Y; };
	friend double Distance(Point& A, Point& B);
private:
	int X,Y;
};

double Distance(Point& A, Point& B)
{
	return sqrt(pow(A.X - B.X, 2) + pow(A.Y - B.Y, 2));
}

int main()
{
	Point p1(3, 4), p2(4, 5);
	cout << "两点之间的距离：" << Distance(p1, p2) << endl;
	
	system("pause");
	return 0;
}
