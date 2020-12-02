#include <iostream>
using namespace std;

class X
{
	int x;
public:
	X(int i) :x(i) {};
	void display() { cout << x << endl; };
	X& operator=(const X& x)
	{
		cout << "ack\n";
		this->x = x.x;
		return *this;
	};
};

int main()
{
	X obj1(1), obj2(2), obj3(3);
	obj1.display();
	obj1 = obj2 = obj3;
	obj1.display();
	obj2.display();
	obj3.display();

	system("pause");
	return 0;
}