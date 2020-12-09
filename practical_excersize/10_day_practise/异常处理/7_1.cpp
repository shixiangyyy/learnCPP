#include <iostream>
using namespace std;

class A
{
	int a;
public:
	A(int i = 0) :a(i) {};
	~A() { cout << "A deconstructed.\n"; }
};

class B
{
	A AobjArr[3];
	double* pd[10];
public:
	B(int i)
	{
		cout << "B is constructing.\n";
		for (int k = 0; k < 10; k++)
		{
			pd[k] = new double[200000000];
			if (pd[k] == 0) throw k;
			else cout << "Allocated 200000000 doubles in pd[" << k << "]\n";
		}
	}

};

int main()
{
	try
	{
		B b(2);
	}
	catch (int e)
	{
		cout << "Catch an exception when allocating pb[" << e << "]\n";
	}

	system("pause");
}