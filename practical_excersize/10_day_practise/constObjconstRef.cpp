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
	//�����������Ǳ���ָ�����-fpermissive�����Ա��벢����
	//Error:const A as "this" argument.
	//��˿���ͨ��const_castȥ��
	const_cast<A*>(&a)->changeElements();

	system("pause");
	return 0;
}