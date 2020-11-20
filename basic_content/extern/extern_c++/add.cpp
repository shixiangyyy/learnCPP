#include <iostream>
//使用extern "C",告诉链接器，应该寻找类似_add这类的C语言函数符号，而不是CPP风格的add_int_int
extern "C"
{
	#include "add.h"
}
using namespace std;

int main()
{
	cout << add(2, 3) << endl;
	system("pause");
	return 0;
}