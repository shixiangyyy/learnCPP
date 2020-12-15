#include <iostream>
using namespace std;

template <typename T, typename...Args>
void printf(const char* s, T value, Args...args)
{
	while (*s)
	{
		if (*s == '%')
		{
			if (*(s + 1) == '%') s++;
			else
			{
				cout << value;
				printf(++s + 1, args...);
				return;
			}
		}
		cout << *s++;
	}
	throw("Error:extra variables are provided than required, please check!");
}

void printf(const char* s)
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

int main()
{
	//正常输出
	printf("%d\t%d\n", 2, 3);
	printf("%d\t%s\n", 2, "石翔");
	printf("%s\n", "石翔");

	//抛出异常的书写
	try
	{
		printf("%%%%%s\n", "石翔");
		printf("%s%d\n", 2);
	}
	catch (const char* s)
	{
		cout << s << endl;
	}

	system("pause");
	return 0;
}
