#include <iostream>
using namespace std;

void print(const char* s)
{
	while (*s)
	{
		if (*s == '%' && *(++s) == '%')
			throw std::runtime_error("Invalid format string:missing arguments");
		std::cout << *s++;
	}
}

template <typename T, typename...Args>
void print(const char* s, T value, const Args&...args)
{
	while (*s)
	{
		if (*s == '%' && *(++s) != '%')
		{
			std::cout << value;
			print(++s, args...);//call even *s == 0 to detect extra arguments
			return;
		}
		cout << *s++;
	}
	throw std::runtime_error("Extra arguments provided to print..");
}

int main()
{
	int* pi = new int;
	print("%d %s %p %f\n", 15, "Acc", pi, 3.14);
	system("pause");
	return 0;
}