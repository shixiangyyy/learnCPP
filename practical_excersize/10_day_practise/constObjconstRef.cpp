#include <iostream>
using namespace std;

void display(const double& r)
{
	cout << r << endl;
}

class A
{
public:
	A(int i, int j) :x(i), y(j) {};
	void changeElements() 
	{ 
		x++; 
		y++; 
		cout << x << " " << y << endl;
	};
private:
	int x, y;
};

int main()
{
	double d(9.5);
	display(d);
	A const a(3, 4);
	//本来报错，但是编译指令加上-fpermissive，可以编译并运行
	//Error:const A as "this" argument.
	//因此考虑通过const_cast去常
	const_cast<A*>(&a)->changeElements();

	system("pause");
	return 0;
}