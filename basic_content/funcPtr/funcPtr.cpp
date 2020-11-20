#include <iostream>
using namespace std;

//定义了一种函数指针类型，参数为void，返回为void
typedef void(*pfun)(void);

void myFunc(void)
{
	cout << "myFunc" << endl;
}

void heFunc(int a)
{
	cout << a << endl;
}

int main()
{
	void (*funPtr) (int);
	funPtr = heFunc;
	funPtr(10);
	pfun funP = myFunc;
	funP();

	system("pause");
	return 0;
}