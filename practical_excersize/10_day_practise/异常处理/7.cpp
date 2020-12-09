#include <iostream>
using namespace std;

void Errhandler(int n)
{
	try
	{
		if (n == 1)throw n;
		cout << "Allis well!\n";
	}
	catch (int n)
	{
		cout << "Catch an int exception in function..." << n << endl;
		throw n; //继续向外围抛出，被主函数捕获
	}
}

int main()
{
	try
	{
		Errhandler(1);
	}
	catch (int x) { cout << "Catch an int exception is main..." << x << endl; }
	cout << "END!\n";

	system("pause");
}