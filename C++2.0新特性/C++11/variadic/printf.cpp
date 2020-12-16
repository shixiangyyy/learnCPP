#include <iostream>
using namespace std;


//��ֹ������Args˥����0����ֻʣ��sһ���ַ�������
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
				printx(++s + 1, args...); //���������ֱ��print�ˣ�û�н������ص���ֹ����
				return;
			}
		}
		cout << *s++;
	}
	throw("Error:extra variables are provided than required, please check!");
}

int main()
{
	//�������
	printx("%d\t%d\n", 2, 3);
	printx("%d\t%s\n", 2, "ʯ��");
	printx("%s\n", "ʯ��");

	//�׳��쳣����д
	try
	{
		printx("%%%%%s\n", "ʯ��");
		printx("%s\t%d\n", 2);
	}
	catch (const char* s)
	{
		cout << s << endl;
	}

	system("pause");
	return 0;
}
