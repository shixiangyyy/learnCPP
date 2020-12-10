#include <iostream>
using namespace std;

//cin.put(char c)
//cin.write(const char* c, int n)
//均用于输出
//使用cin.write可以实现输出一个字符串常量的前若干位
int main()
{
	char c;
	char a[50] = "this is a string...";
	cout << "Use get() to input char: ";
	while ((c = cin.get()) != '\n')
	{
		cout.put(c);
		cout.put('\n');
		cout.put('t').put('h').put('i').put('s').put('\n');
		cout.write(a, 12).put('\n');
		cout << "look" << "\there!" << endl;
	}

	system("pause");
}