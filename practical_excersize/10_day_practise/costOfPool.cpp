#include <iostream>
using namespace std;

double PI = 3.1415926;
float  PERCOST = 4.2;

class CIRCLE
{
private:
	float radius;
public:
	CIRCLE(float r) :radius(r) {};
	double Circleference();
	double Area();
};

double CIRCLE::Circleference()
{
	return 2 * radius * PI;
}

double CIRCLE::Area()
{
	return PI * radius * radius;
}

int main()
{
	float radiusOfPool;
	cout << "Please enter the radius of pool: " << endl;
	cin >> radiusOfPool;
	float radiusOfFenc;
	cout << "Please enter the radius of fence: " << endl;
	cin >> radiusOfFenc;

	CIRCLE pool(radiusOfPool);
	CIRCLE fenc(radiusOfFenc);
	cout << "The area of the pool is: " << pool.Area() << endl;
	double lenOfFen = fenc.Circleference() + pool.Circleference();
	cout << "The length of the fence is: " << lenOfFen << endl;

	cout << "The cose of the fence is: гд " << lenOfFen * PERCOST << endl;
	
	system("pause");
	return 0;
}