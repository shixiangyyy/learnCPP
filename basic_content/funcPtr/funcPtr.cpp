#include <iostream>
using namespace std;

//������һ�ֺ���ָ�����ͣ�����Ϊvoid������Ϊvoid
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