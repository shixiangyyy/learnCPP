#include <iostream>
using namespace std;

void fun(int x)
{
	try
	{
		if (x == 0) throw "“Ï≥£";
	}
	catch (...)
	{
		cout << "In fun" << endl;
		throw 1;
	}
}

int main()
{
	try
	{
		fun(0);
	}
	catch (int n)
	{
		cout << "In main" << endl;
	}

	system("pause");
	return 0;
}