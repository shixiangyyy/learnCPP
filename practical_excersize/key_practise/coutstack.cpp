#include <iostream>
using namespace std;

//22335
//可见g++使用队列处理cout
//但是网上有些编译器使用的stack处理cout
int main()
{
	int i = 1;
	cout << ++i << i++ << i << i++ << ++i << endl;
	system("pause");
}