#include <iostream>
using namespace std;


//终止函数，Args衰减到0个，只剩下s一个字符串参数
void printx(const char* s)
{
	while (*s)
	{
		if (*s == '%')
		{
			if (*(s + 1) == '%') ++s;
			else
			{
				throw("Error:Invalid format string provided! Please check.");
			}
		}
		cout << *s++;
	}
}

template <typename T, typename...Args>
void printx(const char* s, T value, Args...args)
{
	while (*s)
	{
		if (*s == '%')
		{
			if (*(s + 1) == '%') s++;
			else
			{
				cout << value;
				printx(++s + 1, args...); //最后在这里直接print了，没有进入重载的终止函数
				return;
			}
		}
		cout << *s++;
	}
	throw("Error:extra variables are provided than required, please check!");
}

int main()
{
	//正常输出
	printx("%d\t%d\n", 2, 3);
	printx("%d\t%s\n", 2, "石翔");
	printx("%s\n", "石翔");

	//抛出异常的书写
	try
	{
		printx("%%%%%s\n", "石翔");
		printx("%s\t%d\n", 2);
	}
	catch (const char* s)
	{
		cout << s << endl;
	}

	system("pause");
	return 0;
}
