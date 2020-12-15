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
	//�������
	printf("%d\t%d\n", 2, 3);
	printf("%d\t%s\n", 2, "ʯ��");
	printf("%s\n", "ʯ��");

	//�׳��쳣����д
	try
	{
		printf("%%%%%s\n", "ʯ��");
		printf("%s%d\n", 2);
	}
	catch (const char* s)
	{
		cout << s << endl;
	}

	system("pause");
	return 0;
}
