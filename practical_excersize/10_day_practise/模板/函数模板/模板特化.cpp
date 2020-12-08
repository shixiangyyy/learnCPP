#include <iostream>
#include <cstring>
using namespace std;

template <typename T>
bool MAX(T a, T b)
{
	return a > b ? 1 : 0;
}

template <> bool MAX<char*>(char* a, char* b)
{
	return strcmp(a, b) > 0 ? 1 : 0;
}

int main()
{
	cout << "10 is larger than 5? " << MAX(10, 5) << endl;
	cout << "\"ABCDE\" is larger than \"abcde\"? " << MAX("ABCDE", "abcde") << endl;

	system("pause");
	return 0;
}