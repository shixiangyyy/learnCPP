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
	//类的静态成员函数的调用方式
	Apple::printMsg();
	system("pause");
	return 0;
}