#include <iostream>
using namespace std;

class Apple
{
public:
	static void printMsg()
	{
		cout << "Welcome to Apple!" << endl;
	}
};

int main()
{
	//��ľ�̬��Ա�����ĵ��÷�ʽ
	Apple::printMsg();
	system("pause");
	return 0;
}