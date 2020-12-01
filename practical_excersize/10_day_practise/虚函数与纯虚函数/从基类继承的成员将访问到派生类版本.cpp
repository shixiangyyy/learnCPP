#include <iostream>
using namespace std;

class Base
{
public:
	void callFunc() { vfunc(); }
	virtual void vfunc() { cout << "Here in Base." << endl; }
};

class Der :public Base
{
public:
	void vfunc() { cout << "Here in Der." << endl; }
};

int main()
{
	Der d;
	d.callFunc();//"Here in Der."

	system("pause");
	return 0;
}