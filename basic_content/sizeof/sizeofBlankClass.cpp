#include <iostream>
using namespace std;

//空类的大小为一个字节

class A {};

int main()
{
	cout << sizeof(A) << endl;
	system("pause");
	return 0;
}